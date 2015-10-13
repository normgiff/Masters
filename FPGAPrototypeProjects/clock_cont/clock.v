



module clock(clk, period, clk_out, duty);
	input clk;
	input [3:0] period;
	input [1:0] duty;
	output reg clk_out;
	reg [3:0] div;
	reg [3:0] din;
	reg [12:0] counter;
	initial counter <= 0;
	
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