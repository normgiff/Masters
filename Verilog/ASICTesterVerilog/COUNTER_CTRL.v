`timescale 1ns / 1ps

/*
 * Module:             COUNTER_CTRL
 * Function:           Controls the counter ICs' clock and reset pins.
 *                     NOTE: The counter ICs we are currently using are negative-edge triggered.
 * 			           NOTE: This counter IC requires a minimum clock/reset width of 5.0 ns.
 * 			           Using a 100 MHz clock, a single cycle should do the job.
 *           
 * Inputs: 
 * 	CLK
 * 	RST
 * 	ADVANCE_COUNTER: Advance the state of the counter.
 *                     Note: The controlling FSM will need to raise this signal
 *                     for as long as necessary for the counter IC.
 * 	RESET_COUNTER:   Reset the state of the counter.
 *                     NOTE: The controlling FSM will need to raise this signal
 *                     for as long as necessary for the counter IC.
 *
 * Outputs: 
 * 	COUNTER_CLK      (four identical outputs)
 * 	COUNTER_RST
 *    BUSY:            When high, advancing or resetting the counter is not yet complete.
 */
module COUNTER_CTRL(CLK, RST, ADVANCE_COUNTER, RESET_COUNTER, 
						  COUNTER_CLK_1, COUNTER_CLK_2, COUNTER_CLK_3, COUNTER_CLK_4, 
						  COUNTER_RST, 
						  BUSY);
	input CLK;
	input RST;
	input ADVANCE_COUNTER;
	input RESET_COUNTER;
	
	output reg COUNTER_CLK_1;
	output reg COUNTER_CLK_2;
	output reg COUNTER_CLK_3;
	output reg COUNTER_CLK_4;
	
	output reg COUNTER_RST; 
	
	output reg BUSY;
	
	// Apparently, we need a minimum 1 microsecond pulse
	// for the voltage to fully swing between low and high, due
	// to the large load on the FPGA signals...
	// Used for 1 microsecond pulse.
	reg [6:0] delay;
	
	always@(posedge CLK) begin
		if (RST) begin
			delay <= 7'd0;
			BUSY <= 1'b0;
			COUNTER_RST <= 1'b0;
			COUNTER_CLK_1 <= 1'b1;
			COUNTER_CLK_2 <= 1'b1;
			COUNTER_CLK_3 <= 1'b1;
			COUNTER_CLK_4 <= 1'b1;
		end
		else begin		
			if (delay == 7'd0) begin
				COUNTER_CLK_1 <= 1'b1;
				COUNTER_CLK_2 <= 1'b1;
				COUNTER_CLK_3 <= 1'b1;
				COUNTER_CLK_4 <= 1'b1;
				COUNTER_RST <= 1'b0;
				BUSY <= 1'b0;
			end
			else begin
				if (delay == 7'd100) begin
					delay <= 7'd0;
				end
				else begin
					delay <= delay + 7'd1;
				end
			end
			
			if (ADVANCE_COUNTER) begin			
				COUNTER_CLK_1 <= 1'b0;
				COUNTER_CLK_2 <= 1'b0;
				COUNTER_CLK_3 <= 1'b0;
				COUNTER_CLK_4 <= 1'b0;
				delay <= delay + 7'd1;
				BUSY <= 1'b1;
			end
			else if (RESET_COUNTER) begin
				COUNTER_RST <= 1'b1;
				delay <= delay + 7'd1;
				BUSY <= 1'b1;
			end
		end
	end
	
endmodule
