`timescale 1ns / 1ps

/* 
 * Simple DFF.
 */
module DFF(CLK, RST, EN, D, Q);
	input CLK;
	input RST;
	input EN;
	input D;
	output reg Q;
	
	always@(posedge CLK) begin
		if (RST) begin
			Q <= 1'b0;
		end
		else if (EN) begin
			Q <= D;
		end
		else begin
			Q <= Q;
		end
	end

endmodule
