`timescale 1ns / 1ps

module TRIREG_DB;

	// Inputs
	reg I;
	reg EN_BAR;

	// Outputs
	wire O;

	// Instantiate the Unit Under Test (UUT)
	TRIREG uut (
		.I(I), 
		.O(O), 
		.EN_BAR(EN_BAR)
	);

	initial begin
		// Initialize Inputs
		I = 0;
		EN_BAR = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Ensure that when EN_BAR = 1, output is 1'bz.
		EN_BAR = 1;
		#100; 
		
	end
      
endmodule

