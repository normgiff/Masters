`timescale 1ns / 1ps

/* 
 * Module:         UART_RX
 * Function:       Serial communication with BeagleBone Black (rev C).
 *                 Baud rate is fixed at 115,200. 
 *                 (Bits are held for 8.68 microseconds on the wire.)
 *                 NOTE: This module assumes that bytes are always transferred in groups of 16.
 * 
 * Inputs: 
 * 	CLK          (100 MHz)
 * 	RST
 *    DATA:        128-bit data to be sent.
 *    CAPTURE:     Instructs this controller to store the 128-bit data to be transferred.
 *    TRANSMIT:    Instructs this controller to transmit the 128-bit data stored.
 *    ACKNOWLEDGE: Enables this controller to prepare for another data transfer.
 *                 Should be raised in response to a high SENT.
 * 
 * Outputs: 
 * 	TX
 *    SENT:        Informs the user that this controller has completed a 16-byte transfer.
 * 
 * Using this controller: 
 * 1) Ready the DATA bus.
 * 2) Raise the CAPTURE signal for one clock cycle 
 *    to have the controller latch onto the signals on the DATA bus.
 * 3) Raise the TRANSMIT signal for one clock cycle to have the controller transmit the 
 *    stored data.
 * 4) Wait until the SENT signal is high. When SENT is low, the controller is still 
 *    transferring data.
 * 5) Raise ACKNOWLEDGE for one clock cycle to ready the controller for a new transfer.
 * 6) Go to step 1.
 */
module UART_TX(CLK, RST, DATA, CAPTURE, TRANSMIT, ACKNOWLEDGE, TX, SENT);
	input CLK;
	input RST;
	
	input [127:0] DATA;
	input CAPTURE;
	input TRANSMIT;
	input ACKNOWLEDGE;

	output reg TX;
	output reg SENT;

	parameter BAUD_RATE = 115200;
	
	parameter PERIOD = 867 - 1; // Amount of time for each bit on the wire.
	                            // Subtract 1 to account for switching states.
	
	parameter IDLE = 0;
	parameter STARTBIT = 1;
	parameter BIT0 = 2;
	parameter BIT1 = 3;
	parameter BIT2 = 4;
	parameter BIT3 = 5;
	parameter BIT4 = 6;
	parameter BIT5 = 7;
	parameter BIT6 = 8;
	parameter BIT7 = 9;
	parameter STOPBIT = 10;
	parameter IDLE_SENT = 11;
	
	reg [3:0] PS;
	reg [3:0] NS;
	
	reg [6:0] bit_count;     // Number of bits sent at any given time.
	reg [127:0] data_buffer; // We transmit 16 bytes over the line, so 128 bits.
	
	reg [9:0] clock_counter; // Used to count the amount of time to apply a signal value
	                         // on the TX bus.
	reg count;               // Used to raise clock_counter.
	reg reset_count;         // Used to reset clock_counter.
	
	// Present-state logic.
	always@(posedge CLK) begin
		if (RST) begin
			PS <= IDLE;
		end
		else begin
			PS <= NS;
		end
	end
	
	// TX assignment.
	always@(posedge CLK) begin
		if (RST) begin
			TX <= 1'b1;
			bit_count <= 6'd0;
		end
		else begin
			case (PS) 
				STARTBIT: begin
					TX <= 1'b0;
				end
				BIT0: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT1: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT2: begin
					TX <= data_buffer[bit_count];				
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT3: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT4: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT5: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT6: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				BIT7: begin 
					TX <= data_buffer[bit_count];
					if (clock_counter == PERIOD) begin
						bit_count <= bit_count + 7'd1;
					end
				end
				STOPBIT: begin
					TX <= 1'b1;
				end
				default: begin
					TX <= 1'b1;
				end
			endcase
		end
	end
	
	// Counter for the amount of time to hold bits on the wire.
	always@(posedge CLK) begin
		if (RST || reset_count) begin
			clock_counter <= 10'd0;
		end
		else if (count) begin
			clock_counter <= clock_counter + 10'd1;
		end
		else begin
			clock_counter <= clock_counter;
		end
	end
	
	// Used to CAPTURE data.
	always@(posedge CLK) begin
		if (RST) begin
			data_buffer <= 127'd0;
		end
		else begin
			if ((PS == IDLE) && CAPTURE) begin
				data_buffer <= DATA;
			end
		end
	end	
	
	// Next-state logic.
	always@(*) begin
		case (PS)
			// IDLE: Remain in this state until TRANSMIT goes high.
			IDLE: begin
				if (TRANSMIT == 1'b0) begin
					NS = IDLE;
				end
				else begin
					NS = STARTBIT;
				end
			end
			
			STARTBIT: begin
				if (clock_counter == PERIOD) begin
					NS = BIT0;
				end
				else begin
					NS = STARTBIT;
				end
			end
			
			BIT0: begin
				if (clock_counter == PERIOD) begin
					NS = BIT1;
				end
				else begin
					NS = BIT0;
				end
			end
			
			BIT1: begin
				if (clock_counter == PERIOD) begin
					NS = BIT2;
				end
				else begin
					NS = BIT1;
				end
			end
			
			BIT2: begin
				if (clock_counter == PERIOD) begin
					NS = BIT3;
				end
				else begin
					NS = BIT2;
				end
			end
			
			BIT3: begin
				if (clock_counter == PERIOD) begin
					NS = BIT4;
				end
				else begin
					NS = BIT3;
				end
			end
			
			BIT4: begin
				if (clock_counter == PERIOD) begin
					NS = BIT5;
				end
				else begin
					NS = BIT4;
				end
			end
			
			BIT5: begin
				if (clock_counter == PERIOD) begin
					NS = BIT6;
				end
				else begin
					NS = BIT5;
				end
			end
			
			BIT6: begin
				if (clock_counter == PERIOD) begin
					NS = BIT7;
				end
				else begin
					NS = BIT6;
				end
			end
			
			BIT7: begin
				if (clock_counter == PERIOD) begin
					NS = STOPBIT;
				end
				else begin
					NS = BIT7;
				end
			end
			
			STOPBIT: begin
				if (clock_counter == PERIOD) begin
					if (bit_count == 7'd0) begin
						NS = IDLE_SENT;
					end
					else begin
						NS = STARTBIT;
					end
				end
				else begin
					NS = STOPBIT;
				end
			end
			
			IDLE_SENT: begin
				if (ACKNOWLEDGE) begin
					NS = IDLE;
				end
				else begin
					NS = IDLE_SENT;
				end
			end
			
			default: begin
				// Should never get here.
				NS = IDLE;
			end
		endcase
	end
	
	// Combinational logic.
	always@(*) begin	
		count = 1'b0;
		reset_count = 1'b0;
		SENT = 1'b0;
		
		case (PS)
			STARTBIT: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT0: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT1: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end			
			end
			
			BIT2: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT3: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT4: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT5: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT6: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT7: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			STOPBIT: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			IDLE_SENT: begin
				SENT = 1'b1;
			end
		endcase	
	end
	
endmodule
