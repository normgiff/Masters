`timescale 1ns / 1ps

module UART_CTRL_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg RX;
	reg RXDATA_RETRIEVED;
	reg [7:0] TXDATA;
	reg TXCAPTURE;
	reg TXTRANSMIT;

	// Outputs
	wire RXDATA_READY;
	wire [7:0] RXDATA;
	wire TX;
	wire TXSENT;

	// Instantiate the Unit Under Test (UUT)
	UART_CTRL uut (
		.CLK(CLK), 
		.RST(RST), 
		.RX(RX), 
		.RXDATA_READY(RXDATA_READY), 
		.RXDATA_RETRIEVED(RXDATA_RETRIEVED), 
		.RXDATA(RXDATA), 
		.TX(TX), 
		.TXDATA(TXDATA), 
		.TXCAPTURE(TXCAPTURE), 
		.TXTRANSMIT(TXTRANSMIT), 
		.TXSENT(TXSENT)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 0;
		RX = 0;
		RXDATA_RETRIEVED = 0;
		TXDATA = 0;
		TXCAPTURE = 0;
		TXTRANSMIT = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		RST = 1;
		#100;
		RST = 0;
		#100;
		
		TXDATA = 8'b10101010;
		#100;
		TXCAPTURE = 1;
		#100;
		TXCAPTURE = 0;
		#100;
		TXTRANSMIT = 1;
		#100;
		TXTRANSMIT = 0;
		#100;
		
		RX = 0;
		#8680;
		RX = 1;
		#8680;
		RX = 1;
		#8680;
		RX = 0;
		#8680;
		RX = 0;
		#8680;
		RX = 1;
		#8680;
		RX = 0;
		#8680;
		RX = 0;
		#8680;
		RX = 1;
		#8680;
		RX = 0;
		#8680;
		
		
		#1000;
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

