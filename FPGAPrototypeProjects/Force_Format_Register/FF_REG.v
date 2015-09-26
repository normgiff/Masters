`timescale 1ns / 1ps

module FF_REG(RST, CLK, CLK_ENABLE, DATA, FF, OUT);
	input RST;
	input CLK;
	input CLK_ENABLE;
	input DATA;
	input [1:0]FF;
	
	output OUT;

	reg DATA_POS;
	always@(posedge CLK) begin
		if (RST) begin
			DATA_POS <= 1'b0;
		end
		else begin
			DATA_POS <= DATA;
		end
	end

	reg DATA_NEG;
	always@(negedge CLK) begin
		if (RST) begin
			DATA_NEG <= 1'b0;
		end
		else begin
			DATA_NEG <= DATA;
		end
	end
	
	reg D1;
	always@(*) begin
		if (FF[1] && FF[0]) begin
			D1 = DATA_NEG;
		end
		else begin
			D1 = DATA_POS;
		end
	end
	
	reg D2;
	always@(*) begin
		if (FF[1]) begin
			D2 = DATA_POS;
		end
		else begin
			D2 = FF[0];
		end
	end
	
	ODDR #(
	.DDR_CLK_EDGE("OPPOSITE_EDGE"), // "OPPOSITE_EDGE" or "SAME_EDGE"
	.INIT(1'b0), // Initial value of Q: 1'b0 or 1'b1
	.SRTYPE("SYNC") // Set/Reset type: "SYNC" or "ASYNC"
	) ODDR_inst (
		.Q(OUT), // 1-bit DDR output
		.C(CLK), // 1-bit clock input
		.CE(CLK_ENABLE), // 1-bit clock enable input
		.D1(D1), // 1-bit data input (positive edge)
		.D2(D2), // 1-bit data input (negative edge)
		.R(RST), // 1-bit reset
		.S(1'b0) // 1-bit set
	);
endmodule
