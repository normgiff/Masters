`timescale 1ns / 1ps

module LIMIT_GEN_TB;

	// Inputs
	reg [6:0] SCALE;
	reg [6:0] DUTY;

	// Outputs
	wire [31:0] HIGH_LEVEL_LIMIT;
	wire [31:0] LOW_LEVEL_LIMIT;

	// Instantiate the Unit Under Test (UUT)
	LIMIT_GEN uut (
		.SCALE(SCALE), 
		.DUTY(DUTY), 
		.HIGH_LEVEL_LIMIT(HIGH_LEVEL_LIMIT), 
		.LOW_LEVEL_LIMIT(LOW_LEVEL_LIMIT)
	);

	initial begin
		
		// Expected: 25 MHz clock, 50 percent duty cycle.
		SCALE = 2;
		DUTY = 32;
		#100000;
		
	end
      
endmodule

