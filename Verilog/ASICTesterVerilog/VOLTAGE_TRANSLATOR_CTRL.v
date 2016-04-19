`timescale 1ns / 1ps

/* 
 * Module: VOLTAGE_TRANSLATOR_CTRL
 * Function: Voltage translator controller.
 *
 * Inputs: 
 * 	EN_IN: Enables the voltage translator when high.
 *           Disables the voltage translator when low.
 * 
 * Outputs: 
 *		EN:    Same value as EN_IN.
 * 
 * The voltage translators should always be disabled except when performing
 * applying input vectors!
 */
module VOLTAGE_TRANSLATOR_CTRL(EN_IN, EN);
	input EN_IN;
	output EN;
	
	assign EN = EN_IN;

endmodule
