`timescale 1ns / 1ps

module TOP_MODULE_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg RX;
	reg Q;

	// Outputs
	wire TX;
	wire OE_BAR;
	wire CS_BAR;
	wire WE_BAR;
	wire COUNTER_CLK;
	wire COUNTER_RST;
	wire MR_BAR;
	wire PL_BAR;
	wire STCP;
	wire SHCP;
	wire VT_EN;
	wire [127:0] SIGNALS;

	// Instantiate the Unit Under Test (UUT)
	TOP_MODULE uut (
		.CLK(CLK), 
		.RST(RST), 
		.RX(RX), 
		.TX(TX), 
		.OE_BAR(OE_BAR), 
		.CS_BAR(CS_BAR), 
		.WE_BAR(WE_BAR), 
		.COUNTER_CLK(COUNTER_CLK), 
		.COUNTER_RST(COUNTER_RST), 
		.MR_BAR(MR_BAR), 
		.PL_BAR(PL_BAR), 
		.STCP(STCP), 
		.SHCP(SHCP), 
		.Q(Q), 
		.VT_EN(VT_EN), 
		.SIGNALS(SIGNALS)
	);

	integer i;
	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		RX = 1;
		Q = 0;

		// Wait 100 ns for global reset to finish
		#100;
		RST = 0;
		#100;
		
		/////////////////////////////////////////
		// Load cycle configuration data.
		/////////////////////////////////////////
		
		// Transmit an input header.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 3) RX = 1;
				else RX = 0;
			end
			else if (i > 10 && i < 19) begin
				if (i == 14) RX = 1;
				else RX = 0;
			end
			else if (i > 20 && i < 29) begin
				if (i == 24) RX = 1;
				else if (i == 21) RX = 1;
				else RX = 0;
			end
			else if (i > 30 && i < 39) begin
				if (i == 34) RX = 1;
				else if (i == 32) RX = 1;
				else RX = 0;
			end
			else if (i > 40 && i < 49) begin
				if (i <= 44) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8680;
		end
		RX = 1;
		
		// Wait 2 milliseconds for an acknowledgement.
		#2000000;
        
		/////////////////////////////////////////
		// Load three input vectors.
		// The first two have the same template, 
		// the third has a different template.
		/////////////////////////////////////////
		
		// Transmit an input header.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 1) RX = 1;
				else if (i == 2) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8680;
		end
		RX = 1;
		
		// Wait 2 milliseconds before we send the template vector.
		#2000000;
		
		// Transmit an input vector.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				if (i == 158) RX = 1;
				else if (i == 157) RX = 1;
				else RX = i; // Send a mix of zeroes and ones.
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds before proceeding.
		#2000000;
		
				// Transmit an input header.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 1) RX = 1;
				else if (i == 2) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8680;
		end
		RX = 1;
		
		// Wait 2 milliseconds before we send the template vector.
		#2000000;
		
		// Transmit an input vector (data bits flipped but same header).
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				if (i == 158) RX = 1;
				else if (i == 157) RX = 1;
				else RX = ~i; // Send a mix of zeroes and ones.
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds before proceeding.
		#2000000;
		
		// Transmit another input header.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 1) RX = 1;
				else if (i == 2) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds before we send the template vector.
		#2000000;
		
		// Transmit another input vector.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				if (i == 158) RX = 0;
				else if (i == 157) RX = 0;
				else RX = i; // Send a mix of zeroes and ones.
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds before proceeding.
		#2000000;
		
		// Perform a test. What happens?
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 1) RX = 1;
				else if (i == 3) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds.
		#2000000;
		
		// Perform the test again. What happens?
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 1) RX = 1;
				else if (i == 3) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds.
		#2000000;
		
		// Request data.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 2) RX = 1;
				else if (i == 3) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds.
		#2000000;
		
		// Request data again.
		for (i = 0; i < 160; i = i + 1) begin
			if ((i % 10) == 0) begin
				RX = 0;
			end
			else if (i > 0 && i < 9) begin
				if (i == 2) RX = 1;
				else if (i == 3) RX = 1;
				else RX = 0;
			end
			else if ((i & 32'h00000009) == 32'h00000009) begin // Last digit of i is 9.
				RX = 1;
			end
			else begin
				RX = 1;
			end
			#8670;
		end
		RX = 1;
		
		// Wait 2 milliseconds.
		#2000000;
		
		$finish;
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

