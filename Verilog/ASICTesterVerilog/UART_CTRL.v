`timescale 1ns / 1ps

/* 
 * Module: UART_CTRL
 * Function:    For BBB-FPGA communication.
 *              See UART_RX and UART_TX modules for more information.
 * 
 * Codes that the BBB can send to the FPGA (least-significant byte): 
 * 8'b00000000: The next 16 bytes are a template vector.
 * 8'b00000001: The next 16 bytes are a force-format vector.
 * 8'b00000010: The next 16 bytes are a cycle vector.
 * 8'b00000011: The next 16 bytes are an input vector.
 * 8'b00000100: The next 16-byte transfer's last four bytes are: 
 *              DELAY 1 (i.e. LEADING EDGE 1), DELAY 2 (i.e. LEADING EDGE 2), 
 *              WIDTH (i.e. TRAILING EDGE), LENGTH (i.e. cycle length).
 * 8'b00000101: The FPGA should execute all input vectors.
 * 8'b00000110: The FPGA should send back the SRAM contents at the current counter address,
 *              then increment the counter.
 *              Note that the FPGA resets the counter after executing all input vectors.
 */
module UART_CTRL(CLK, RST, 
					  RX, RXDATA_READY, RXDATA_RETRIEVED, RXDATA, 
					  TX, TXDATA, TXCAPTURE, TXTRANSMIT, TXSENT, TXACK);
	
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
	
	UART_RX uart_rx0(.CLK(CLK), .RST(RST), .RX(RX), .DATA_READY(RXDATA_READY), 
						  .DATA_RETRIEVED(RXDATA_RETRIEVED), .DATA(RXDATA));
	
	UART_TX uart_tx0(.CLK(CLK), .RST(RST), .TX(TX), .DATA(TXDATA), 
						  .CAPTURE(TXCAPTURE), .TRANSMIT(TXTRANSMIT), .SENT(TXSENT), 
						  .ACKNOWLEDGE(TXACK));

endmodule
