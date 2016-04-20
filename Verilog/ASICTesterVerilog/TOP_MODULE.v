`timescale 1ns / 1ps

// Top Verilog module.
module TOP_MODULE(CLK, RST, 
						RX, TX,
						OE_BAR, CS_BAR, WE_BAR, 
						COUNTER_CLK, COUNTER_RST, 
						MR_BAR, PL_BAR, STCP, SHCP, Q,
						VT_EN,
						SIGNALS);

	input CLK;
	input RST;
	
	// UART
	input RX;
	output TX;
	
	// SRAM
	output OE_BAR;
	output CS_BAR;
	output WE_BAR;
	
	// Counter
	output COUNTER_CLK;
	output COUNTER_RST;
	
	// Output buffers (parallel->serial shift registers)
	output MR_BAR;
	output PL_BAR;
	output STCP;
	output SHCP;
	input Q;
	
	// Voltage translators
	output VT_EN;
	
	// DUT signals
	output [127:0] SIGNALS;
	
	CENTRAL_FSM central_fsm0(CLK, RST, 
									 RX, TX,
									 OE_BAR, CS_BAR, WE_BAR, 
									 COUNTER_CLK, COUNTER_RST, 
									 MR_BAR, PL_BAR, STCP, SHCP, Q,
									 VT_EN,
									 SIGNALS);

endmodule
