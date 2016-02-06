`timescale 1ns / 1ps

module RANDOM_GEN(CLK, RST, GET_NEXT, SEED, VAL);
	input CLK;
	input RST;
	input GET_NEXT;
	input [7:0] SEED;
	
	output [7:0] VAL;
	
	// Prime number
	parameter A = 7'd101;
	parameter MODULUS = 8'd128;
	
	always@(posedge CLK) begin
		if (RST) begin
			VAL <= SEED;
		end
		else if (GET_NEXT) begin
			VAL <= (VAL * A) & MODULUS;
		end		
	end

endmodule
