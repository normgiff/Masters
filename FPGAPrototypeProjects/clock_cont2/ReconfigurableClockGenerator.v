`timescale 1ns / 1ps

module ReconfigurableClockGenerator(CLK_IN, RST, PERIOD, DUTY, CLK_OUT);
	input CLK_IN;
	input RST;
	input [3:0] PERIOD;
	input [1:0] DUTY;
	output CLK_OUT;
	
	reg [3:0] low_end;
	reg [3:0] high_end;
	reg [9:0] counter = 10'd0;
	reg CLK_OUT_INT;
	
	// Clock output register.
	ODDR#(.DDR_CLK_EDGE("OPPOSITE_EDGE"),
			.INIT(1'b0),
			.SRTYPE("SYNC")
	)ODDR_inst(.Q(CLK_OUT),
				  .C(CLK_OUT_INT),
				  .CE(1'b1),
				  .D1(1'b1),
				  .D2(1'b0),
				  .R(1'b0),
				  .S(1'b0));
	
	always@(posedge CLK_IN)
	begin
		if(RST) begin 
			counter <= 12'b0;
			low_end <= 4'd0;
			high_end <= 4'd0;
			CLK_OUT_INT <= 1'b0;
		end
		else begin
			case(DUTY)
				2'b00:
				begin // 50%
					low_end <= 4'd1;
					high_end <= 4'd2;
				end
				2'b01:
				begin // 25%
					low_end <= 4'd1;
					high_end <= 4'd4;
				end
				2'b10:
				begin // 75%
					low_end <= 4'd3;
					high_end <= 4'd4;
				end
				2'b11:
				begin // 90%
					low_end <= 4'd9;
					high_end <= 4'd10;
				end
			endcase

			counter <= counter + 1'b1;
			
			if(counter < (low_end*PERIOD)) begin
				CLK_OUT_INT <= 1'b0;
			end
			else if(counter < (high_end*PERIOD)) begin
				CLK_OUT_INT <= 1'b1;
			end
			else begin
				counter <= 1;
				CLK_OUT_INT <= 1'b0;
			end
		end
	end
	
endmodule
