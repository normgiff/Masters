`timescale 1ns / 1ps

module CLK_WIZ_V3_6_TB;

	// Inputs
	reg CLK_IN;
	reg RESET;

	// Outputs
	wire CLK_OUT;
	wire LOCKED;

	// Instantiate the Unit Under Test (UUT)
	clk_wiz_v3_6 uut (
		.CLK_IN(CLK_IN), 
		.CLK_OUT(CLK_OUT), 
		.RESET(RESET), 
		.LOCKED(LOCKED)
	);

	initial begin
		// Initialize Inputs
		CLK_IN = 0;
		RESET = 1;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		RESET = 0;
		#100;
	end
	
	always begin
		// Simulates 100 MHz input clock.
		CLK_IN = #5 ~CLK_IN;
	end
      
endmodule

