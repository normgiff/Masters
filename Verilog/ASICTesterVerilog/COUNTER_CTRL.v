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
	
	output COUNTER_CLK_1;
	output COUNTER_CLK_2;
	output COUNTER_CLK_3;
	output COUNTER_CLK_4;
	
	output reg COUNTER_RST; 
	reg counter_clock_oddr2;
	
	assign COUNTER_CLK_1 = counter_clock_oddr2;
	assign COUNTER_CLK_2 = counter_clock_oddr2;
	assign COUNTER_CLK_3 = counter_clock_oddr2;
	assign COUNTER_CLK_4 = counter_clock_oddr2;
	
	always@(posedge CLK) begin
		if (RST) begin
			counter_clock_oddr2 <= 1'b1;
			COUNTER_RST <= 1'b0;
		end
		else begin
			if (ADVANCE_COUNTER) begin
				counter_clock_oddr2 <= 1'b0;
			end
			else if (RESET_COUNTER) begin
				COUNTER_RST <= 1'b1;
			end
			else begin
				counter_clock_oddr2 <= 1'b1;
				COUNTER_RST <= 1'b0;
			end
		end
	end
	
	/*
	// Might help with glitches, but probably not necessary.
	// Actually, they appear to cause IO problems...
	ODDR2 #(
		.DDR_ALIGNMENT("NONE"), // Sets output alignment to "NONE", "C0" or "C1"
		.INIT(1'b1), // Sets initial state of the Q output to 1'b0 or 1'b1
		.SRTYPE("SYNC") // Specifies "SYNC" or "ASYNC" set/reset
		) ODDR2_inst1 (
		.Q(COUNTER_CLK_1), // 1-bit DDR output data
		.C0(CLK), // 1-bit clock input
		.C1(~CLK), // 1-bit clock input
		.CE(1'b1), // 1-bit clock enable input
		.D0(counter_clock_oddr2), // 1-bit data input (associated with C0)
		.D1(counter_clock_oddr2), // 1-bit data input (associated with C1)
		.R(1'b0), // 1-bit reset input
		.S(1'b0) // 1-bit set input
		);
		
	// Might help with glitches, but probably not necessary.
	ODDR2 #(
		.DDR_ALIGNMENT("NONE"), // Sets output alignment to "NONE", "C0" or "C1"
		.INIT(1'b1), // Sets initial state of the Q output to 1'b0 or 1'b1
		.SRTYPE("SYNC") // Specifies "SYNC" or "ASYNC" set/reset
		) ODDR2_inst2 (
		.Q(COUNTER_CLK_2), // 1-bit DDR output data
		.C0(CLK), // 1-bit clock input
		.C1(~CLK), // 1-bit clock input
		.CE(1'b1), // 1-bit clock enable input
		.D0(counter_clock_oddr2), // 1-bit data input (associated with C0)
		.D1(counter_clock_oddr2), // 1-bit data input (associated with C1)
		.R(1'b0), // 1-bit reset input
		.S(1'b0) // 1-bit set input
		);
		
	// Might help with glitches, but probably not necessary.
	ODDR2 #(
		.DDR_ALIGNMENT("NONE"), // Sets output alignment to "NONE", "C0" or "C1"
		.INIT(1'b1), // Sets initial state of the Q output to 1'b0 or 1'b1
		.SRTYPE("SYNC") // Specifies "SYNC" or "ASYNC" set/reset
		) ODDR2_inst3 (
		.Q(COUNTER_CLK_3), // 1-bit DDR output data
		.C0(CLK), // 1-bit clock input
		.C1(~CLK), // 1-bit clock input
		.CE(1'b1), // 1-bit clock enable input
		.D0(counter_clock_oddr2), // 1-bit data input (associated with C0)
		.D1(counter_clock_oddr2), // 1-bit data input (associated with C1)
		.R(1'b0), // 1-bit reset input
		.S(1'b0) // 1-bit set input
		);
		
	// Might help with glitches, but probably not necessary.
	ODDR2 #(
		.DDR_ALIGNMENT("NONE"), // Sets output alignment to "NONE", "C0" or "C1"
		.INIT(1'b1), // Sets initial state of the Q output to 1'b0 or 1'b1
		.SRTYPE("SYNC") // Specifies "SYNC" or "ASYNC" set/reset
		) ODDR2_inst4 (
		.Q(COUNTER_CLK_4), // 1-bit DDR output data
		.C0(CLK), // 1-bit clock input
		.C1(~CLK), // 1-bit clock input
		.CE(1'b1), // 1-bit clock enable input
		.D0(counter_clock_oddr2), // 1-bit data input (associated with C0)
		.D1(counter_clock_oddr2), // 1-bit data input (associated with C1)
		.R(1'b0), // 1-bit reset input
		.S(1'b0) // 1-bit set input
		);
		
	*/

endmodule
