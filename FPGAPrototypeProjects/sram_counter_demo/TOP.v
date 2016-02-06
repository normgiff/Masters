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
 * 1) We load the SRAM block with 32 pseudorandom values (16 per chip), using the counter to address the SRAM block.
 * 2) We reset the counter and attempt to load back the pseudorandom values stored in SRAM.
 * 3) The FPGA reports (via LEDs, because why not?) whether the values came back as expected.
 */
module TOP(CLK, RST, COUNTER_CLK, COUNTER_RST, WE_BAR, CHIP1_DATA, CHIP2_DATA);
	input CLK;
	input RST;
	
	// Counter
	output COUNTER_CLK;
	output reg COUNTER_RST;
	
	// SRAM
	output reg WE_BAR;
	inout reg [7:0] CHIP1_DATA;
	inout reg [7:0] CHIP2_DATA;
	
	reg [15:0] CHIP1_ACTUAL_DATA [15:0];
	reg [15:0] CHIP2_ACTUAL_DATA [15:0];

	// FSM 
	parameter IDLE = 7'd0;
	parameter GENERATE = 7'd35;
	parameter W1 = 7'd1;
	parameter W2 = 7'd2;
	parameter W3 = 7'd3;
	parameter W4 = 7'd4;
	parameter W5 = 7'd5;
	parameter W6 = 7'd6;
	parameter W7 = 7'd7;
	parameter W8 = 7'd8;
	parameter W9 = 7'd9;
	parameter W10 = 7'd10;
	parameter W11 = 7'd11;
	parameter W12 = 7'd12;
	parameter W13 = 7'd13;
	parameter W14 = 7'd14;
	parameter W15 = 7'd15;
	parameter W16 = 7'd16;
	parameter READ = 7'd17;
	parameter R1 = 7'd18;
	parameter R2 = 7'd19;
	parameter R3 = 7'd20;
	parameter R4 = 7'd21;
	parameter R5 = 7'd22;
	parameter R6 = 7'd23;
	parameter R7 = 7'd24;
	parameter R8 = 7'd25;
	parameter R9 = 7'd26;
	parameter R10 = 7'd27;
	parameter R11 = 7'd28;
	parameter R12 = 7'd29;
	parameter R13 = 7'd30;
	parameter R14 = 7'd31;
	parameter R15 = 7'd32;
	parameter R16 = 7'd33;
	parameter VERIFY = 7'd34;
	
	reg [6:0] PS;
	reg [6:0] NS;
	
	// Present-state logic
	always@(posedge CLK) begin
		if (RST) begin
			PS <= IDLE;
		end
		else begin
			PS <= NS;
		end
	end
	
	// Next-state logic
	always@(*) begin
		case (PS)
			IDLE: begin
				
			end
		
		endcase
	end

endmodule
