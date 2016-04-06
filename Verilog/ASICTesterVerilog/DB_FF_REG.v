`timescale 1ns / 1ps

/*
 * Module:      DB_FF_REG
 * Function:    A FF_REG that is preceded by a register.
 * 
 * Inputs: 
 *    CLK
 *    RST
 * 	CYCLE: 	 Low-to-high transition denotes leading edge
 * 				 High-to-low transition denotes trailing edge
 *    LOAD:     Loads D into the buffer.
 *    TRANSFER: Transfers the buffer data to the FF register.
 *  	FF: 		 00 == R0 		(return to zero on trailing edge)
 *					 01 == R1 		(return to one on trailing edge)
 * 				 10 == DNRZ_L	(force signal value on leading edge)
 * 				 11 == DNRZ_T   (force signal value on trailing edge)
 * 	D
 * Outputs:
 * 	Q
 */ 
 
module DB_FF_REG(CLK, RST, CYCLE, LOAD, TRANSFER, FF, D, Q);
	input CLK;
	input RST;
	
	input CYCLE;
	input LOAD;
	input TRANSFER;
	
	input [1:0] FF;
	input D;
	output Q;
	
	reg buffer_data;
	reg buffer_out;
	
	FF_REG ff_reg0(.CYCLE(CYCLE), .D(buffer_out), .FF(FF), .Q(Q));	
	
	always@(posedge CLK) begin
		if (RST) begin
			buffer_data <= 1'b0;
			buffer_out <= 1'b0;
		end
		else if (LOAD) begin
			buffer_data <= D;
		end
		else if (TRANSFER) begin
			buffer_out <= buffer_data;
		end
		else begin
			buffer_data <= buffer_data;
			buffer_out <= buffer_out;
		end
	end

endmodule
