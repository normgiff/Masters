`timescale 1ns / 1ps

/*
 * Module: 		 TRIREG
 * Function:    An output tristate register, used when forcing signals.
 * 
 * Inputs: 
 *    I
 *	   EN_BAR    (active-low enable)
 * Outputs:
 * 	O
 */ 
module TRIREG(I, O, EN_BAR);
	input I;
	input EN_BAR;
	output O;
	
	assign O = EN_BAR ? 1'bz : I;
	
endmodule
