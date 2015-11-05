`timescale 1ns / 1ps

/* 
 * 
 */
module SYNCHRONIZER(CLK1, CLK2, CLK3, CLK4, PROCEED);

input CLK1, CLK2, CLK3, CLK4;

output PROCEED;

assign PROCEED = CLK1 && CLK2 && CLK3 && CLK4;

endmodule
