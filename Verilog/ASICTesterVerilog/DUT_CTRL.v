`timescale 1ns / 1ps

/*
 * Module: DUT_CTRL
 * Function: A wrapper around all DUT logic.
 * Inputs: 
 *    CLK
 *    RST
 *    SIG_LOAD:     Load signals into signal pre-output buffer.
 *    SIG_TRANSFER: Load signals into signal output buffer.
 *    SIG_BUS_IN:   128-bit signal vector.
 *    SIG_BUS_OUT:  128-bit signal vector (output of FPGA).
 * 
 */
module DUT_CTRL(CLK, RST, PERFORM_TEST, BUS128,
					 SIG_LOAD, SIG_TRANSFER, 
					 FF_LOAD, FF_TRANSFER, 
					 TEMPLATE_LOAD, TEMPLATE_TRANSFER,
					 CYCLE_LOAD, CYCLE_TRANSFER,
					 LEADING_EDGE_1, TRAILING_EDGE_1, CYCLE_LENGTH_1,
					 LEADING_EDGE_2, TRAILING_EDGE_2, CYCLE_LENGTH_2, 
					 OUTPUT_SIGNALS
					 );
	input CLK;
	input RST;
	input PERFORM_TEST;
	input [127:0] BUS128;
	
	input SIG_LOAD;
	input SIG_TRANSFER;
	
	input FF_LOAD;
	input FF_TRANSFER;
	
	input [6:0] LEADING_EDGE_1;
	input [6:0] TRAILING_EDGE_1;
	input [7:0] CYCLE_LENGTH_1;
	input [6:0] LEADING_EDGE_2;
	input [6:0] TRAILING_EDGE_2;
	input [7:0] CYCLE_LENGTH_2;
	
	input CYCLE_LOAD;
	input CYCLE_TRANSFER;

	input TEMPLATE_LOAD;
	input TEMPLATE_TRANSFER;
	
	output [127:0] OUTPUT_SIGNALS;
	
	wire [127:0] sig_outputs;
	wire [127:0] ff_outputs;
	wire [127:0] template_outputs;
	wire [127:0] cycle_outputs;
	
	// Signal registers
	DUTSIG_DB_REG signal_regs[127:0](.CLK(CLK), .RST(RST), .LOAD(SIG_LOAD), 
												.TRANSFER(SIG_TRANSFER), .D(BUS128), 
												.Q(sig_outputs));
	
	// FF registers
	FF_DB_REG ff_regs[127:0](.CLK(CLK), .RST(RST), .EN_FF_LOGIC(PERFORM_TEST), 
									  .LOAD(FF_LOAD), .TRANSFER(FF_TRANSFER), .FF(BUS128), 
									  .LEADING_EDGE_1(LEADING_EDGE_1), .TRAILING_EDGE_1(TRAILING_EDGE_1), 
									  .CYCLE_LENGTH_1(CYCLE_LENGTH_1), .LEADING_EDGE_2(LEADING_EDGE_2), 
									  .TRAILING_EDGE_2(TRAILING_EDGE_2), .CYCLE_LENGTH_2(CYCLE_LENGTH_2), 
									  .TEST_CYCLE(cycle_outputs), .D(sig_outputs), .Q(ff_outputs));
											
	// Template registers
	TEMPLATE_DB_REG template_regs[127:0](.CLK(CLK), .RST(RST), .LOAD(TEMPLATE_LOAD),
													 .TRANSFER(TEMPLATE_TRANSFER), .D(BUS128), 
													 .Q(template_outputs));
													 
	// Signal registers
	CYCLE_DB_REG cycle_regs[127:0](.CLK(CLK), .RST(RST), .LOAD(CYCLE_LOAD), 
											 .TRANSFER(CYCLE_TRANSFER), .D(BUS128), 
											 .Q(cycle_outputs));
			
	// Tristate registers
	TRIREG triregs[127:0](.I(ff_outputs), .O(OUTPUT_SIGNALS), .EN_BAR(template_outputs));
												
endmodule
