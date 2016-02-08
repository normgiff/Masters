`timescale 1ns / 1ps

/* 
 * Author: Daniel Khoury
 *
 * Generates a 1 MHz pulse from a 100 MHz input clock.
 */
module PULSE_GEN(CLK, RST, PULSE);
	input CLK;
	input RST;
	
	output reg PULSE;
	
	reg [6:0] counter;
	
	always@(posedge CLK) begin
		if(RST) begin
			counter <= 7'd0;
			PULSE <= 1'b0;
		end
		else begin
			if(counter == 7'd100) begin
				counter <= 7'd0;
				PULSE <= 1'b1;
			end
			else begin
				counter <= counter + 7'd1;
				PULSE <= 1'b0;
			end
		end
	end

endmodule
