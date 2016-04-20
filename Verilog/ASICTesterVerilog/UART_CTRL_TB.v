`timescale 1ns / 1ps

module UART_CTRL_TB;

	// Inputs
	reg CLK;
	reg RST;
	//reg RX;
	reg RXDATA_RETRIEVED;
	reg [127:0] TXDATA;
	reg TXCAPTURE;
	reg TXTRANSMIT;
	reg TXACK;

	// Outputs
	wire RXDATA_READY;
	wire [127:0] RXDATA;
	wire TX;
	wire TXSENT;

	// Instantiate the Unit Under Test (UUT)
	UART_CTRL uut (
		.CLK(CLK), 
		.RST(RST), 
		.RX(TX), // Read what TX sends out.
		.RXDATA_READY(RXDATA_READY), 
		.RXDATA_RETRIEVED(RXDATA_RETRIEVED), 
		.RXDATA(RXDATA), 
		.TX(TX), 
		.TXDATA(TXDATA), 
		.TXCAPTURE(TXCAPTURE), 
		.TXTRANSMIT(TXTRANSMIT), 
		.TXSENT(TXSENT), 
		.TXACK(TXACK)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		RXDATA_RETRIEVED = 0;
		TXDATA = 0;
		TXCAPTURE = 0;
		TXTRANSMIT = 0;
		TXACK = 0;

		// Wait 100 ns for global reset to finish
		#100;
		RST = 0;
		#100;
        
		// Add stimulus here
		// Ensure that the first and last four 1's are sent!
		TXDATA = 128'hF000000000000000000000000000000F;
		#10;
		TXCAPTURE = 1;
		#10;
		TXCAPTURE = 0;
		#10;
		TXTRANSMIT = 1;
		#10;
		TXTRANSMIT = 0;
		#10;
		
		while (TXSENT == 1'b0) begin
			#10;
		end
		
		while (RXDATA_READY == 1'b0) begin
			#10;
		end
		
		$finish;

	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

