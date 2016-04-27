`timescale 1ns / 1ps

/*
 * Module: OUTPUT_BUFFER_CTRL 
 * Function: Controller for parallel-to-serial shift registers (output buffers).
 *           Datasheet: http://www.nxp.com/documents/data_sheet/74HC_HCT597.pdf
 *
 * Inputs: 
 *    CLK
 *    RST
 * 	CLEAR_BUFFER:      Resets the output buffers.
 *    CAPTURE_SRAM_DATA: When high, this controller latches onto the SRAM data
 *                       and then clocks it in.
 *    Q:                 Serial data from daisy-chained output buffers.
 *    
 * Outputs: 
 *    READY:             When high, the controller has completed the last-requested operation.
 * 							 When low, the controller is in the middle of an operation.
 *	 	SRAM_DATA:         128-bit SRAM data fetched from output buffers.
 *    MR_BAR: 				 Master reset (active-low).
 *    PL_BAR:            Enables parallel load (active-low).
 *    SCHP:              Shift-register clock.
 *    STCP:              Storage (parallel) register clock.
 * 
 */
module OUTPUT_BUFFER_CTRL(CLK, RST, CLEAR_BUFFER, CAPTURE_SRAM_DATA, 
								  READY, SRAM_DATA, Q, MR_BAR, PL_BAR, SHCP, STCP);
	input CLK;
	input RST;
	output reg READY;
	
	input CLEAR_BUFFER; 
	input CAPTURE_SRAM_DATA; 
	output reg [127:0] SRAM_DATA;
	input Q;
	output reg MR_BAR;
	output reg PL_BAR;
	output reg SHCP;
	output reg STCP;
	
	parameter IDLE = 0;
	parameter RESET_BUFFER = 1;
	parameter LATCH_DATA = 2;
	parameter RETRIEVE_DATA = 3;
	
	// These output buffers are (intentionally) very slow.
	// The datasheet suggests that at 3.3V, 1000 nanoseconds should be a safe waiting time.
	reg [7:0] serial_counter;
	reg [6:0] propagation_delay_counter;
	
	reg enable_delay_counter;
	reg reset_delay_counter;
	reg enable_serial_counter;
	reg reset_serial_counter;

	parameter MAX_DELAY = 100;
	parameter SERIAL_LIMIT = 128;
	
	reg [1:0] PS;
	reg [1:0] NS;
	
	// Counters used when clocking out data from output buffer and
	// taking the slow propagation speed of the chip into account.
	// Note that a data retrieval operation requires about 50 us.
	always@(posedge CLK) begin
		if (RST) begin
			serial_counter <= 7'd0;
			propagation_delay_counter <= 7'd0;
		end
		else begin
			if (enable_delay_counter) begin
				propagation_delay_counter <= propagation_delay_counter + 7'd1;
			end
			else if (reset_delay_counter) begin
				propagation_delay_counter <= 7'd0; 
			end
			if (enable_serial_counter) begin
				serial_counter <= serial_counter + 7'd1;
			end
			else if (reset_serial_counter) begin
				serial_counter <= 7'd0;
			end
		end
	end
	
	// Present-state logic.
	always@(posedge CLK) begin
		if (RST) begin
			PS <= IDLE;
		end
		else begin
			PS <= NS;
		end
	end
	
	// Next-state logic.
	always@(*) begin
		case (PS)
			IDLE: begin
				if (CLEAR_BUFFER) begin
					NS = RESET_BUFFER;
				end
				else if (CAPTURE_SRAM_DATA) begin
					NS = LATCH_DATA; 
				end
				else begin
					NS = IDLE;
				end
			end
			RESET_BUFFER: begin
				if (propagation_delay_counter == MAX_DELAY) begin
					NS = IDLE;
				end
				else begin
					NS = RESET_BUFFER;
				end
			end
			LATCH_DATA: begin
				if (propagation_delay_counter == MAX_DELAY) begin
					NS = RETRIEVE_DATA;
				end
				else begin
					NS = LATCH_DATA;
				end
			end
			RETRIEVE_DATA: begin
				if (serial_counter == SERIAL_LIMIT) begin
					NS = IDLE;
				end
				else begin
					NS = RETRIEVE_DATA;
				end
			end
			default: begin
				// Should never get here.
				NS = IDLE;
			end
		endcase
	end
	
	reg shcp_internal; // Double-buffered to avoid glitches.
	reg stcp_internal;
	always@(posedge CLK) begin
		if (RST) begin
			SHCP <= 1'b0;
			STCP <= 1'b0;
		end
		else begin
			SHCP <= shcp_internal;
			STCP <= stcp_internal;
		end
	end
	
	// Combinational logic.
	always@(*) begin
		MR_BAR = 1'b1;
		PL_BAR = 1'b1;
		shcp_internal = 1'b0;
		stcp_internal = 1'b0;
		READY = 1'b0;

		enable_serial_counter = 1'b0;
		reset_serial_counter = 1'b0;
		
		enable_delay_counter = 1'b0;
		reset_delay_counter = 1'b0;

		case (PS) 
			IDLE: begin
				READY = 1'b1;
				reset_serial_counter = 1'b1;
				reset_delay_counter = 1'b1;
			end
			
			RESET_BUFFER: begin
				if (propagation_delay_counter < (MAX_DELAY >> 1)) begin
					MR_BAR = 1'b0;
				end
				else begin
					MR_BAR = 1'b1;
				end
			
				if (propagation_delay_counter == MAX_DELAY) begin
					reset_delay_counter = 1'b1;
				end
				else begin
					enable_delay_counter = 1'b1;
				end
			end
			
			LATCH_DATA: begin
				if (propagation_delay_counter < (MAX_DELAY >> 1)) begin
					PL_BAR = 1'b0;
					stcp_internal = 1'b0;
				end
				else begin
					PL_BAR = 1'b0;
					stcp_internal = 1'b1;
				end
			
				if (propagation_delay_counter == MAX_DELAY) begin
					reset_delay_counter = 1'b1;
				end
				else begin
					enable_delay_counter = 1'b1;
				end
			end
			
			RETRIEVE_DATA: begin
				if (propagation_delay_counter == 0) begin
					enable_serial_counter = 1'b1;
				end
				else if (propagation_delay_counter < (MAX_DELAY >> 1)) begin
					shcp_internal = 1'b0;
				end
				else begin
					shcp_internal = 1'b1;
				end
			
				if (propagation_delay_counter == MAX_DELAY) begin
					reset_delay_counter = 1'b1;
				end
				else begin
					enable_delay_counter = 1'b1;
				end
			end
			
			default: begin
				// Should never get here.
			end
		endcase
	end
	
	// Clocks in serial data.
	always@(posedge CLK) begin
		if (RST) begin
			SRAM_DATA <= 127'd0;
		end
		else if (enable_serial_counter) begin
			SRAM_DATA[8'd127 - serial_counter] <= Q;
		end
	end
	
endmodule
