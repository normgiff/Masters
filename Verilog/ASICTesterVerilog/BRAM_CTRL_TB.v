`timescale 1ns / 1ps

module BRAM_CTRL_TB;

	// Inputs
	reg CLK;
	reg RST;
	reg RESET_READ_COUNTER;
	reg INPUT_WRITE;
	reg TEMPLATE_WRITE;
	reg FF_WRITE;
	reg TC_WRITE;
	reg [127:0] WRITE_DATA;
	reg TEMPLATE_READ;
	reg [1:0] TEMPLATE_BITS;
	reg INPUT_READ;
	reg FF_READ;
	reg TC_READ;

	// Outputs
	wire [127:0] READ_DATA;
	wire TEMPLATE_CHANGE;
	wire READY;
 
	// Instantiate the Unit Under Test (UUT)
	BRAM_CTRL uut (
		.CLK(CLK), 
		.RST(RST), 
		.RESET_READ_COUNTER(RESET_READ_COUNTER),
		.INPUT_WRITE(INPUT_WRITE), 
		.TEMPLATE_WRITE(TEMPLATE_WRITE), 
		.FF_WRITE(FF_WRITE), 
		.TC_WRITE(TC_WRITE),
		.WRITE_DATA(WRITE_DATA), 
		.READ_DATA(READ_DATA), 
		.TEMPLATE_READ(TEMPLATE_READ), 
		.TEMPLATE_BITS(TEMPLATE_BITS), 
		.INPUT_READ(INPUT_READ), 
		.FF_READ(FF_READ), 
		.TC_READ(TC_READ),
		.TEMPLATE_CHANGE(TEMPLATE_CHANGE), 
		.READY(READY)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RST = 1;
		RESET_READ_COUNTER = 0;
		INPUT_WRITE = 0;
		TEMPLATE_WRITE = 0;
		FF_WRITE = 0;
		WRITE_DATA = 0;
		TEMPLATE_READ = 0;
		TEMPLATE_BITS = 0;
		INPUT_READ = 0;
		FF_READ = 0;
		TC_READ = 0;
		TC_WRITE = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		RST = 0;
		#100;
		
		// Write, then read a cycle vector
		// Associated with template 0
		WRITE_DATA = 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF;
		TC_WRITE = 1;
		#10;
		TC_WRITE = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		TEMPLATE_BITS = 0;
		TC_READ = 1;
		#10;
		TC_READ = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF) begin
			$display("READ_DATA should be %d, but is %d.\n", 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF, READ_DATA);
			$display("BAD CYCLE READ!!!");
		end
		
		// Write, then read a template
		// Template 0
		WRITE_DATA = 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF;
		TEMPLATE_WRITE = 1;
		#10;
		TEMPLATE_WRITE = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		TEMPLATE_BITS = 0;
		TEMPLATE_READ = 1;
		#10;
		TEMPLATE_READ = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF) begin
			$display("READ_DATA should be %d, but is %d.\n", 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF, READ_DATA);
		end
		
		// Write, then read a template
		// Template 3
		WRITE_DATA = 128'hC123FEEDDEADBEEF0123FEEDDEADBEEF;
		TEMPLATE_WRITE = 1;
		#10;
		TEMPLATE_WRITE = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		TEMPLATE_BITS = 3;
		TEMPLATE_READ = 1;
		#10;
		TEMPLATE_READ = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'hC123FEEDDEADBEEF0123FEEDDEADBEEF) begin
			$display("READ_DATA should be %d, but is %d.\n", 128'hC123FEEDDEADBEEF0123FEEDDEADBEEF, READ_DATA);
		end
		
		// Read the previous template at 0, make sure there is no conflict
		TEMPLATE_BITS = 0;
		TEMPLATE_READ = 1;
		#10;
		TEMPLATE_READ = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF) begin
			$display("READ_DATA should be %d, but is %d.\n", 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF, READ_DATA);
		end
		
		// Write a FF for template 3
		WRITE_DATA = 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF;
		FF_WRITE = 1;
		#10;
		FF_WRITE = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		// Read the FF for template 3
		TEMPLATE_BITS = 3;
		FF_READ = 1;
		#10;
		FF_READ = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF) begin
			$display("Incorrect FF read.\n");
		end
		
		// Write
		// Template 0
		WRITE_DATA = 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF;
		INPUT_WRITE = 1;
		#10;
		INPUT_WRITE = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		// Template 3
		WRITE_DATA = 128'hFEEDDEADBEEFEEEEDDDDCCCCBBBBAAAA;
		INPUT_WRITE = 1;
		#10;
		INPUT_WRITE = 0;
		#10;
		
		while (READY == 1'b0) begin
			#10;
		end
		
		// Read 
		INPUT_READ = 1;
		#10;
		INPUT_READ = 0;
		#10; 
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF) begin
			$display("READ_DATA should be %d, but is %d!\n", 128'h0123FEEDDEADBEEF0123FEEDDEADBEEF, READ_DATA);
		end
		
		INPUT_READ = 1;
		#10;
		INPUT_READ = 0;
		#10; 
		
		while (READY == 1'b0) begin
			#10;
		end
		
		if (READ_DATA != 128'hFEEDDEADBEEFEEEEDDDDCCCCBBBBAAAA) begin
			$display("READ_DATA should be %d, but is %d!\n", 128'hFEEDDEADBEEFEEEEDDDDCCCCBBBBAAAA, READ_DATA);
		end 
	end
	
	always begin
		CLK = #5 ~CLK;
	end
      
endmodule

