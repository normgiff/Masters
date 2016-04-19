`timescale 1ns / 1ps

module OUTPUT_BUFFER_CTRL_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg CLEAR_BUFFER;
	reg CAPTURE_SRAM_DATA;
	reg Q;

	// Outputs
	wire READY;
	wire [127:0] SRAM_DATA;
	wire MR_BAR;
	wire PL_BAR;
	wire SHCP;
	wire STCP;

	// Instantiate the Unit Under Test (UUT)
	OUTPUT_BUFFER_CTRL uut (
		.CLK(CLK), 
		.RST(RST), 
		.CLEAR_BUFFER(CLEAR_BUFFER), 
		.CAPTURE_SRAM_DATA(CAPTURE_SRAM_DATA), 
		.READY(READY), 
		.SRAM_DATA(SRAM_DATA), 
		.Q(Q), 
		.MR_BAR(MR_BAR), 
		.PL_BAR(PL_BAR), 
		.SHCP(SHCP), 
		.STCP(STCP)
	);

	integer i;
	initial begin
		// Initialize Inputs
		i = 1;
		CLK = 0;
		RST = 1;
		CLEAR_BUFFER = 0;
		CAPTURE_SRAM_DATA = 0;
		Q = 0;

		// Wait 100 ns for global reset to finish
		#100;
		RST = 0;
		#100;
        
		// Reset buffer.
		CLEAR_BUFFER = 1;
		#10;
		CLEAR_BUFFER = 0;
		#10;
		while (READY != 1'b1) begin
			#10;
		end
		
		// Try capturing SRAM data.
		CAPTURE_SRAM_DATA = 1;
		#10;
		CAPTURE_SRAM_DATA = 0;
		#10;
		while (READY == 1'b0) begin
			#10;
		end
		
		// Inspect captured data.
		#100;
		
	end
	
	always@(posedge SHCP) begin
		i = ~i;
		Q = #1 i;
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

