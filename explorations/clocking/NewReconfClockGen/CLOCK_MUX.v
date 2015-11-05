`timescale 1ns / 1ps

/*
 * Creates the "clock" signal for an ODDR register.
 * Inputs: 
 * 	SEL: Used to control the BUFGMUX output.
 *    OUT: Effectively a configurable clock signal.
 */
module CLOCK_MUX(SEL, OUT);

input SEL;

output OUT;

BUFGMUX #(.CLK_SEL_TYPE("ASYNC")) BUFGMUX_inst (
	.O(OUT),
	.I0(1'b0),
	.I1(1'b1),
	.S(SEL)
);

endmodule
