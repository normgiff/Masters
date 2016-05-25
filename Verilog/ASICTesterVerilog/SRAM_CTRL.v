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
 *    OE_BAR: Same as OE_BAR_IN (synchronous assignment).
 *    CS_BAR: Same as CS_BAR_IN (synchronous assignment).
 *    WE_BAR: Same as WE_BAR_IN (synchronous assignment).
 * 
 * Notes: 
 * 1) BHE and BLE (byte high and byte low enable pins) are tied to low, as
 *    we always want to read the full SRAM word.
 * 2) The SRAM chips should only accept writes when applying input vectors.
 */
module SRAM_CTRL(CLK, RST, 
					  OE_BAR_IN, CS_BAR_IN, WE_BAR_IN, 
					  OE_BAR, 
					  CS_BAR_1, WE_BAR_1,
					  CS_BAR_2, WE_BAR_2,
					  CS_BAR_3, WE_BAR_3,
					  CS_BAR_4, WE_BAR_4);
	input CLK;
	input RST;
	
	input OE_BAR_IN;
	input CS_BAR_IN;
	input WE_BAR_IN;
	
	output reg OE_BAR;
	output reg CS_BAR_1;
	output reg WE_BAR_1;
	output reg CS_BAR_2;
	output reg WE_BAR_2;
	output reg CS_BAR_3;
	output reg WE_BAR_3;
	output reg CS_BAR_4;
	output reg WE_BAR_4;
	
	always@(posedge CLK) begin
		if (RST) begin
			// SRAM chips are off by default.		
			CS_BAR_1 <= 1'b1;
			CS_BAR_2 <= 1'b1;
			CS_BAR_3 <= 1'b1;
			CS_BAR_4 <= 1'b1;
			
			WE_BAR_1 <= 1'b1;
			WE_BAR_2 <= 1'b1;
			WE_BAR_3 <= 1'b1;
			WE_BAR_4 <= 1'b1;
			
			OE_BAR <= 1'b1;
		end
		else begin
			CS_BAR_1 <= CS_BAR_IN;
			CS_BAR_2 <= CS_BAR_IN;
			CS_BAR_3 <= CS_BAR_IN;
			CS_BAR_4 <= CS_BAR_IN;
			
			WE_BAR_1 <= WE_BAR_IN;
			WE_BAR_2 <= WE_BAR_IN;
			WE_BAR_3 <= WE_BAR_IN;
			WE_BAR_4 <= WE_BAR_IN;
			
			OE_BAR <= OE_BAR_IN;		
		end
	end
	
endmodule
