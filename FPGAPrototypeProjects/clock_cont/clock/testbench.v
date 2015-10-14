`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:24:47 10/01/2015 
// Design Name: 
// Module Name:    testbench 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module testbench;
	reg clk;
	wire clk_out0, clk_out1, clk_out2, clk_out3;
	reg [11:0] period0, period1, period2, period3;
	reg [3:0] duty0, duty1, duty2, duty3;
	clocks clk0(.clk(clk), .period(period0), .period1(period1), .period2(period2), .period3(period3), 
								  .duty(duty0), .duty1(duty1), .duty2(duty2), .duty3(duty3), 
								  .clk0(clk_out0), .clk1(clk_out1), .clk2(clk_out2), .clk3(clk_out3));
	
	always #1 clk = ~clk;
	initial 
	begin
		clk = 0;
		period0 = 4'b0011;
		duty0 = 4'b0011;
		period1 = 4'b0011;
		duty1 = 4'b0011;
		period2 = 4'b0011;
		duty2 = 4'b0011;
		period3 = 4'b0011;
		duty3 = 4'b0011;
		//#100
		//period0 = 4'b0011;
		//duty0 = 4'b0001;
		//#100
		//period0 = 4'b0011;
		//duty0 = 4'b0010;
		//#100
		//period0 = 4'b0011;
		//duty0 = 4'b0011;
		//#100
		//period0 = 4'b0011;
		//duty0 = 4'b0100;
		//#100
		//period0 = 4'b0011;
		//duty0 = 4'b0101;
		//#100
		//period0 = 4'b0011;
		//duty0 = 4'b0110;
	end
endmodule
