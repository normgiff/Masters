`timescale 1ns / 1ps

/*
 * Module:          DUT_CTRL
 * Function:        A wrapper around all DUT logic.
 * 
 * Please see individual modules for more informatoin.
 */
module DUT_CTRL(CLK, RST, PERFORM_TEST, BUS126,
					 SIG_LOAD, SIG_TRANSFER, 
					 FF_LOAD_FF, FF_TRANSFER_FF,
					 FF_LOAD_SIG, FF_TRANSFER_SIG,
					 TEMPLATE_LOAD, TEMPLATE_TRANSFER,
					 CYCLE_LOAD, CYCLE_TRANSFER,
					 LEADING_EDGE_1, LEADING_EDGE_2, TRAILING_EDGE, CYCLE_LENGTH,
					 OUTPUT_SIGNALS
					 );
	input CLK;
	input RST;
	input PERFORM_TEST;
	input [125:0] BUS126;
	
	input SIG_LOAD;
	input SIG_TRANSFER;
	
	input FF_LOAD_FF;
	input FF_TRANSFER_FF;
	
	input FF_LOAD_SIG;
	input FF_TRANSFER_SIG;
	
	input [6:0] LEADING_EDGE_1;
	input [6:0] LEADING_EDGE_2;
	input [6:0] TRAILING_EDGE;
	input [7:0] CYCLE_LENGTH;
	
	input CYCLE_LOAD;
	input CYCLE_TRANSFER;

	input TEMPLATE_LOAD;
	input TEMPLATE_TRANSFER;
	
	output [125:0] OUTPUT_SIGNALS;
	
	wire [125:0] sig_outputs;
	wire [125:0] ff_outputs;
	wire [125:0] template_outputs;
	wire [125:0] cycle_outputs;
	
	// Signal registers.
	DUTSIG_DB_REG signal_regs[125:0](.CLK(CLK), .RST(RST), .LOAD(SIG_LOAD), 
												.TRANSFER(SIG_TRANSFER), .D(BUS126), 
												.Q(sig_outputs));
	
	// FF registers.
	FF_DB_REG ff_regs[125:0](.CLK(CLK), .RST(RST), .EN_FF_LOGIC(PERFORM_TEST), 
									  .LOAD_FF(FF_LOAD_FF), .TRANSFER_FF(FF_TRANSFER_FF), .FF(BUS126), 
									  .LOAD_SIG(FF_LOAD_SIG), .TRANSFER_SIG(FF_TRANSFER_SIG), 
									  .LEADING_EDGE_1(LEADING_EDGE_1), .LEADING_EDGE_2(LEADING_EDGE_2), 
									  .TRAILING_EDGE_1(TRAILING_EDGE), .CYCLE_LENGTH_1(CYCLE_LENGTH), 
									  .TEST_CYCLE(cycle_outputs), .D(sig_outputs), .Q(ff_outputs));
											
	// Template registers.
	TEMPLATE_DB_REG template_regs[125:0](.CLK(CLK), .RST(RST), .LOAD(TEMPLATE_LOAD),
													 .TRANSFER(TEMPLATE_TRANSFER), .D(BUS126), 
													 .Q(template_outputs));
													 
	// Signal registers.
	CYCLE_DB_REG cycle_regs[125:0](.CLK(CLK), .RST(RST), .LOAD(CYCLE_LOAD), 
											 .TRANSFER(CYCLE_TRANSFER), .D(BUS126), 
											 .Q(cycle_outputs));
			
	// Tristate registers.
	TRIREG triregs[125:0](.I(ff_outputs), .O(OUTPUT_SIGNALS), .EN_BAR(template_outputs));
												
endmodule
