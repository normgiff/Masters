`timescale 1ns / 1ps

/*
 * Module:      DUTSIG_DB_REG
 * Function:    A DUT signal register that is preceded by a register.
 * 
 * Inputs: 
 *    CLK
 *    RST
 *    LOAD:     Loads D into the buffer.
 *    TRANSFER: Transfers the buffer data to the DUT signal register.
 * 	D
 * Outputs:
 * 	Q
 */ 
module DUTSIG_DB_REG(CLK, RST, LOAD, TRANSFER, D, Q);
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
