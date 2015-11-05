`timescale 1ns / 1ps

module RECONF_PULSE_GEN(CLK, RST, INIT, PROCEED, HIGH_LEVEL_LIMIT, LOW_LEVEL_LIMIT, 
								DELAY_LIMIT, READY, SEL);

// Global clock and reset.
input CLK;
input RST;

// These three signals are used to synchronize the clock generators.
// We want to ensure that the clock generators begin at the same time!
input INIT;
input PROCEED;
output reg READY;

// These limits are computed by the BeagleBone Black and sent over serial.
// (It's too expensive to compute these limits in Verilog!)
input [6:0] DELAY_LIMIT;
input [6:0] HIGH_LEVEL_LIMIT;
input [6:0] LOW_LEVEL_LIMIT;

// The SEL signal for the BUFGMUX.
// TODO: Figure out how to specify a constraint in ISE. (Probably PlanAhead.)
//       We need to minimize the skew for all of the SEL signals!
output reg SEL;

//////////////////

// IDLE: SEL = 0.
parameter IDLE = 3'b000;

// In order to ensure that all instances begin operating at the same time.
parameter INITIALIZE = 3'b001;

// Before counting, we delay the signal.
parameter DELAY = 3'b010;

// Used in generating the SEL signals.
parameter COUNT_UP = 3'b011;
parameter COUNT_DOWN = 3'b100;

reg [2:0] PS;
reg [2:0] NS;

//////////////////

// Present-state logic.
always@(posedge CLK) begin
	if (RST) begin
		PS <= IDLE;
	end
	else begin
		PS <= NS;
	end
end


// Counters.
reg [6:0] HIGH_COUNTER;
reg [6:0] LOW_COUNTER;
reg [6:0] DELAY_COUNTER;

always@(posedge CLK) begin
	if (RST) begin
		HIGH_COUNTER <= 7'd0;
		LOW_COUNTER <= 7'd0;
		DELAY_COUNTER <= 7'd0;
	end
	else begin
		HIGH_COUNTER <= 7'd0;
		LOW_COUNTER <= 7'd0;
		DELAY_COUNTER <= 7'd0;
		case(PS)
			COUNT_UP: begin
				if (HIGH_COUNTER == HIGH_LEVEL_LIMIT) begin
					HIGH_COUNTER <= 7'd0;
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
				if (DELAY_COUNTER == DELAY_LIMIT) begin
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
			if (INIT) begin
				NS = INITIALIZE;
			end
			else begin
				NS = IDLE;
			end
		end
		INITIALIZE: begin
			if (PROCEED) begin
				if (DELAY_LIMIT == 7'd0) begin
					NS = COUNT_UP;
				end
				else begin
					NS = DELAY;
				end
			end
			else begin
				NS = INITIALIZE;
			end	
		end
		DELAY: begin
			if (DELAY_COUNTER == DELAY_LIMIT) begin
				NS = COUNT_UP;
			end
			else begin 
				NS = DELAY;
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
				NS = COUNT_UP;
			end
			else begin
				NS = COUNT_DOWN;
			end
		end
		default: begin
			NS = IDLE;
		end
	endcase
end

// READY and SEL signals.
always@(*) begin
	READY = 1'b1;
	SEL = 1'b0;
	case(PS)
		IDLE: begin
			// Do nothing.
			READY = 1'b0;
		end
		INITIALIZE: begin
			// Do nothing.
		end
		DELAY: begin
			// Do nothing.
		end
		COUNT_UP: begin
			SEL = 1'b1;
		end
		COUNT_DOWN: begin
			// Do nothing.
		end
	endcase
end

endmodule
