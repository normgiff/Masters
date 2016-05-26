`timescale 1ns / 1ps

/*
 * Module:           FF_REG
 * Function:         A register that behaves according to the inputted force-format (FF) encoding.
 * 
 * Inputs: 
 *    EN:            Active-high enable for counting cycles (leading edge, trailing edge).
 * 	LEADING_EDGE:  Number of CLK cycles to count until leading edge.
 *    TRAILING_EDGE: Number of CLK cycles to count until trailing edge.
 *    CYCLE_LENGTH:  Number of CLK cycles in a single test cycle.
 * 	D		
 *  	FF: 		      0 == R0 		(force signal value on leading edge, return to zero on trailing edge)
 * 				      1 == DNRZ_L	(force signal value on leading edge)
 * Outputs:
 * 	Q
 */ 
 
module FF_REG(CLK, RST, EN, LEADING_EDGE, TRAILING_EDGE, CYCLE_LENGTH, D, FF, Q);
	input CLK;
	input RST;
	input EN;
	
	input [9:0] LEADING_EDGE;
	input [9:0] TRAILING_EDGE;
	input [9:0] CYCLE_LENGTH;
	input D;
	input FF;
	
	output reg Q;
	
	parameter R0 =     1'b0;
	parameter DNRZ_L = 1'b1;
	
	reg [9:0] cycle_counter;
	
	reg L_reg;
	
	// Register to count.
	always@(posedge CLK) begin
		if (RST || cycle_counter == CYCLE_LENGTH) begin
			cycle_counter <= 10'd1;
		end
		else begin
			if (EN) begin
				cycle_counter <= cycle_counter + 10'd1;
			end
			else begin
				cycle_counter <= 10'd1;
			end
		end
	end
	
	reg r0_val;
	
	// Register for R0 logic.
	always@(posedge CLK) begin
		if (RST) begin
			r0_val <= 1'b0;
		end
		else if (cycle_counter == LEADING_EDGE - 1) begin
			r0_val <= D;
		end
		else if (cycle_counter == TRAILING_EDGE - 1) begin
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
		if (RST) begin
			Q <= 1'b0;
		end
		else begin
			case(FF)
				DNRZ_L: begin
					Q <= L_reg;
				end
				R0: begin
					Q <= r0_val;
				end
			endcase
		end
	end
	
endmodule
