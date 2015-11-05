`timescale 1ns / 1ps

module CLOCK_GEN_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg INIT;
	reg [6:0] HIGH_LEVEL_LIMIT;
	reg [6:0] LOW_LEVEL_LIMIT;

	// Outputs
	wire OUT1;
	wire OUT2;

	// Instantiate the Unit Under Test (UUT)
	CLOCK_GEN uut (
		.CLK(CLK), 
		.RST(RST), 
		.INIT(INIT), 
		.HIGH_LEVEL_LIMIT(HIGH_LEVEL_LIMIT), 
		.LOW_LEVEL_LIMIT(LOW_LEVEL_LIMIT), 
		.OUT1(OUT1),
		.OUT2(OUT2) 
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		INIT = 0;
		HIGH_LEVEL_LIMIT = 0;
		LOW_LEVEL_LIMIT = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		RST = 0;
		INIT = 1;
		HIGH_LEVEL_LIMIT = 100;
		LOW_LEVEL_LIMIT = 100;
		#10000;
		
		INIT = 0;
		#10000;
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

