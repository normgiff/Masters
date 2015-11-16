`timescale 1ns / 1ps

module CLOCK_GEN(CLK, RST, INIT, HIGH_LEVEL_LIMIT, LOW_LEVEL_LIMIT, OUT1, OUT2, OUT3, OUT4);

// Global clock and reset.
input CLK;
input RST;

// From BeagleBone Black.
input INIT;
input [6:0] HIGH_LEVEL_LIMIT;
input [6:0] LOW_LEVEL_LIMIT;
wire [6:0] DELAY_LIMIT = 7'd0;

// Output clock signal.
output OUT1;
output OUT2;
output OUT3;
output OUT4;

// Internal wires.
wire global_clk;
wire clk1_ready;
wire clk1_sel;
wire clk2_ready;
wire clk2_sel;
wire clk3_ready;
wire clk3_sel;
wire clk4_ready;
wire clk4_sel;
wire global_proceed;
wire clk1_mux_out;
wire clk2_mux_out;
wire clk3_mux_out;
wire clk4_mux_out;

// TODO: Figure out what the "LOCKED" signal is for. Is it useful?
// Right now, the global clock signal is configured to be 250 MHz (granularity of 4 ns).
// On a Spartan-6, it doesn't look like we can do much better than that.
CLK_MULTIPLIER CLK_MULTIPLIER_0(.CLK_IN(CLK), .CLK_OUT(global_clk), .RESET(RST));

SYNCHRONIZER SYNCHRONIZER_0(.CLK(global_clk), .RST(RST), .CLK1(clk1_ready), .CLK2(clk2_ready), .CLK3(1'b1), .CLK4(1'b1), .PROCEED(global_proceed));

RECONF_PULSE_GEN RECONF_PULSE_GEN_0(.CLK(global_clk), 
												.RST(RST), 
												.INIT(INIT), 
												.PROCEED(global_proceed), 
												.HIGH_LEVEL_LIMIT(HIGH_LEVEL_LIMIT), 
												.LOW_LEVEL_LIMIT(LOW_LEVEL_LIMIT),
												.DELAY_LIMIT(7'd0),
												.READY(clk1_ready), 
												.SEL(clk1_sel));
												
RECONF_PULSE_GEN RECONF_PULSE_GEN_1(.CLK(global_clk), 
												.RST(RST), 
												.INIT(INIT), 
												.PROCEED(global_proceed), 
												.HIGH_LEVEL_LIMIT(HIGH_LEVEL_LIMIT), 
												.LOW_LEVEL_LIMIT(LOW_LEVEL_LIMIT),
												.DELAY_LIMIT(7'd5),
												.READY(clk2_ready), 
												.SEL(clk2_sel));

											
RECONF_PULSE_GEN RECONF_PULSE_GEN_2(.CLK(global_clk), 
												.RST(RST), 
												.INIT(INIT), 
												.PROCEED(global_proceed), 
												.HIGH_LEVEL_LIMIT(HIGH_LEVEL_LIMIT), 
												.LOW_LEVEL_LIMIT(LOW_LEVEL_LIMIT),
												.DELAY_LIMIT(7'd2),
												.READY(clk3_ready), 
												.SEL(clk3_sel));
												
RECONF_PULSE_GEN RECONF_PULSE_GEN_3(.CLK(global_clk), 
												.RST(RST), 
												.INIT(INIT), 
												.PROCEED(global_proceed), 
												.HIGH_LEVEL_LIMIT(HIGH_LEVEL_LIMIT), 
												.LOW_LEVEL_LIMIT(LOW_LEVEL_LIMIT),
												.DELAY_LIMIT(7'd3),
												.READY(clk4_ready), 
												.SEL(clk4_sel));

												
CLOCK_MUX CLOCK_MUX_0(.SEL(clk1_sel), .OUT(clk1_mux_out));

CLOCK_MUX CLOCK_MUX_1(.SEL(clk2_sel), .OUT(clk2_mux_out));

CLOCK_MUX CLOCK_MUX_2(.SEL(clk3_sel), .OUT(clk3_mux_out));

CLOCK_MUX CLOCK_MUX_3(.SEL(clk4_sel), .OUT(clk4_mux_out));

ODDR_WRAPPER ODDR_WRAPPER_0(.CLK_IN(clk1_mux_out), .RST(RST), .CLK_OUT(OUT1));

ODDR_WRAPPER ODDR_WRAPPER_1(.CLK_IN(clk2_mux_out), .RST(RST), .CLK_OUT(OUT2));

ODDR_WRAPPER ODDR_WRAPPER_2(.CLK_IN(clk3_mux_out), .RST(RST), .CLK_OUT(OUT3));

ODDR_WRAPPER ODDR_WRAPPER_3(.CLK_IN(clk4_mux_out), .RST(RST), .CLK_OUT(OUT4));

endmodule
