`timescale 1ns / 1ps

module FF_REG_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg EN;
	reg [6:0] LEADING_EDGE;
	reg [6:0] TRAILING_EDGE;
	reg [7:0] CYCLE_LENGTH;
	reg D;
	reg [1:0] FF;

	// Outputs
	wire Q;

	// Instantiate the Unit Under Test (UUT)
	FF_REG uut (
		.CLK(CLK), 
		.RST(RST), 
		.EN(EN),
		.LEADING_EDGE(LEADING_EDGE), 
		.TRAILING_EDGE(TRAILING_EDGE), 
		.CYCLE_LENGTH(CYCLE_LENGTH), 
		.D(D), 
		.FF(FF), 
		.Q(Q)
	);	

	integer i;
	integer j;
	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		EN = 0;
		LEADING_EDGE = 0;
		TRAILING_EDGE = 0;
		CYCLE_LENGTH = 0;
		D = 0;
		FF = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		// Add stimulus here
		RST = 0;		
		LEADING_EDGE = 5;
		TRAILING_EDGE = 10;
		CYCLE_LENGTH = 15;
		#100;
		
		EN = 1;
		for (i = 0; i < 4; i = i + 1) begin
			FF = i;
			for (j = 0; j < 2; j = j + 1) begin
				D = j;					
				#500;
			end
			EN = 0;
			#1000;
			EN = 1;
		end

	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

