`timescale 1ns / 1ps

/*
 * Module:     FF_REG
 * Function:   A register that behaves according to the inputted force-format (FF) encoding.
 * 
 * Inputs: 
 * 	CYCLE: 	Low-to-high transition denotes leading edge
 * 				High-to-low transition denotes trailing edge
 * 	D		
 *  	FF: 		00 == R0 		(return to zero on trailing edge)
 *					01 == R1 		(return to one on trailing edge)
 * 				10 == DNRZ_L	(force signal value on leading edge)
 * 				11 == DNRZ_T   (force signal value on trailing edge)
 * Outputs:
 * 	Q
 */ 
 
module FF_REG(CYCLE, D, FF, Q);	
	input CYCLE;
	input D;
	input [1:0] FF;
	output reg Q;
	
	parameter R0 =     2'b00;
	parameter R1 =     2'b01;
	parameter DNRZ_L = 2'b10;
	parameter DNRZ_T = 2'b11;
	
	reg L_reg;
	reg T_reg;
	
	// Register for leading edge.
	always@(posedge CYCLE) begin
		L_reg <= D;
	end
	
	always@(negedge CYCLE) begin
		T_reg <= D;
	end
	
	always@(*) begin
		case(FF)
			DNRZ_L: begin
				Q = L_reg;
			end
			DNRZ_T: begin
				Q = T_reg;
			end
			default: begin
				if (FF == R0) begin
					Q = CYCLE ? D : 1'b0;
				end
				else begin
					Q = CYCLE ? D : 1'b1;
				end
			end
		endcase
	end
	
endmodule
