`timescale 1ns / 1ps

/* Initially, we planned to use external tristate buffers and template registers.
 * Using a two-layer PCB, however, proved inadequate to house 128 tristate buffer ICs, 
 * even with 60 square inches. 
 * Had we used external tristate buffers and template registers, we would output the data
 * with an ODDR2 module. Due to our design change, we attempt to mimic the behavior of the 
 * ODDR2 module instead.
 */
module DDR_REG(RST, EN, D0, D1, C0, C1, Q);
	input RST;
	input D0;
	input D1;
	input C0;
	input C1;
	
	output Q;
	
	// Internal wires.
	wire platch_out;
	wire nlatch_out;
	wire latch_out;
	
	// Positive latch.
	always@(C0) begin
		if (RST) begin
			platch_out = 1'b0;
		end
		else begin
			platch_out = D0;
		end
	end
	
	always@(C1) begin
		if (RST) begin
			nlatch_out = 1'b0;
		end
		else begin
			nlatch_out = D1;
		end
	end
	
	IOBUF #(
		.DRIVE(24), 				// Specify the output drive strength
		.IOSTANDARD("DEFAULT"), // Specify the I/O standard
		.SLEW("FAST") 				// Specify the output slew rate
	) IOBUF_inst (
		.O(O), 						// Buffer output
		.IO(IO), 					// Buffer inout port (connect directly to top-level port)
		.I(I), 						// Buffer input
		.T(EN) 						// 3-state enable input, high=input, low=output
	);

endmodule
