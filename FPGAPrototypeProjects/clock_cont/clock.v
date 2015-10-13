



module clock(clk, period, clk_out, duty);
	input clk;
	input [3:0] period;
	input [1:0] duty;
	output reg clk_out;
	reg [3:0] div;
	reg [3:0] din;
	reg [12:0] counter;
	initial counter <= 0;
	ODDR#(.DDR_CLK_EDGE("OPPOSITE_EDGE"),//"OPPOSITE_EDGE"or"SAME_EDGE"
			.INIT(1'b0),//Initial valu of Q: 1'b0 or 1'b1
			.SRTYPE("SYNC")// Set/Reset type: "SYNC" or "ASYNC")
	)ODDR_inst (.Q(Q), // 1-bit DDR output
				  .C(C), // 1-bit clock input
				  .CE(CE), // 1-bit clock enable input
				.D1(D1), // 1-bit data input (positive edge) 
				  .D2(D2), // 1-bit data input (negative edge)
				  .R(R), // 1-bit reset 
				  .S(S)); // 1-bit set
	
	
	
	always @(posedge clk)
	begin
		case(duty)
			2'b00:
			begin
				div <= 1;
				din <= 2;
			end
			2'b01:
			begin
				div <= 1;
				din <= 4;
			end
			2'b10:
			begin
				div <= 3;
				din <= 4;
			end
			2'b11:
			begin
				div <= 9;
				din <= 10;
			end
			default
			begin
				div <= 1;
				din <= 10;
			end
		endcase
		if(counter <= (period*div)*100)
		begin
			clk_out <= 0;
			counter <= counter + 1'b1;
		end
		else if(counter <= (period*din)*100)
		begin
			clk_out <= 1;
			counter <= counter + 1'b1;
		end
		else
		begin
			counter <= 0;
		end
	end
endmodule