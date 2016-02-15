`timescale 1ns / 1ps

module TOP_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg INIT;
	reg [7:0] SEED;

	// Outputs
	wire COUNTER_CLK;
	wire COUNTER_RST;
	wire WE_BAR;
	wire [15:0] LED_OUT;

	// Bidirs
	wire [3:0] CHIP1_DATA;
	wire [3:0] CHIP2_DATA;

	// Instantiate the Unit Under Test (UUT)
	TOP uut (
		.CLK(CLK), 
		.RST(RST), 
		.INIT(INIT), 
		.SEED(SEED), 
		.COUNTER_CLK(COUNTER_CLK), 
		.COUNTER_RST(COUNTER_RST), 
		.WE_BAR(WE_BAR), 
		.CHIP1_DATA(CHIP1_DATA), 
		.CHIP2_DATA(CHIP2_DATA), 
		.LED_OUT(LED_OUT)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		INIT = 0;
		SEED = 23;

		// Wait 1000 ns for global reset to finish
		#1000;
		
		// Initialize!
		RST = 0;
		INIT = 1;
		#100000000;
		
		$finish;
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

