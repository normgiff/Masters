`timescale 1ns / 1ps

/*
 * Module:     FF_REG
 * Function:   A register that behaves according to the inputted force-format (FF) encoding.
 * 
 * Inputs: 
 * 	CYCLE: 	Low-to-high transition denotes leading edge
 * 				High-to-low transition denotes trailing edge
 * 	D		
 *  	FF: 		0 == R0 		(return to zero on trailing edge)
 * 				1 == DNRZ_L	(force signal value on leading edge)
 * Outputs:
 * 	Q
 */ 
 
module FF_REG(CLK, RST, EN, LEADING_EDGE, TRAILING_EDGE, CYCLE_LENGTH, D, FF, Q);
	input CLK;
	input RST;
	input EN;
	
	input [6:0] LEADING_EDGE;
	input [6:0] TRAILING_EDGE;
	input [7:0] CYCLE_LENGTH;
	input D;
	input FF;
	
	output reg Q;
	
	parameter R0 =     1'b0;
	parameter DNRZ_L = 1'b1;
	
	reg [7:0] cycle_counter;
	reg [8:0] cycle_counter_x2;
	
	reg L_reg;
	
	// Register to count.
	always@(posedge CLK) begin
		if (RST || cycle_counter == CYCLE_LENGTH) begin
			cycle_counter <= 7'd1;
		end
		else begin
			if (EN) begin
				cycle_counter <= cycle_counter + 7'd1;
			end
		end
	end
	
	reg r0_val;
	
	always@(posedge CLK) begin
		if (RST) begin
			r0_val <= 1'b0;
		end
		else if (cycle_counter == LEADING_EDGE) begin
			r0_val <= D;
		end
		else if (cycle_counter == TRAILING_EDGE) begin
			r0_val <= 1'b0;
		end
	end
	
	// Register to capture signal (leading edge).
	always@(posedge CLK) begin
		if (RST) begin
			L_reg <= 1'b0;
		end
		else begin
			if (cycle_counter == LEADING_EDGE - 1) begin
				L_reg <= D;
			end
		end
	end
	
	always@(posedge CLK) begin
		case(FF)
			DNRZ_L: begin
				Q <= L_reg;
			end
			R0: begin
				Q <= r0_val;
			end
		endcase
	end
	
endmodule
