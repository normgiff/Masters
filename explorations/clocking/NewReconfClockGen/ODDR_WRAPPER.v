`timescale 1ns / 1ps

module ODDR_WRAPPER(CLK_IN, RST, CLK_OUT);

// Global reset and "clock" generated from RECONF_PULSE_GEN.
input CLK_IN;
input RST;

// Output clock.
output CLK_OUT;

// ODDR: Output Double Data Rate Output Register with Set, Reset
// and Clock Enable.
// 7 Series
// Xilinx HDL Libraries Guide, version 13.1
ODDR #(
.DDR_CLK_EDGE("OPPOSITE_EDGE"), // "OPPOSITE_EDGE" or "SAME_EDGE"
.INIT(1'b0), // Initial value of Q: 1'b0 or 1'b1
.SRTYPE("SYNC") // Set/Reset type: "SYNC" or "ASYNC"
) ODDR_inst (
	.Q(CLK_OUT), // 1-bit DDR output
	.C(CLK_IN), // 1-bit clock input
	.CE(1'b1), // 1-bit clock enable input
	.D1(1'b1), // 1-bit data input (positive edge)
	.D2(1'b0), // 1-bit data input (negative edge)
	.R(RST), // 1-bit reset
	.S(1'b0) // 1-bit set
);
// End of ODDR_inst instantiation

endmodule
