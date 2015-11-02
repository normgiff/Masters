`timescale 1ns / 1ps

// TODO: Experiment with a faster clock. You can generate a faster clock using a DCM or PLL.
// See the Xilinx Timing Report for the maximum clock speed.
module RECONF_PULSE_GEN(CLK, RST, INIT, PROCEED, FREQ, DELAY, DUTY, READY, SEL);

input CLK;
input RST;
input INIT;
input PROCEED;
input [6:0] FREQ;
input [6:0] DELAY;
input [6:0] DUTY;

output reg READY;
output reg SEL;

//////////////////

// IDLE: SEL = 0.
parameter IDLE = 3'b000;

// In order to ensure that all BUFGMUX instances begin operating at the same time, 
// every BUFGMUX instance must 
parameter INITIALIZE = 3'b001;

// Frequency is calculated as: (100 MHz)/FREQ (valid values for FREQ are [1,99]).
// Duty cycle (percentage) is calculated as: DUTY/100 (valid values for DUTY are [1,100]).
// This state takes into account the values of SEL, FREQ, and DUTY.
parameter COUNT_UP = 3'b010;
parameter COUNT_DOWN = 3'b011;

// When SEL is ready to change, we wait DELAY clock cycles before changing SEL.
parameter DELAY = 3'b100;

parameter CLOCK_SPEED = 27'd100000000;

reg PS;
reg [1:0] NS;

//////////////////

// HIGH_LEVEL_LIMIT: The number of clock cycles in which SEL should be high.
// Calculation: (number of clock cycles to count) * (duty cycle)
//            = (CLOCK_SPEED/FREQ) * (DUTY/100)
reg [6:0] HIGH_LEVEL_LIMIT;

// LOW_LEVEL_LIMIT: The number of clock cycles in which SEL should be low.
// Calculation: (number of clock cycles to count) * (1 - duty cycle)
//            = (CLOCK_SPEED/FREQ) * ((100 - DUTY)/100)
reg [6:0] LOW_LEVEL_LIMIT;

// How long to keep SEL high and low.
// TODO: Place this logic in a different module in order to achieve better timing on this module.
always@(posedge CLK) begin
	HIGH_LEVEL_LIMIT <= (CLOCK_SPEED/FREQ) * (DUTY/100);
	LOW_LEVEL_LIMIT <= (CLOCK_SPEED/FREQ) * ((100 - DUTY)/100);
end

// PS logic.
always@(posedge CLK) begin
	if (RST) begin
		PS <= IDLE;
	end
	else begin
		PS <= NS;
	end
end

reg [6:0] HIGH_COUNTER;
reg [6:0] LOW_COUNTER;
reg [6:0] DELAY_COUNTER;

// Counters.
always@(posedge CLK) begin
	if (RST) begin
		HIGH_COUNTER <= 7'b0;
		LOW_COUNTER <= 7'b0;
		DELAY_COUNTER <= 7'b0;
	end
	else begin
		HIGH_COUNTER <= 7'b0;
		LOW_COUNTER <= 7'b0;
		DELAY_COUNTER <= 7'b0;
		case(PS)
			COUNT_UP: begin
				if (HIGH_COUNTER == HIGH_LEVEL_LIMIT) begin
					HIGH_COUNTER = 7'd0;
				end
				else begin
					HIGH_COUNTER <= HIGH_COUNTER + 7'd1;
				end
			end
			COUNT_DOWN: begin
				if (LOW_COUNTER == LOW_LEVEL_LIMIT) begin
					LOW_COUNTER <= 7'd0;
				end
				else begin
					LOW_COUNTER <= LOW_COUNTER + 7'd1;
				end
			end
			DELAY: begin
				if (DELAY_COUNTER == DELAY) begin
					DELAY_COUNTER <= 7'd0;
				end
				else begin
					DELAY_COUNTER <= DELAY_COUNTER + 7'd1;
				end
			end
		endcase
	end
end

always@(*) begin
	case(PS)
		IDLE: begin
			if (START) begin
				NS = INITIALIZE;
			end
			else begin
				NS = IDLE;
			end
		end
		INITIALIZE: begin
			if (PROCEED) begin
				NS = COUNT_UP;
			end
			else begin
				NS = INITIALIZE;
			end	
		end
		COUNT_UP: begin
			if (HIGH_COUNTER == HIGH_LEVEL_LIMIT) begin
				NS = COUNT_DOWN;
			end
			else begin
				NS = COUNT_UP;
			end
		end
		COUNT_DOWN: begin
			if (LOW_COUNTER == LOW_LEVEL_LIMIT) begin
				NS = COUNT_DOWN;
			end
			else begin
				NS = COUNT_UP;
			end
		end
		DELAY: begin
			if (DELAY_COUNTER == DELAY) begin
				NS = INITIALIZE;
			end
			else begin 
				NS = DELAY;
			end
		end
	endcase
end

// READY and SEL signals.
always@(*) begin
	READY = 1'b0;
	SEL = 1'b0;
	case(PS)
		IDLE: begin
			// Do nothing.
		end
		INITIALIZE: begin
			READY = 1'b1;
		end
		COUNT_UP: begin
			SEL = 1'b1;
		end
		COUNT_DOWN: begin
			// Do nothing.
		end
		DELAY: begin
			// Do nothing.
		end
	
	endcase
end

endmodule
