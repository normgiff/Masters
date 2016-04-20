`timescale 1ns / 1ps


module CENTRAL_FSM(CLK, RST, 
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
	
	// Signals to DUT
	output [127:0] SIGNALS;
	
	// States
	parameter IDLE = 0;
	parameter DECODE_UART_CODE = 1;
	parameter STORE_TEMPLATE_VECTOR = 2;
	parameter ACCUMULATE_FF_VECTOR_1 = 3;
	parameter ACCUMULATE_FF_VECTOR_2 = 4;
	parameter STORE_FF_VECTOR = 5;
	parameter ACCUMULATE_CYCLE_VECTOR = 5;
	parameter STORE_CYCLE_VECTOR = 6;
	parameter ACCUMULATE_INPUT_VECTOR = 7;
	parameter STORE_INPUT_VECTOR = 8;
	parameter STORE_CYCLE_ATTRIBUTES = 9;
	parameter PERFORM_TESTS = 10;
	parameter SWITCH_TEMPLATE_1 = 11;
	parameter SWITCH_TEMPLATE_2 = 12;
	parameter SWITCH_TEMPLATE_3 = 13;
	parameter SWITCH_TEMPLATE_4 = 14;
	parameter FETCH_OUTPUT_VECTOR = 15;
	parameter TRANSMIT_OUTPUT_VECTOR = 16;
	parameter PERFORM_SOFT_RESET = 17;
	parameter TRANSMIT_UART_CODE = 18;
	
	// GOAL: Code this entirely by end-of-day Wednesday.
	
endmodule
