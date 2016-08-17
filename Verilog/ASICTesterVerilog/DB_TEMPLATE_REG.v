`timescale 1ns / 1ps

/*
 * Module:      TEMPLATE_DB_REG
 * Function:    A double-buffered register for template values.
 * 
 * Inputs: 
 *    CLK
 *    RST
 *    LOAD:     Loads D into the buffer.
 *    TRANSFER: Transfers the buffer data to the output register.
 * 	D
 * Outputs:
 * 	Q
 */ 
module TEMPLATE_DB_REG(CLK, RST, LOAD, TRANSFER, D, Q);
	input CLK;
	input RST;
	input LOAD;
	input TRANSFER;
	input D;
	
	output reg Q;
	reg internal_q;
	
	always@(posedge CLK) begin
		if (RST) begin
			// NOTE: By default, internal tristates MUST be disabled upon reset.
			// Otherwise, we might drive a DUT output!
			Q <= 1'b1;
			internal_q <= 1'b1;
		end
		else begin
			if (LOAD) begin
				internal_q <= D;
			end
			else if (TRANSFER) begin
				Q <= internal_q;
			end
		end		
	end

endmodule
