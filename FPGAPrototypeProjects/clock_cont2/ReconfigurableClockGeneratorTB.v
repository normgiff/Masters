`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:08:14 10/14/2015
// Design Name:   ReconfigurableClockGenerator
// Module Name:   C:/Users/dkhoury/OneDrive/Documents/Masters/FPGAPrototypeProjects/clock_cont2/ReconfigurableClockGeneratorTB.v
// Project Name:  clock_cont2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ReconfigurableClockGenerator
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ReconfigurableClockGeneratorTB;

	// Inputs
	reg CLK_IN;
	reg RST;
	reg [3:0] PERIOD;
	reg [1:0] DUTY;

	// Outputs
	wire CLK_OUT;

	// Instantiate the Unit Under Test (UUT)
	ReconfigurableClockGenerator uut (
		.CLK_IN(CLK_IN), 
		.RST(RST), 
		.PERIOD(PERIOD), 
		.DUTY(DUTY), 
		.CLK_OUT(CLK_OUT)
	);
	
	always begin
	#5 CLK_IN = ~CLK_IN;
	end

	initial begin
		// Initialize inputs, reset circuit
		CLK_IN = 0;
		RST = 1;
		PERIOD = 0;
		DUTY = 0;
		#100;
		RST = 0;
		#100;
        
		// Add stimulus here
		DUTY = 2'b0;
		PERIOD = 4'd2;
		#1000;
		
		DUTY = 2'd1;
		PERIOD = 4'd2;
		#1000;
		
		DUTY = 2'd2;
		PERIOD = 4'd2;
		#1000;
		
		DUTY = 2'd3;
		PERIOD = 4'd2;
		#1000;
	end
      
endmodule

