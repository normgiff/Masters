`timescale 1ns / 1ps

/*
 * Module: 		 TRIREG
 * Function:    An output tristate register, used when forcing signals.
 * 
 * Inputs: 
 *    I
 *	   EN
 * Outputs:
 * 	O
 */ 
module TRIREG(I, O, EN_BAR);
	input I;
	input EN_BAR;
	output O;
	
	assign O = EN_BAR ? 1'bz : I;
	
	/*
	IOBUF #(
			.DRIVE(24),
			.IOSTANDARD("DEFAULT"),
			.SLEW("FAST") // Change to SLOW if we experience severe bouncing on the output line
	) IOBUF_inst (
			.O(),   // Unconnected since DUT outputs should not enter the FPGA
			.IO(O), // Just output
			.I(I),
			.T(EN_BAR)
	);
	*/

endmodule
