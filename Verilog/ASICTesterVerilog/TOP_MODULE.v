`timescale 1ns / 1ps

// Top Verilog module.
module TOP_MODULE(CLK, RST, 
						RX, TX,
						OE_BAR, 
						CS_BAR_1, WE_BAR_1,
						CS_BAR_2, WE_BAR_2,
						CS_BAR_3, WE_BAR_3,
						CS_BAR_4, WE_BAR_4, 
						COUNTER_CLK_1, COUNTER_CLK_2, COUNTER_CLK_3, COUNTER_CLK_4, 
						COUNTER_RST, 
						MR_BAR, PL_BAR, STCP, SHCP, Q,
						VT_EN,
						ERROR,
						SIGNALS);

	input CLK;
	input RST;
	
	// UART
	input RX;
	output TX;
	output ERROR;
	
	// SRAM
	output OE_BAR;
	output CS_BAR_1;
	output WE_BAR_1;
	output CS_BAR_2;
	output WE_BAR_2;
	output CS_BAR_3;
	output WE_BAR_3;
	output CS_BAR_4;
	output WE_BAR_4;
	
	// Counter
	output COUNTER_CLK_1;
	output COUNTER_CLK_2;
	output COUNTER_CLK_3;
	output COUNTER_CLK_4;
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
	output [125:0] SIGNALS;
	
	CENTRAL_FSM central_fsm0(CLK, RST, 
									 RX, TX,
									 OE_BAR, 
									 CS_BAR_1, WE_BAR_1,
									 CS_BAR_2, WE_BAR_2,
									 CS_BAR_3, WE_BAR_3,
									 CS_BAR_4, WE_BAR_4, 
									 COUNTER_CLK_1, COUNTER_CLK_2, COUNTER_CLK_3, COUNTER_CLK_4, 
									 COUNTER_RST, 
									 MR_BAR, PL_BAR, STCP, SHCP, Q,
									 VT_EN,
									 ERROR,
									 SIGNALS);

endmodule
