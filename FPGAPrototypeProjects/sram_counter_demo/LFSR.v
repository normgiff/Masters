`timescale 1ns / 1ps

/*
 * Linear feedback shift register.
 * 8-bit bandwidth.
 */
module LFSR(CLK, RST, SEED, LOAD, GET_NEXT, OUT);
	input CLK;
	input RST;
	input [3:0] SEED;
	input GET_NEXT;
	input LOAD;
	
	output OUT;
	
	wire [3:0] RVAL_IN;
	wire [3:0] RVAL_OUT;
	
	DFF FF_ARR[3:0] (.CLK(CLK), .RST(RST), .EN(LOAD || GET_NEXT), .D(RVAL_IN), .Q(RVAL_OUT));
	MUX21 MUX_ARR[3:0] (.SEL(~LOAD), .A(SEED), .B({OUT, RVAL_OUT[3], RVAL_OUT[2], RVAL_OUT[1]}), .OUT(RVAL_IN));

	assign OUT = (RVAL_OUT[3] ^ RVAL_OUT[2]) ^ (RVAL_OUT[1] ^ RVAL_OUT[0]);

endmodule
