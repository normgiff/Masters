`timescale 1ns / 1ps

module FF_REG_TB;

	// Inputs
	reg RST;
	reg CLK;
	reg CLK_ENABLE;
	reg DATA;
	reg [1:0] FF;

	// Outputs
	wire OUT;

	// Instantiate the Unit Under Test (UUT)
	FF_REG uut (
		.RST(RST), 
		.CLK(CLK), 
		.CLK_ENABLE(CLK_ENABLE), 
		.DATA(DATA), 
		.FF(FF), 
		.OUT(OUT)
	);

	integer i, j;
	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 0;
		CLK_ENABLE = 0;
		DATA = 0;
		FF = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		RST = 1;
		#100;
		
		RST = 0;
		CLK_ENABLE = 1;
		#100;
		
		FF = 0;
		DATA = 1;
		#7;
		DATA = 0;
		#7;
		DATA = 1;
		#7;;
		DATA = 0;
		#7;
		DATA = 1;
		#7;
		
	end
	
	always begin
		CLK = ~CLK;
		#5;
	end
      
endmodule

