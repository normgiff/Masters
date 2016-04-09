`timescale 1ns / 1ps

`timescale 1ns / 1ps

/*
 * Module:     BRAM
 * Function:   32 blocks of dual-port block RAM (Spartan-6).
 * 
 * Inputs: 
 * 	CLK
 * 	EN_A: 	Enables port A for access.
 * 	EN_B:		Enables port B for access.
 *  	WE_A: 	Enables port A for write access.
 * 	WE_B: 	Enables port B for write access.
 * 	DIN_A: 	Data to be written (port A).
 *		DIN_B: 	Data to be written (port B).
 * 	ADDR_A: 	Location of data to be read from or written to (port A).
 * 	ADDR_B: 	Location of data to be read from or written to (port B).
 *
 * Outputs:
 * 	DOUT_A: 	Register that outputs the last word read from or written to (port A).
 *		DOUT_B: 	Register that outputs the last word read from or written to (port B).
 */ 
 
module BRAM(CLK, EN_A, EN_B, WE_A, WE_B, DIN_A, DIN_B, ADDR_A, ADDR_B, DOUT_A, DOUT_B);
	// Reading four adjacent memory addresses will output a full 128-bit vector.
	// With dual-port read, two read cycles are needed to obtain a full 128-bit vector.
	// To maximize block RAM space, the FPGA will fetch one output bit vector at a time and send
	// it to the BeagleBone Black. (Slow but oh well.)
	// Assuming a maximum of 196 template vectors, maximum number of input bit vectors is 4000.
	parameter RAM_WIDTH = 32; 
	parameter RAM_ADDR_BITS = 13;

	// Port A
	input CLK, EN_A, WE_A;
	input [RAM_WIDTH-1:0] DIN_A;
	input [RAM_ADDR_BITS-1:0] ADDR_A;
	output reg [RAM_WIDTH-1:0] DOUT_A;

	// Port B
	input EN_B, WE_B;
	input [RAM_WIDTH-1:0] DIN_B;
	input [RAM_ADDR_BITS-1:0] ADDR_B;
	output reg [RAM_WIDTH-1:0] DOUT_B;

	reg [RAM_WIDTH-1:0] the_memory_core [(2**RAM_ADDR_BITS)-1:0];

	always @(posedge CLK)
	begin
		if (EN_A == 1'b1) begin
			if (WE_A == 1'b1) begin
				the_memory_core[ADDR_A] <= DIN_A;
				// In write-first mode, the din is also passed on to dout
				DOUT_A <= DIN_A;
			end
			else
				DOUT_A <= the_memory_core[ADDR_A];
		end
		if (EN_B == 1'b1) begin
			if (WE_B == 1'b1) begin
				the_memory_core[ADDR_B] <= DIN_B;
				// In write-first mode, the din is also passed on to dout
				DOUT_B <= DIN_B;
			end
			else
				DOUT_B <= the_memory_core[ADDR_B];
		end
	end

endmodule
