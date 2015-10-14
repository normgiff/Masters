`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:50:52 10/12/2015 
// Design Name: 
// Module Name:    clocks 
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
module clocks(clk, period, period1, period2, period3, 
						 clk0, clk1, clk2, clk3, 
						 duty, duty1, duty2, duty3);
	input clk;
	output clk0, clk1, clk2, clk3;
	input [3:0] period, period1, period2, period3;
	input [1:0] duty, duty1, duty2, duty3;
	
	clock clock0(.clk(clk), .period(period), .duty(duty), .clk_out(clk0));
	clock clock1(.clk(clk), .period(period1), .duty(duty1), .clk_out(clk1));
	clock clock2(.clk(clk), .period(period2), .duty(duty2), .clk_out(clk2));
	clock clock3(.clk(clk), .period(period3), .duty(duty3), .clk_out(clk3));

endmodule
