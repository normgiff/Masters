`timescale 1ns / 1ps

module CLOCK_MUX(SEL, OUT);

input SEL;

output OUT;

BUFGMUX BUFGMUX_inst 
(
.O(OUT),
.I0(1'b0),
.I1(1'b1),
.S(SEL)
);

endmodule
