`timescale 1ns / 1ps

/*
 * Module: BRAM_CTRL
 * Function: A wrapper around the BRAM. 
 * 			 Reads/writes an input vector (126 bits) and the corresponding template (2 bits). 
 * 			 Two clock cycles are needed to complete a read or write request.
 * 			 
 * Inputs: 
 * 	CLK
 * 	RST
 *		INPUT_WRITE:        128-bit write {2 template bits, 126 input vector bits} 		
 * 	TEMPLATE_WRITE: 	  128-bit write {2 template bits, 126 template-config bits}	
 * 	FF_WRITE: 		 	  128-bit write {2 template bits, 63 sets of 2-bit FF configs}
 *    TC_WRITE:           128-bit write {2 template bits, 126 cycle-config bits}
 * 	WRITE_DATA_0: 		  128-bit write input.
 * 	WRITE_DATA_1: 		  128-bit write input (for FF_WRITE only).
 * 	
 * Outputs: 
 * 	READ_DATA_0: 		  128-bit read output.
 * 	READ_DATA_1: 		  128-bit read output (for FF_READ only).
 * 	TEMPLATE_READ:      128-bit read {2 template bits, 126 template-config bits}
 * 	TEMPLATE_BITS:      When performing a TEMPLATE_READ or FF_READ, two template bits 
 * 							  must be provided naturally.
 * 	INPUT_READ:         128-bit read {2 template bits, 126 input vector bits}
 * 	FF_READ:            128-bit read {2 template bits, 64 sets of 2-bit FF configs}
 *    TC_READ:            128-bit read {2 template bits, 126 cycle-config bits}
 *		TEMPLATE_CHANGE: 	  Indicates if the read template is different from the last read template.
 * 	READY: 		        Read/write operation is not in progress.
 *    MORE_TO_READ:       Always 1 unless this controller has finished reading the last input vector.
 *                        Reading again will cause the first input vector to be read.
 * 
 */
module BRAM_CTRL(CLK, RST, 
					  INPUT_WRITE, TEMPLATE_WRITE, FF_WRITE, TC_WRITE,
					  WRITE_DATA_0, WRITE_DATA_1,
					  TEMPLATE_READ, TEMPLATE_BITS, INPUT_READ, FF_READ, TC_READ,
					  READ_DATA_0, READ_DATA_1, 
					  TEMPLATE_CHANGE, READY,
					  MORE_TO_READ);					  
					  
	`include "BRAM_CTRL_PARAMS.v"
	
	input CLK;
	input RST;
	
	input INPUT_WRITE;
	input TEMPLATE_WRITE;
	input FF_WRITE;
	input TC_WRITE;
	input [127:0] WRITE_DATA_0;
	input [127:0] WRITE_DATA_1;
	
	input TEMPLATE_READ;
	input [1:0] TEMPLATE_BITS;
	input INPUT_READ;
	input FF_READ;
	input TC_READ;
	
	output reg [127:0] READ_DATA_0;
	output reg [127:0] READ_DATA_1;
	output reg TEMPLATE_CHANGE;
	output READY;
	output MORE_TO_READ;
	
	assign READY = (PS == IDLE);
	assign MORE_TO_READ = (PS == IDLE) && (input_vectors_written == input_vectors_read);
	
	wire write_en = PS == INPUT_WRITE_1 || PS == INPUT_WRITE_2 || 
						 PS == TEMPLATE_WRITE_1 || PS == TEMPLATE_WRITE_2 || 
						 PS == FF_WRITE_1 || PS == FF_WRITE_2 || PS == FF_WRITE_3 || 
						 PS == FF_WRITE_4;
						 
	wire [63:0] dout;
	reg [63:0] din;
	reg [12:0] addr_a;
	reg [12:0] addr_b;
	
	reg [2:0] prev_temp;
	reg [1:0] curr_temp;
	
	reg [6:0] input_write_posA;
	reg [6:0] input_read_posA;
	reg [6:0] input_write_posB;
	reg [6:0] input_read_posB;
	
	// Right now, only 240 input vectors are allowed.
	reg [7:0] input_vectors_written;
	reg [7:0] input_vectors_read;
	
	BRAM bram0(.CLK(CLK), .EN_A(1'b1), .EN_B(1'b1), .WE_A(write_en), .WE_B(write_en), 
				  .DIN_A(din[31:0]), .DIN_B(din[63:32]), .ADDR_A(addr_a), .ADDR_B(addr_b), 
				  .DOUT_A(dout[31:0]), .DOUT_B(dout[63:32]));
				  
	reg [4:0] PS;
	reg [4:0] NS;
	
	// Present-state logic.
	always@(posedge CLK) begin
		if (RST) begin
			PS <= IDLE;
		end
		else begin
			PS <= NS;
		end
	end
	
	// Next-state logic.
	always@(*) begin
		case (PS)
			IDLE: begin
				if (INPUT_WRITE) begin
					NS = INPUT_WRITE_1;
				end
				else if (TEMPLATE_WRITE) begin
					NS = TEMPLATE_WRITE_1;
				end
				else if (FF_WRITE) begin
					NS = FF_WRITE_1;
				end
				else if (TC_WRITE) begin
					NS = TC_WRITE_1;
				end
				else if (INPUT_READ) begin
					NS = INPUT_READ_0;
				end
				else if (TEMPLATE_READ) begin
					NS = TEMPLATE_READ_0;
				end
				else if (FF_READ) begin
					NS = FF_READ_0;
				end
				else if (TC_READ) begin
					NS = TC_READ_0;
				end
				else begin
					NS = IDLE;
				end
			end
			
			INPUT_WRITE_1: begin
				NS = INPUT_WRITE_2;
			end
			
			INPUT_WRITE_2: begin
				NS = IDLE;
			end
			
			TEMPLATE_WRITE_1: begin
				NS = TEMPLATE_WRITE_2;
			end
			
			TEMPLATE_WRITE_2: begin
				NS = IDLE;
			end
			
			FF_WRITE_1: begin
				NS = FF_WRITE_2;
			end
			
			FF_WRITE_2: begin
				NS = FF_WRITE_3;
			end
			
			FF_WRITE_3: begin
				NS = FF_WRITE_4;
			end
			
			FF_WRITE_4: begin
				NS = IDLE;
			end
			
			TC_WRITE_1: begin
				NS = TC_WRITE_2; 
			end
			
			TC_WRITE_2: begin
				NS = IDLE;
			end
			
			INPUT_READ_0: begin
				NS = INPUT_READ_1;
			end
			
			INPUT_READ_1: begin
				NS = INPUT_READ_2;
			end
			
			INPUT_READ_2: begin
				NS = CHECK_TEMPLATE;
			end
			
			TEMPLATE_READ_0: begin
				NS = TEMPLATE_READ_1;
			end
			
			TEMPLATE_READ_1: begin
				NS = TEMPLATE_READ_2;
			end
			
			TEMPLATE_READ_2: begin
				NS = IDLE;
			end
			
			FF_READ_0: begin
				NS = FF_READ_1;
			end
			
			FF_READ_1: begin
				NS = FF_READ_2;
			end
			
			FF_READ_2: begin
				NS = FF_READ_3;
			end
			
			FF_READ_3: begin
				NS = FF_READ_4;
			end
			
			FF_READ_4: begin
				NS = IDLE;
			end
			
			TC_READ_0: begin
				NS = TC_READ_1;
			end
			
			TC_READ_1: begin
				NS = TC_READ_2;
			end
			
			TC_READ_2: begin
				NS = IDLE;
			end
			
			CHECK_TEMPLATE: begin
				NS = IDLE;
			end
			
			default: begin
				// Should never get here.
				NS = IDLE;
			end
		endcase
	end
	
	// Logic to update number of input vectors read and written.
	always@(posedge CLK) begin
		if (RST) begin
			input_vectors_written <= 8'd0;
			input_vectors_read <= 8'd0;
		end
		else begin
			if (PS == INPUT_WRITE_2) begin
				input_vectors_written <= input_vectors_written + 8'd1;
			end
			else if (PS == INPUT_READ_1) begin
				// Delay by a clock cycle so we can reset this counter in time.
				// (See below.)
				input_vectors_read <= input_vectors_read + 8'd1;
			end
			
			if (input_vectors_read == input_vectors_written) begin
				input_vectors_read <= 8'd0;
			end
		end
	end
	
	// Logic to update read and write addresses for input vectors.
	always@(posedge CLK) begin
		if (RST) begin
			input_write_posA <= INPUT_START_ADDR_A;
			input_read_posA <= INPUT_START_ADDR_A;
			input_write_posB <= INPUT_START_ADDR_B;
			input_read_posB <= INPUT_START_ADDR_B;
		end
		else begin
			if (PS == INPUT_WRITE_1 || PS == INPUT_WRITE_2) begin
				input_write_posA <= input_write_posA + INPUT_INCR_FACTOR;
				input_write_posB <= input_write_posB + INPUT_INCR_FACTOR;
			end
			else if (PS == INPUT_READ_0 || PS == INPUT_READ_1) begin
				input_read_posA <= input_read_posA + INPUT_INCR_FACTOR;
				input_read_posB <= input_read_posB + INPUT_INCR_FACTOR;
			end
		end
	end
	
	// Combinational logic.
	always@(*) begin
		din = 64'd0;
		addr_a = 14'd0;
		addr_b = 14'd0;
		case (PS)
			IDLE: begin
				// Do nothing.
			end
			
			INPUT_WRITE_1: begin
				din = WRITE_DATA_0[63:0];
				addr_a = {input_write_posA, 6'b000000};
				addr_b = {input_write_posB, 6'b000000};
			end
			
			INPUT_WRITE_2: begin
				din = WRITE_DATA_0[127:64];
				addr_a = {input_write_posA, 6'b100000};
				addr_b = {input_write_posB, 6'b100000};
			end
			
			TEMPLATE_WRITE_1: begin
				din = WRITE_DATA_0[63:0];
				case (WRITE_DATA_0[127:126])
					2'b00: begin
						addr_a = TEMPLATE_0_ADDR_A0;
						addr_b = TEMPLATE_0_ADDR_B0;
					end
					2'b01: begin
						addr_a = TEMPLATE_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR);
						addr_b = TEMPLATE_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TEMPLATE_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = TEMPLATE_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						// Left-shifting by 2 and subtracting the original value 
						// is equivalent to multiplying by three.
						addr_a = TEMPLATE_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = TEMPLATE_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			TEMPLATE_WRITE_2: begin
				din = WRITE_DATA_0[127:64];
				case (WRITE_DATA_0[127:126])
					2'b00: begin
						addr_a = TEMPLATE_0_ADDR_A1;
						addr_b = TEMPLATE_0_ADDR_B1;
					end
					2'b01: begin
						addr_a = TEMPLATE_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR);
						addr_b = TEMPLATE_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TEMPLATE_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = TEMPLATE_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = TEMPLATE_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = TEMPLATE_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_WRITE_1: begin
				din = WRITE_DATA_0[63:0];
				case (WRITE_DATA_1[127:126])
					2'b00: begin
						addr_a = FF_0_ADDR_A0;
						addr_b = FF_0_ADDR_B0;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_WRITE_2: begin
				din = WRITE_DATA_0[127:64];
				case (WRITE_DATA_1[127:126])
					2'b00: begin
						addr_a = FF_0_ADDR_A1;
						addr_b = FF_0_ADDR_B1;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_WRITE_3: begin
				din = WRITE_DATA_1[63:0];
				case (WRITE_DATA_1[127:126])
					2'b00: begin
						addr_a = FF_0_ADDR_A2;
						addr_b = FF_0_ADDR_B2;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A2 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B2 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A2 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B2 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A2 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B2 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_WRITE_4: begin
				din = WRITE_DATA_1[127:64];
				case (WRITE_DATA_1[127:126])
					2'b00: begin
						addr_a = FF_0_ADDR_A3;
						addr_b = FF_0_ADDR_B3;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A3 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B3 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A3 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B3 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A3 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B3 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			TC_WRITE_1: begin
				din = WRITE_DATA_0[63:0];
				case (WRITE_DATA_0[127:126])
					2'b00: begin
						addr_a = TC_0_ADDR_A0;
						addr_b = TC_0_ADDR_B0;
					end
					2'b01: begin
						addr_a = TC_0_ADDR_A0 + (TC_INCR_FACTOR);
						addr_b = TC_0_ADDR_B0 + (TC_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TC_0_ADDR_A0 + (TC_INCR_FACTOR << 1);
						addr_b = TC_0_ADDR_B0 + (TC_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = TC_0_ADDR_A0 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
						addr_b = TC_0_ADDR_B0 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
					end
				endcase
			end
			
			TC_WRITE_2: begin
				din = WRITE_DATA_0[63:0];
				case (WRITE_DATA_0[127:126])
					2'b00: begin
						addr_a = TC_0_ADDR_A1;
						addr_b = TC_0_ADDR_B1;
					end
					2'b01: begin
						addr_a = TC_0_ADDR_A1 + (TC_INCR_FACTOR);
						addr_b = TC_0_ADDR_B1 + (TC_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TC_0_ADDR_A1 + (TC_INCR_FACTOR << 1);
						addr_b = TC_0_ADDR_B1 + (TC_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = TC_0_ADDR_A1 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
						addr_b = TC_0_ADDR_B1 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
					end
				endcase
			end
			
			INPUT_READ_0: begin
				addr_a = {input_read_posA, 6'b000000};
				addr_b = {input_read_posB, 6'b000000};
			end
			
			INPUT_READ_1: begin
				addr_a = {input_read_posA, 6'b100000};
				addr_b = {input_read_posB, 6'b100000};
			end
			
			INPUT_READ_2: begin
				// Data fully read by now.
			end
			
			TEMPLATE_READ_0: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = TEMPLATE_0_ADDR_A0;
						addr_b = TEMPLATE_0_ADDR_B0;
					end
					2'b01: begin
						addr_a = TEMPLATE_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR);
						addr_b = TEMPLATE_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TEMPLATE_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = TEMPLATE_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = TEMPLATE_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = TEMPLATE_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			TEMPLATE_READ_1: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = TEMPLATE_0_ADDR_A1;
						addr_b = TEMPLATE_0_ADDR_B1;
					end
					2'b01: begin
						addr_a = TEMPLATE_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR);
						addr_b = TEMPLATE_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TEMPLATE_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = TEMPLATE_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = TEMPLATE_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = TEMPLATE_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			TEMPLATE_READ_2: begin
				// Data fully read by now.
			end
			
			TC_READ_0: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = TC_0_ADDR_A0;
						addr_b = TC_0_ADDR_B0;
					end
					2'b01: begin
						addr_a = TC_0_ADDR_A0 + (TC_INCR_FACTOR);
						addr_b = TC_0_ADDR_B0 + (TC_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TC_0_ADDR_A0 + (TC_INCR_FACTOR << 1);
						addr_b = TC_0_ADDR_B0 + (TC_INCR_FACTOR << 1);
					end
					2'b11: begin
							addr_a = TC_0_ADDR_A0 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
						addr_b = TC_0_ADDR_B0 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
					end
				endcase
			end
			
			TC_READ_1: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = TC_0_ADDR_A1;
						addr_b = TC_0_ADDR_B1;
					end
					2'b01: begin
						addr_a = TC_0_ADDR_A1 + (TC_INCR_FACTOR);
						addr_b = TC_0_ADDR_B1 + (TC_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = TC_0_ADDR_A1 + (TC_INCR_FACTOR << 1);
						addr_b = TC_0_ADDR_B1 + (TC_INCR_FACTOR << 1);
					end
					2'b11: begin
						// Left-shifting by 2 is equivalent to multiplying by four.
						// Left-shifting by 2 and subtracting is equivalent to multiplying by three.
						addr_a = TC_0_ADDR_A1 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
						addr_b = TC_0_ADDR_B1 + (TC_INCR_FACTOR << 2) - TC_INCR_FACTOR;
					end
				endcase
			end
			
			TC_READ_2: begin
				// Data fully read by now.
			end
			
			FF_READ_0: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = FF_0_ADDR_A0;
						addr_b = FF_0_ADDR_B0;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B0 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_READ_1: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = FF_0_ADDR_A1;
						addr_b = FF_0_ADDR_B1;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B1 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_READ_2: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = FF_0_ADDR_A2;
						addr_b = FF_0_ADDR_B2;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A2 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B2 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A2 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B2 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A2 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B2 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_READ_3: begin
				case (TEMPLATE_BITS)
					2'b00: begin
						addr_a = FF_0_ADDR_A3;
						addr_b = FF_0_ADDR_B3;
					end
					2'b01: begin
						addr_a = FF_0_ADDR_A3 + (TEMPLATE_INCR_FACTOR);
						addr_b = FF_0_ADDR_B3 + (TEMPLATE_INCR_FACTOR);
					end
					2'b10: begin
						addr_a = FF_0_ADDR_A3 + (TEMPLATE_INCR_FACTOR << 1);
						addr_b = FF_0_ADDR_B3 + (TEMPLATE_INCR_FACTOR << 1);
					end
					2'b11: begin
						addr_a = FF_0_ADDR_A3 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
						addr_b = FF_0_ADDR_B3 + (TEMPLATE_INCR_FACTOR << 2) -  TEMPLATE_INCR_FACTOR;
					end
				endcase
			end
			
			FF_READ_4: begin
				// Data fully read by now.
			end
			
		endcase
	end
	
	// Logic to latch onto data read. 
	always@(posedge CLK) begin
		if (RST) begin
			READ_DATA_0 <= 128'd0;
			READ_DATA_1 <= 128'd0;
		end
		else begin
			case (PS) 
				INPUT_READ_1: begin
					READ_DATA_0[63:0] <= dout;
				end
				
				INPUT_READ_2: begin
					READ_DATA_0[127:64] <= dout;
				end
				
				TEMPLATE_READ_1: begin
					READ_DATA_0[63:0] <= dout;
				end
				
				TEMPLATE_READ_2: begin
					READ_DATA_0[127:64] <= dout;
				end
				
				FF_READ_1: begin
					READ_DATA_0[63:0] <= dout;
				end
				
				FF_READ_2: begin
					READ_DATA_0[127:64] <= dout;
				end
				
				FF_READ_3: begin
					READ_DATA_1[63:0] <= dout;
				end
				
				FF_READ_4: begin
					READ_DATA_1[127:64] <= dout;
				end
				
				TC_READ_1: begin
					READ_DATA_0[63:0] <= dout;
				end
				
				TC_READ_2: begin
					READ_DATA_0[127:64] <= dout;
				end
				
			endcase
		end
	end
	
	// Logic to track the current template read.
	always@(posedge CLK) begin
		if (RST) begin
			curr_temp <= 2'd0;
		end
		else if (PS == INPUT_READ_2) begin
			curr_temp <= READ_DATA_0[127:126];
		end
	end
	
	// Logic to check for template changes.
	always@(posedge CLK) begin
		if (RST) begin
			prev_temp <= RESET_TEMPLATE; 
		end
		else if (PS == CHECK_TEMPLATE) begin
			if (prev_temp[2] == 1'b1 || prev_temp != curr_temp) begin
				TEMPLATE_CHANGE <= 1'b1;
				prev_temp <= curr_temp;
			end
			else begin
				TEMPLATE_CHANGE <= 1'b0;
			end
		end
	end

endmodule
