`timescale 1ns / 1ps

// This module exists just to see if the Spartan-6 has enough resources for the BRAM 
// controller. The connections are junk.
//
// 04/08: The parameters defined in BRAM_CTRL_PARAMS.v are taking up too many LUTs.
// 04/08: BRAM was too large (not sure why the BRAM.v module synthesized originally).
//        Logic is not too large now.
module BRAM_CTRL_WRAPPER_TEST(CLK, RST, INPUT_WRITE, TEMPLATE_WRITE, FF_WRITE,
									   TEMPLATE_READ, INPUT_READ, FF_READ, READ_DATA_0, JUNK);
	input CLK;
	input RST;
	input INPUT_WRITE;
	input TEMPLATE_WRITE;
	input FF_WRITE;
	input TEMPLATE_READ;
	input INPUT_READ;
	input FF_READ;
	output [127:0] READ_DATA_0;
	output reg JUNK;
	
	// Fake buses.
	reg [1:0] TEMPLATE_BITS;
	wire [127:0] READ_DATA_1;
	reg [127:0] WRITE_DATA_0;
	reg [127:0] WRITE_DATA_1;
	
	// Junk logic to avoid optimization/trimming.
	always@(*) begin 
		WRITE_DATA_0 = 128'd0;
		WRITE_DATA_1 = 128'd0;
		if (INPUT_WRITE) begin
			WRITE_DATA_0 = READ_DATA_0;
		end
		else begin
			WRITE_DATA_1 = READ_DATA_1;
		end
		JUNK = WRITE_DATA_0 || WRITE_DATA_1;
		TEMPLATE_BITS = {READY, TEMPLATE_CHANGE};
	end

	BRAM_CTRL bram_ctrl0(CLK, RST, INPUT_WRITE, TEMPLATE_WRITE, FF_WRITE, WRITE_DATA_0, WRITE_DATA_1,
					  READ_DATA_0, READ_DATA_1, TEMPLATE_READ, TEMPLATE_BITS, INPUT_READ, FF_READ,
					  TEMPLATE_CHANGE, READY);		
endmodule
