`timescale 1ns / 1ps

module LIMIT_GEN(SCALE, DUTY, HIGH_LEVEL_LIMIT, LOW_LEVEL_LIMIT);

// How much to scale down CLKSPEED by. For instance, if SCALE = 1, reduce CLKSPEED by half.
// Effectively, 2*SCALE is the number of clock cycles to count. These clock cycles make up the entire period.
input [6:0] SCALE;

// Duty cycle. Valid inputs are [0,100].
input [6:0] DUTY;

output [31:0] HIGH_LEVEL_LIMIT;
output [31:0] LOW_LEVEL_LIMIT;

assign HIGH_LEVEL_LIMIT = (SCALE << 1);
assign LOW_LEVEL_LIMIT = (SCALE << 1);

endmodule
