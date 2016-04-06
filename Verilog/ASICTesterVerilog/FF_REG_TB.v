`timescale 1ns / 1ps

module FF_REG_TB;

	// Inputs
	reg CYCLE;
	reg D;
	reg [1:0] FF;

	// Outputs
	wire Q;

	// Instantiate the Unit Under Test (UUT)
	FF_REG uut (
		.CYCLE(CYCLE), 
		.D(D), 
		.FF(FF), 
		.Q(Q)
	);	
	
	initial begin
		// Initialize Inputs
		CYCLE = 0;
		D = 0;
		FF = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		// These tests assume the user specified the following:
		// Test cycle length: 100 ns
		// Leading edge offset: 40 ns
		// Trailing edge offset: 64 ns

		///////////////////////////////
		// R0 test
		///////////////////////////////
		FF = 2'b00;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 1;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		///////////////////////////////
		// R1 test
		///////////////////////////////
		FF = 2'b01;

		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 1;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		///////////////////////////////
		// DNRZ_L test
		///////////////////////////////
		FF = 2'b10;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 1;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 1;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		///////////////////////////////
		// DNRZ_T test
		///////////////////////////////
		FF = 2'b11;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 0;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 1;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
		D = 1;
		
		#40; 
		CYCLE = 1'b1;
		
		#24;
		CYCLE = 1'b0;
		
		#36;
		
	end
      
endmodule

