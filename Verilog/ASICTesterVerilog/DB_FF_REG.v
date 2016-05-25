`timescale 1ns / 1ps

/*
 * Module:            DB_FF_REG
 * Function:          A FF_REG that is preceded by a register.
 * 
 * Inputs: 
 *    CLK
 *    RST
 *    EN_FF_LOGIC:    Active-high enable for counting cycles (see FF_REG.v).
 *    LOAD_FF:        Loads the FF value into a buffer in this module.
 *    TRANSFER_FF:    "Activates" the buffered FF value.
 *    FF: 		       0 == R0 		(see FF_REG.v)
 * 				       1 == DNRZ_L	(see FF_REG.v)
 *    LOAD_SIG:       Loads the signal value D into a buffer in this module.
 *    TRANSFER_SIG:   "Activates" the buffered signal value.
 * 	D
 *    LEADING_EDGE_1:  One possible leading edge value, determined by TEST_CYCLE.
 *    LEADING_EDGE_2:  One possible leading edge value, determined by TEST_CYCLE.
 *    TRAILING_EDGE_1: Trailing edge value. (Number of clock cycles to count before 
 *                     trailing edge occurs.)
 *    CYCLE_LENGTH_1:  Number of clock cycles comprising a single test cycle.
 *    TEST_CYCLE:      Determines whether to use LEADING_EDGE_1 or LEADING_EDGE_2.
 * Outputs:
 * 	Q
 */ 
module FF_DB_REG(CLK, RST, EN_FF_LOGIC, LOAD_FF, TRANSFER_FF, FF, 
					  LOAD_SIG, TRANSFER_SIG, D,
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
