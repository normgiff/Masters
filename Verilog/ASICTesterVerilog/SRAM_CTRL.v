`timescale 1ns / 1ps

/* 
 * Module: SRAM_CTRL
 * Function: Controller for SRAM blocks.
 *           Part number: 71V016SA10PHG8
 *           Datasheet: http://www.idt.com/document/71v016sa-datasheet
 * 
 * Inputs: 
 * 	OE_BAR_IN: Active-low output enable.
 *    CS_BAR_IN: Active-low chip select.
 *    WE_BAR_IN: Active-low write enable.
 *
 * Outputs: 
 *    OE_BAR: Same as OE_BAR_IN.
 *    CS_BAR: Same as CS_BAR_IN.
 *    WE_BAR: Same as WE_BAR_IN.
 * 
 * Notes: 
 * 1) BHE and BLE (byte high and byte low enable pins) are tied to low, as
 *    we always want to read the full SRAM word.
 * 2) The SRAM chips should only accept writes when applying input vectors.
 */
module SRAM_CTRL(OE_BAR_IN, CS_BAR_IN, WE_BAR_IN, 
					  OE_BAR, 
					  CS_BAR_1, WE_BAR_1,
					  CS_BAR_2, WE_BAR_2,
					  CS_BAR_3, WE_BAR_3,
					  CS_BAR_4, WE_BAR_4);
					  
	input OE_BAR_IN;
	input CS_BAR_IN;
	input WE_BAR_IN;
	
	output OE_BAR;
	
	output CS_BAR_1;
	output WE_BAR_1;
	output CS_BAR_2;
	output WE_BAR_2;
	output CS_BAR_3;
	output WE_BAR_3;
	output CS_BAR_4;
	output WE_BAR_4;
	
	assign OE_BAR = OE_BAR_IN;
	
	assign CS_BAR_1 = CS_BAR_IN;
	assign WE_BAR_1 = WE_BAR_IN;

	assign CS_BAR_2 = CS_BAR_IN;
	assign WE_BAR_2 = WE_BAR_IN;

	assign CS_BAR_3 = CS_BAR_IN;
	assign WE_BAR_3 = WE_BAR_IN;

	assign CS_BAR_4 = CS_BAR_IN;
	assign WE_BAR_4 = WE_BAR_IN;

endmodule
