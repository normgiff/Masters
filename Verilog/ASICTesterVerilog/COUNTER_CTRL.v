`timescale 1ns / 1ps

/*
 * Module: COUNTER_CTRL
 * Function: Controls the counter ICs' clock and reset pins.
 *           Note that the counter ICs we are currently using are negative-edge triggered!
 * 			 Also note that this counter IC requires a minimum clock/reset width of 5.0 ns.
 * 			 Using a 100 MHz clock, a single cycle should do the job.
 *           
 * Inputs: 
 * 	CLK
 * 	RST
 * 	ADVANCE_COUNTER: Advance the state of the counter.
 *                     Note: The controlling FSM will need to raise this signal
 *                     for as long as necessary for the counter IC.
 * 	RESET_COUNTER:   Reset the state of the counter.
 *                     Note: The controlling FSM will need to raise this signal
 *                     for as long as necessary for the counter IC.
 *
 * Outputs: 
 * 	COUNTER_CLK
 * 	COUNTER_RST
 */
module COUNTER_CTRL(CLK, RST, ADVANCE_COUNTER, RESET_COUNTER, 
						  COUNTER_CLK_1, COUNTER_CLK_2, COUNTER_CLK_3, COUNTER_CLK_4, 
						  COUNTER_RST);
	input CLK;
	input RST;
	input ADVANCE_COUNTER;
	input RESET_COUNTER;
	
	output reg COUNTER_CLK_1;
	output reg COUNTER_CLK_2;
	output reg COUNTER_CLK_3;
	output reg COUNTER_CLK_4;
	
	output reg COUNTER_RST; 
	
	// Looks like we need to hold the clock signal for 40 ns.
	// Otherwise the FPGA glitches.
	reg advance_ok;
	reg advance_ok_buf;
	reg [1:0] delay; 
	
	always@(posedge CLK) begin
		if (RST) begin
			COUNTER_RST <= 1'b0;
			delay <= 2'd0;
			advance_ok <= 1'b1;
			advance_ok_buf <= 1'b1;
		end
		else begin
			if (ADVANCE_COUNTER || delay != 2'd0) begin
				advance_ok <= 1'b0;
				delay <= delay + 2'd1;
			end
			else if (RESET_COUNTER || delay != 2'd0) begin
				COUNTER_RST <= 1'b1;
				delay <= delay + 2'd1;
			end
			else begin
				COUNTER_RST <= 1'b0;
				advance_ok <= 1'b1;
			end
			advance_ok_buf <= advance_ok;
			COUNTER_CLK_1 <= advance_ok_buf;
			COUNTER_CLK_2 <= advance_ok_buf;
			COUNTER_CLK_3 <= advance_ok_buf;
			COUNTER_CLK_4 <= advance_ok_buf;
		end
	end
	
endmodule
