`timescale 1ns / 1ps

/*
 * Module:      DB_FF_REG
 * Function:    A FF_REG that is preceded by a register.
 * 
 * Inputs: 
 *    CLK
 *    RST
 *    EN_FF_LOGIC: 
 * 	CYCLE: 	    Low-to-high transition denotes leading edge
 * 				    High-to-low transition denotes trailing edge
 *    LOAD:        Loads D into the buffer.
 *    TRANSFER:    Transfers the buffer data to the FF register.
 *  	FF: 		    00 == R0 		(return to zero on trailing edge)
 *					    01 == R1 		(return to one on trailing edge)
 * 				    10 == DNRZ_L	(force signal value on leading edge)
 * 				    11 == DNRZ_T   (force signal value on trailing edge)
 * 	D
 * Outputs:
 * 	Q
 */ 
module FF_DB_REG(CLK, RST, EN_FF_LOGIC, LOAD, TRANSFER, FF, D, 
					  LEADING_EDGE_1, TRAILING_EDGE_1, CYCLE_LENGTH_1, 
					  LEADING_EDGE_2, TRAILING_EDGE_2, CYCLE_LENGTH_2, 
					  TEST_CYCLE, Q);
	input CLK;
	input RST;
	input EN_FF_LOGIC;
	
	input LOAD;
	input TRANSFER;
	
	input [1:0] FF;
	input D;
	
	input [6:0] LEADING_EDGE_1;
	input [6:0] TRAILING_EDGE_1;
	input [7:0] CYCLE_LENGTH_1;
	
	input [6:0] LEADING_EDGE_2;
	input [6:0] TRAILING_EDGE_2;
	input [7:0] CYCLE_LENGTH_2;
	
	input TEST_CYCLE;
	
	output Q;
	
	reg buffer_data;
	reg buffer_out;

	reg [6:0] leading_edge;
	reg [6:0] trailing_edge;
	reg [7:0] cycle_length;
	
	always@(*) begin
		if (TEST_CYCLE) begin
			leading_edge = LEADING_EDGE_2;
			trailing_edge = TRAILING_EDGE_2;
			cycle_length = CYCLE_LENGTH_2;
		end
		else begin
			leading_edge = LEADING_EDGE_1;
			trailing_edge = TRAILING_EDGE_1;
			cycle_length = CYCLE_LENGTH_1;
		end
	end

	FF_REG ff_reg0(.CLK(CLK), .RST(RST), .EN(EN_FF_LOGIC), .LEADING_EDGE(leading_edge), 
						.TRAILING_EDGE(trailing_edge), .CYCLE_LENGTH(cycle_length), 
						.D(buffer_out), .FF(FF), .Q(Q));	
	
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
	end

endmodule
