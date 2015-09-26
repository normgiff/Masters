
module test;
	reg clk;
	wire clk_out0, clk_out1, clk_out2;
	reg [7:0] period0, period1, period2, period3, period4, period5;
	reg [7:0] duty0, duty1, duty2, duty3, duty4, duty5;
	clock clk0(.clk(clk), .period(period0), .duty(duty0), .clk_out(clk_out0));
	clock clk1(.clk(clk), .period(period1), .duty(duty1), .clk_out(clk_out1));
	clock clk2(.clk(clk), .period(period2), .duty(duty2), .clk_out(clk_out2));
	clock clk3(.clk(clk), .period(period3), .duty(duty3), .clk_out(clk_out3));
	clock clk4(.clk(clk), .period(period4), .duty(duty4), .clk_out(clk_out4));
	clock clk5(.clk(clk), .period(period5), .duty(duty5), .clk_out(clk_out5));
	always #10 clk = ~clk;
	initial 
	begin
		clk = 0;
		period0 = 6;
		duty0 = 0;
		period1 = 6;
		duty1 = 2;
		period2 = 6;
		duty2 = 3;
		period3 = 6;
		duty3 = 4;
		period4 = 6;
		duty4 = 5;
		period5 = 6;
		duty5 = 6;
		#1000
		period0 = 6;
		duty0 = 7;
		period1 = 6;
		duty1 = 8;
		period2 = 6;
		duty2 = 9;
		period3 = 6;
		duty3 = 10;
		period4 = 6;
		duty4 = 11;
		period5 = 6;
		duty5 = 12;
	
	end
endmodule


module clock(clk, period, duty, clk_out);
	input clk;
	input [7:0] period, duty;
	output reg clk_out;
	
	reg [31:0] counter;
	reg [7:0] cycle;
	initial counter = 0;
	
	always @(posedge clk)
	begin
		if(period <= duty)
		begin
			cycle <= duty - period;
		end
		else
		begin
			cycle <= period - duty;
		end
	
	
		if(counter < cycle)
		begin
			clk_out <= 0;
		end
		else
		begin
			clk_out <= 1;
		end
		if (counter != period)
		begin
			counter = counter + 1;
		end
		else
		begin
			counter = 0;
		end
	end
endmodule