`timescale 1ns / 1ps

/* 
 * Module:   VOLTAGE_TRANSLATOR_CTRL
 * Function: Voltage translator controller.
 *
 * Inputs: 
 * 	CLK
 * 	RST
 * 	EN_IN: Enables the voltage translators when high.
 *           Disables the voltage translators when low.
 * 
 * Outputs: 
 *		EN:    Same value as EN_IN (synchronous assignment).
 * 
 * NOTICE:   The voltage translators must not be enabled when reading
 *           from SRAM!
 */
module VOLTAGE_TRANSLATOR_CTRL(CLK, RST, EN_IN, EN);
	input CLK;
	input RST;	
	input EN_IN;
	
	output reg EN;
	
	always@(posedge CLK) begin
		if (RST) begin
			// Disable when resetting for safety.
			EN <= 1'b0;
		end
		else begin
			EN <= EN_IN;
		end
	end
	
endmodule
