`timescale 1ns / 1ps

/* 
 * Used to synchronize when the clocks begin outputting signals.
 */
module SYNCHRONIZER(CLK, RST, CLK1, CLK2, CLK3, CLK4, PROCEED);

input CLK, RST;
input CLK1, CLK2, CLK3, CLK4;

output reg PROCEED;

reg [9:0] counter;

always@(posedge CLK) begin
	if (RST) begin
		PROCEED <= 1'b0;
		counter <= 9'd0;
	end
	else begin
		if (counter < 10'd1000) begin
			counter <= counter + 10'd1;
			PROCEED <= 1'b0;
		end
		else begin
			PROCEED <= CLK1 && CLK2 && CLK3 && CLK4;
		end
	end
end

endmodule
