`timescale 1ns / 1ps

// Simple 2-to-1 mux.
module MUX21(SEL, A, B, OUT);
	input SEL;
	input A;
	input B;
	output OUT;
	
	assign OUT = SEL ? B : A;

endmodule
