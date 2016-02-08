`timescale 1ns / 1ps

/* 
 * Author: Daniel Khoury
 * SRAM and counter demo using Nexys 4 board.
 * 
 * Parts: 
 * 1) Two SRAM ICs (part no. IDT71V016SA).
 * 2) One 12-bit counter (part no. MC14040B).
 * 
 * SRAM specifications:  
 * VDD: 3.3V (recommended)
 * Maximium read/write speed: 100 MHz
 * Number of address pins: 16
 * Number of data pins: 16 
 * State pins (all are active-low): S = {CS, OE, WE, BLE, BHE}
 * 	Word read: S = {L, L, H, L, L}
 *    Word write: S = {L, X, L, L, L}
 *    Thus, CS, OE, BLE, and BHE are all fixed to low. WE is used to switch between reading and writing.
 * 
 * Counter specifications: 
 * Number of counter pins: 12
 * Maximum clock speed: ~1 MHz
 * 	NOTE: A faster counter will be used in the actual project!
 * VDD: 3.3V
 * 
 * Demo: 
 * 1) We load the SRAM block with 16 8-bit pseudorandom values (split amongst the chips), using the counter to address the SRAM blocks.
 * 2) We reset the counter and attempt to load back the pseudorandom values stored in SRAM.
 * 3) The FPGA reports (via LEDs, because why not?) whether the values came back as expected.
 */
module TOP(CLK, RST, INIT, SEED, COUNTER_CLK, COUNTER_RST, WE_BAR, CHIP1_DATA, CHIP2_DATA, LED_OUT);
	input CLK;
	input RST;
	input INIT;
	input [7:0] SEED;
	
	// Counter
	output COUNTER_CLK;
	output reg COUNTER_RST;
	
	// TODO: Better logic :)
	assign COUNTER_CLK = pulse; 
	
	// SRAM
	output reg WE_BAR;
	inout reg [3:0] CHIP1_DATA;
	inout reg [3:0] CHIP2_DATA;
	
	// LEDs
	output reg [15:0] LED_OUT;
	
	reg [3:0] CHIP1_ACTUAL_DATA [3:0];
	reg [3:0] CHIP2_ACTUAL_DATA [3:0];

	// FSM 
	parameter IDLE = 3'd0;
	parameter GENERATE = 3'd1;
	parameter WRITE = 3'd2;
	parameter SWITCH = 3'd3;
	parameter READ = 3'd4;
	parameter VERIFY = 3'd5;
	
	reg [2:0] PS;
	reg [2:0] NS;
	
	// GENERATE, WRITE, and READ states (internal progression)
	reg [4:0] state_counter;
	
	// Module instantiations
	reg pulse;
	PULSE_GEN pg0(.CLK(CLK), .RST(RST), .PULSE(pulse));
	
	reg get_next;
	reg [7:0] random_val;
	reg [3:0] random_val_arr [7:0];
	RANDOM_GEN rg0(.CLK(CLK), .RST(RST), .GET_NEXT(get_next), .SEED(SEED), .VAL(random_val));
	
	// Present-state block
	always@(posedge CLK) begin
		if(RST) begin
			PS <= IDLE;
		end
		else if(pulse) begin
			PS <= NS;
		end
		else begin
			PS <= PS;
		end
	end
	
	// Sequential logic
	always@(posedge CLK) begin
		if (RST) begin
			state_counter <= 5'd0;
		end
		else if (pulse) begin
			state_counter <= 5'd0;
			case(PS)
				GENERATE: begin
					if (state_counter == 5'd16) begin
						state_counter <= 5'd0;
					end
					else begin
						state_counter <= state_counter + 5'd1;
					end
				end
				WRITE: begin
					if (state_counter == 5'd16) begin
						state_counter <= 5'd0;
					end
					else begin
						state_counter <= state_counter + 5'd1;
					end
				end
				READ: begin
					if (state_counter == 5'd16) begin
						state_counter <= 5'd0;
					end
					else begin
						state_counter <= state_counter + 5'd1;
					end
				end
			endcase
		end
	end
	
	// Next-state block
	always@(*) begin
		NS = IDLE;
		case(PS)
			// Remain idle until initialized
			IDLE: begin
				if (INIT) begin
					NS = GENERATE;
				end
				else begin
					NS = IDLE;
				end
			end
			
			// Generate 16 random values
			GENERATE: begin
				if (state_counter == 5'd16) begin
					NS = WRITE;
				end
				else begin
					NS = GENERATE;
				end
			end
			
			// Write the 16 values
			WRITE: begin
				if (state_counter == 5'd16) begin
					NS = SWITCH;
				end
				else begin
					NS = WRITE;
				end
			end
			
			// Switch from write to read (reset the counter)
			SWITCH: begin
				NS = READ;
			end
			
			// Read the 16 values
			READ: begin
				if (state_counter == 5'd16) begin
					NS = SWITCH;
				end
				else begin
					NS = WRITE;
				end
			end
			
			// Verification (stay here until reset)
			VERIFY: begin
				NS = VERIFY;
			end
		endcase
	end
	
	// General logic
	always@(*) begin
		get_next = 1'b0;
		COUNTER_RST = 1'b0;
		WE_BAR = 1'b0; // By default, set to write to avoid multiple-driver issues
		LED_OUT = 16'd0;
		CHIP1_DATA = 4'bz;
		CHIP2_DATA = 4'bz;
		case(PS)
			IDLE: begin
				// Nothing to do
			end
			
			GENERATE: begin
				get_next = 1'b1;
				random_val_arr[state_counter] = random_val;
			end
			
			WRITE: begin
				CHIP1_DATA = random_val_arr[state_counter][7:4];
				CHIP2_DATA = random_val_arr[state_counter][3:0];
			end
			
			SWITCH: begin
				COUNTER_RST = 1'b1;
			end
			
			READ: begin
				WE_BAR = 1'b1;
				CHIP1_ACTUAL_DATA[state_counter] = CHIP1_DATA;
				CHIP2_ACTUAL_DATA[state_counter] = CHIP2_DATA;
			end
			
			VERIFY: begin
				LED_OUT[0] = ({CHIP1_ACTUAL_DATA[0], CHIP2_ACTUAL_DATA[0]} == random_val_arr[0]);
				LED_OUT[1] = ({CHIP1_ACTUAL_DATA[1], CHIP2_ACTUAL_DATA[1]} == random_val_arr[1]);
				LED_OUT[2] = ({CHIP1_ACTUAL_DATA[2], CHIP2_ACTUAL_DATA[2]} == random_val_arr[2]);
				LED_OUT[3] = ({CHIP1_ACTUAL_DATA[3], CHIP2_ACTUAL_DATA[3]} == random_val_arr[3]);
				LED_OUT[4] = ({CHIP1_ACTUAL_DATA[4], CHIP2_ACTUAL_DATA[4]} == random_val_arr[4]);
				LED_OUT[5] = ({CHIP1_ACTUAL_DATA[5], CHIP2_ACTUAL_DATA[5]} == random_val_arr[5]);
				LED_OUT[6] = ({CHIP1_ACTUAL_DATA[6], CHIP2_ACTUAL_DATA[6]} == random_val_arr[6]);
				LED_OUT[7] = ({CHIP1_ACTUAL_DATA[7], CHIP2_ACTUAL_DATA[7]} == random_val_arr[7]);
				LED_OUT[8] = ({CHIP1_ACTUAL_DATA[8], CHIP2_ACTUAL_DATA[8]} == random_val_arr[8]);
				LED_OUT[9] = ({CHIP1_ACTUAL_DATA[9], CHIP2_ACTUAL_DATA[9]} == random_val_arr[9]);
				LED_OUT[10] = ({CHIP1_ACTUAL_DATA[10], CHIP2_ACTUAL_DATA[10]} == random_val_arr[10]);
				LED_OUT[11] = ({CHIP1_ACTUAL_DATA[11], CHIP2_ACTUAL_DATA[11]} == random_val_arr[11]);
				LED_OUT[12] = ({CHIP1_ACTUAL_DATA[12], CHIP2_ACTUAL_DATA[12]} == random_val_arr[12]);
				LED_OUT[13] = ({CHIP1_ACTUAL_DATA[13], CHIP2_ACTUAL_DATA[13]} == random_val_arr[13]);
				LED_OUT[14] = ({CHIP1_ACTUAL_DATA[14], CHIP2_ACTUAL_DATA[14]} == random_val_arr[14]);
				LED_OUT[15] = ({CHIP1_ACTUAL_DATA[15], CHIP2_ACTUAL_DATA[15]} == random_val_arr[15]);
			end
		endcase
	end

endmodule
