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
 *  	FF: 		    0 == R0 		(return to zero on trailing edge)
 * 				    1 == DNRZ_L	(force signal value on leading edge)
 * 	D
 * Outputs:
 * 	Q
 */ 
module FF_DB_REG(CLK, RST, EN_FF_LOGIC, LOAD_FF, TRANSFER_FF, FF, 
					  D, LOAD_SIG, TRANSFER_SIG,  
					  LEADING_EDGE_1, TRAILING_EDGE_1, CYCLE_LENGTH_1, LEADING_EDGE_2, 
					  TEST_CYCLE, Q);
	input CLK;
	input RST;
	input EN_FF_LOGIC;
	
	input LOAD_FF;
	input TRANSFER_FF;
	
	input FF;
	input D;
	
	input LOAD_SIG;
	input TRANSFER_SIG;
	
	input [6:0] LEADING_EDGE_1;
	input [6:0] TRAILING_EDGE_1;
	input [7:0] CYCLE_LENGTH_1;
	
	input [6:0] LEADING_EDGE_2;
	
	input TEST_CYCLE;
	
	output Q;
	
	reg buffer_data;
	reg buffer_out;
	
	reg ff_data;
	reg ff_out;

	wire [6:0] leading_edge;
	
	assign leading_edge = (TEST_CYCLE) ? LEADING_EDGE_2 : LEADING_EDGE_1;

	FF_REG ff_reg0(.CLK(CLK), .RST(RST), .EN(EN_FF_LOGIC), .LEADING_EDGE(leading_edge), 
						.TRAILING_EDGE(TRAILING_EDGE_1), .CYCLE_LENGTH(CYCLE_LENGTH_1), 
						.D(buffer_out), .FF(ff_out), .Q(Q));	
	
	always@(posedge CLK) begin
		if (RST) begin
			buffer_data <= 1'b0;
			buffer_out <= 1'b0;
			ff_data <= 1'b0;
			ff_out <= 1'b0;
		end
		else begin
			if (LOAD_SIG) begin
				buffer_data <= D;
			end
			if (LOAD_FF) begin
				ff_data <= FF;
			end
			if (TRANSFER_SIG) begin
				buffer_out <= buffer_data;
			end
			if (TRANSFER_FF) begin
				ff_out <= ff_data;
			end
		end
	end

endmodule
