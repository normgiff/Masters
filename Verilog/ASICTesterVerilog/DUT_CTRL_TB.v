`timescale 1ns / 1ps

module DUT_CTRL_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg PERFORM_TEST;
	reg [127:0] BUS128_0;
	reg [127:0] BUS128_1;
	reg SIG_LOAD;
	reg SIG_TRANSFER;
	reg FF_LOAD;
	reg FF_TRANSFER;
	reg TEMPLATE_LOAD;
	reg TEMPLATE_TRANSFER;
	reg CYCLE_LOAD;
	reg CYCLE_TRANSFER;
	reg [6:0] LEADING_EDGE_1;
	reg [6:0] TRAILING_EDGE_1;
	reg [7:0] CYCLE_LENGTH_1;
	reg [6:0] LEADING_EDGE_2;
	reg [6:0] TRAILING_EDGE_2;
	reg [7:0] CYCLE_LENGTH_2;

	// Outputs
	wire [127:0] OUTPUT_SIGNALS;

	// Instantiate the Unit Under Test (UUT)
	DUT_CTRL uut (
		.CLK(CLK), 
		.RST(RST), 
		.PERFORM_TEST(PERFORM_TEST), 
		.BUS128_0(BUS128_0), 
		.BUS128_1(BUS128_1), 
		.SIG_LOAD(SIG_LOAD), 
		.SIG_TRANSFER(SIG_TRANSFER), 
		.FF_LOAD(FF_LOAD), 
		.FF_TRANSFER(FF_TRANSFER), 
		.TEMPLATE_LOAD(TEMPLATE_LOAD), 
		.TEMPLATE_TRANSFER(TEMPLATE_TRANSFER), 
		.CYCLE_LOAD(CYCLE_LOAD), 
		.CYCLE_TRANSFER(CYCLE_TRANSFER), 
		.LEADING_EDGE_1(LEADING_EDGE_1), 
		.TRAILING_EDGE_1(TRAILING_EDGE_1), 
		.CYCLE_LENGTH_1(CYCLE_LENGTH_1), 
		.LEADING_EDGE_2(LEADING_EDGE_2), 
		.TRAILING_EDGE_2(TRAILING_EDGE_2), 
		.CYCLE_LENGTH_2(CYCLE_LENGTH_2), 
		.OUTPUT_SIGNALS(OUTPUT_SIGNALS)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		PERFORM_TEST = 0;
		BUS128_0 = 0;
		BUS128_1 = 0;
		SIG_LOAD = 0;
		SIG_TRANSFER = 0;
		FF_LOAD = 0;
		FF_TRANSFER = 0;
		TEMPLATE_LOAD = 0;
		TEMPLATE_TRANSFER = 0;
		CYCLE_LOAD = 0;
		CYCLE_TRANSFER = 0;
		LEADING_EDGE_1 = 0;
		TRAILING_EDGE_1 = 0;
		CYCLE_LENGTH_1 = 0;
		LEADING_EDGE_2 = 0;
		TRAILING_EDGE_2 = 0;
		CYCLE_LENGTH_2 = 0;

		// Wait 100 ns for global reset to finish
		#100;
		RST = 0;
		#100;
		
		LEADING_EDGE_1 = 20;
		LEADING_EDGE_2 = 40;
      
		TRAILING_EDGE_1 = 40;
		TRAILING_EDGE_2 = 60;
      
		CYCLE_LENGTH_1 = 80;
		CYCLE_LENGTH_2 = 120;
		
		// Load all registers, then inspect the outputs and see if they look OK.
		// Must be loaded and transfered before FF.
		BUS128_0 = 128'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE;
		#10;
		SIG_LOAD = 1;
		#10;
		SIG_LOAD = 0;
		#10;
		SIG_TRANSFER = 1;
		#10;
		SIG_TRANSFER = 0;
		#10;
		
		BUS128_0 = 128'h0;
		BUS128_1 = 128'h0;
		#10;
		FF_LOAD = 1;
		#10;
		FF_LOAD = 0;
		#10;
		
		BUS128_0 = 128'h0;
		TEMPLATE_LOAD = 1;
		#10;
		TEMPLATE_LOAD = 0;
		#10;
		
		BUS128_0 = 128'hAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
		#10;
		CYCLE_LOAD = 1;	
		#10;
		CYCLE_LOAD = 0;
		#10; 
		
		FF_TRANSFER = 1;
		CYCLE_TRANSFER = 1;
		TEMPLATE_TRANSFER = 1;
		#10;
		
		PERFORM_TEST = 1;
		#10;
		
		FF_TRANSFER = 0;
		CYCLE_TRANSFER = 0;
		TEMPLATE_TRANSFER = 0;
		#10000;
		
		// Load new signals and FF logic.
		PERFORM_TEST = 0;
		#10;
		
		BUS128_0 = 128'h00000000000000000000000000000001;
		#10;
		SIG_LOAD = 1;
		#10;
		SIG_LOAD = 0;
		#10;
		SIG_TRANSFER = 1;
		#10;
		SIG_TRANSFER = 0;
		#10;
		
		BUS128_0 = 128'h55555555555555555555555555555555;
		BUS128_1 = 128'h55555555555555555555555555555555;
		#10;
		FF_LOAD = 1;
		#10;
		FF_LOAD = 0;
		#10;
		FF_TRANSFER = 1;
		#10;
		FF_TRANSFER = 0;
		#10;
		
		PERFORM_TEST = 1;
		#10000;
		
		// Load new FF logic.
		PERFORM_TEST = 0;
		#10;
		
		BUS128_0 = 128'hAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
		#10;
		SIG_LOAD = 1;
		#10;
		SIG_LOAD = 0;
		#10;
		SIG_TRANSFER = 1;
		#10;
		SIG_TRANSFER = 0;
		#10;
		
		BUS128_0 = 128'hAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
		BUS128_1 = 128'hAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA;
		#10;
		FF_LOAD = 1;
		#10;
		FF_LOAD = 0;
		#10;
		FF_TRANSFER = 1;
		#10;
		FF_TRANSFER = 0;
		#10;
		
		PERFORM_TEST = 1;
		#10000;
		
		// Load new FF logic.
		PERFORM_TEST = 0;
		#10;
		
		BUS128_0 = 128'h55555555555555555555555555555555;
		#10;
		SIG_LOAD = 1;
		#10;
		SIG_LOAD = 0;
		#10;
		SIG_TRANSFER = 1;
		#10;
		SIG_TRANSFER = 0;
		#10;
		
		BUS128_0 = 128'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF;
		BUS128_1 = 128'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF;
		#10;
		FF_LOAD = 1;
		#10;
		FF_LOAD = 0;
		#10;
		FF_TRANSFER = 1;
		#10;
		FF_TRANSFER = 0;
		#10;
		
		PERFORM_TEST = 1;
		#10000;
		$finish;
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

