`timescale 1ns / 1ps

/*
 * PROTOCOL FOR BBB-FPGA COMMUNICATION
 * 
 * Codes that the BBB sends to the FPGA: 
 * 000000XX: The next 16 bytes (128 bits) that the BBB will send are 
 *           the template bits for template XX.
 *           Note: A "template bit" indicates whether an FPGA pin is 
 *           an input to the DUT or not. In other words, a template bit
 *           is just the enable bit for an FPGA pin's tristate buffer.
 * 000001XX: The next 32 bytes (256 bits) that the BBB will send are 
 *           the force-format configurations for template XX.
 *           Note: Recall that there are four force-format options: 
 *           	R0 | 00 == Force signal when test cycle is high, return to zero otherwise.
 * 				R1 | 01 == Force signal when test cycle is high, return to one otherwise.
 * 				DNRZ_L | 10 == Force signal on leading edge, hold until next leading edge.
 * 				DRNZ_T | 11 == Force signal on trailing edge, hold until next trailing edge.
 * 000010XX: The next 16 bytes that the BBB will send indicate whether a signal belongs 
 *           to the "first" test cycle or the "second" test cycle (for template XX).
 *           Note: A single test can comprise up to two test cycles.
 *           Note: By default, we assume that all signals belong to the "first" test cycle.
 * 000011XX: The next 16 bytes are an input vector for template XX. 
 * 			 Note: The FPGA will keep track of the ordering of input vectors and what 
 *                 template they are associated with.
 *			    Note: The BBB must send the input vectors in the order that they appear
 *                 in the test file.
 * 00010YXX: The next three bytes that the BBB will send are the "count" for the leading edge,
 *           the "count" for the trailing edge, and the test cycle length for test cycle Y, 
 *           template XX. The FPGA will likely run off a 100 MHz clock (10 nanoseconds).
 *           Example: If the BBB sends the following: 
 *           00100000 00001111 00011110 00111100
 *           Then for the "first" test cycle, the leading edge is at 15*10 ns = 150 ns,
 *           the trailing edge is at 30*10 ns = 300 ns, and the length of a test cycle is 
 *           60*10 = 600 ns. (Test cycle frequency would therefore be about 1.6 MHz.)
 * 00110000: The FPGA should perform its tests. 
 * 01000000: The FPGA should repeat the test that it just performed.
 *           (This code should be used for schmooing.)
 * 01010000: The FPGA should send one output vector back to the BBB.
 *           Note: The BBB needs to invoke this command as many times as there are input 
 *           vectors. 
 * 01100000: The FPGA should perform a soft reset to prepare itself for a new chip.
 *           (A user can also manually reset the FPGA with a push button.)
 * 
 * Codes that the FPGA can send to the BBB: 
 * 00000000: Acknowledgement and completion of command received.
 * 11111111: Unknown command received. 
 * 
 */
module UART_CTRL(CLK, RST, 
					  RX, RXDATA_READY, RXDATA_RETRIEVED, RXDATA, 
					  TX, TXDATA, TXCAPTURE, TXTRANSMIT, TXSENT, TXACK, ERROR);
	
	input CLK;
	input RST;
	
	input RX;
	input RXDATA_RETRIEVED;
	output RXDATA_READY;
	output [127:0] RXDATA;
	
	input [127:0] TXDATA;
	input TXCAPTURE;
	input TXTRANSMIT;
	input TXACK;
	output TX;
	output TXSENT;
	output ERROR;
	
	UART_RX uart_rx0(.CLK(CLK), .RST(RST), .RX(RX), .DATA_READY(RXDATA_READY), 
						  .DATA_RETRIEVED(RXDATA_RETRIEVED), .DATA(RXDATA));
	UART_TX uart_tx0(.CLK(CLK), .RST(RST), .TX(TX), .DATA(TXDATA), 
						  .CAPTURE(TXCAPTURE), .TRANSMIT(TXTRANSMIT), .SENT(TXSENT), 
						  .ACKNOWLEDGE(TXACK), .ERROR(ERROR));

endmodule
