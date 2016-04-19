`timescale 1ns / 1ps

/*
 * Module:      CYCLE_DB_REG
 * Function:    A cycle register that is preceded by a register.
 * 
 * Inputs: 
 *    CLK
 *    RST
 *    LOAD:     Loads D into the buffer.
 *    TRANSFER: Transfers the buffer data to the "actual" cycle register.
 * 	D
 * Outputs:
 * 	Q
 */ 
module CYCLE_DB_REG(CLK, RST, LOAD, TRANSFER, D, Q);	 
	input CLK;
	input RST;
	input LOAD;
	input TRANSFER;
	input D;
	
	output reg Q;
	reg internal_q;
	
	always@(posedge CLK) begin
		if (RST) begin
			Q <= 1'b0;
			internal_q <= 1'b0;
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
