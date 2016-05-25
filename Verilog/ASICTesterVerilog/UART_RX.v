`timescale 1ns / 1ps

/* 
 * Module:            UART_RX
 * Function:          Serial communication with BeagleBone Black (rev C).
 *                    Baud rate is fixed at 115,200. 
 *                    (A bit is held for 8.68 microseconds on the wire.)
 *                    NOTE: This module assumes that bytes are always transferred in groups of 16.
 *  
 * Inputs: 
 * 	CLK (100 MHz)
 * 	RST
 *    RX
 *    DATA_RETRIEVED: When high, clears the UART read buffer to allow more data to be stored.
 *                    Should be raised in response to a high DATA_READY.
 *    
 * Outputs: 
 * 	DATA_READY:     When high, data has been received on the UART lines.
 *    DATA:           128 bits stored in the UART read buffer.
 * 
 * Using this controller: 
 * 1) When data has been received on the line, DATA_READY will be 1.
 * 2) Retrieve the DATA from the line, then raise DATA_RETRIEVED for one clock cycle.
 * 3) Go to step 1.
 */
module UART_RX(CLK, RST, RX, DATA_RETRIEVED, DATA_READY, DATA);
	input CLK;
	input RST;
	
	input RX;
	input DATA_RETRIEVED;

	output reg DATA_READY;
	output reg [127:0] DATA;

	parameter BAUD_RATE = 115200;
	
	// Subtract 1 to account for switching states.
	parameter PERIOD = 867 - 1;      // The amount of time a bit is held on the wire.
	parameter HALF_PERIOD = 433 - 1; // Used to sample bits halfway through its life.
	
	parameter IDLE_NODATA = 0;
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
	parameter IDLE_DATA = 11;
	
	// We expect 16 bytes over the line, so 128 bits.
	reg [6:0] bit_count;
	
	reg [9:0] clock_counter; // Counter used to sample bits at the appropriate time.
	reg count;               // Used to increment clock_counter.
	reg reset_count;         // Resets the counter used to sample bits.
	reg sample;              // When high, sample the bit on the wire.
	
	reg [3:0] PS;
	reg [3:0] NS;
	
	// Counter used to determine when to sample a bit on the wire.
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
	
	// Used to sample bits.
	always@(posedge CLK) begin
		if (RST) begin
			DATA <= 127'd0;
			bit_count <= 7'd0;
		end
		else if (sample) begin
			bit_count <= bit_count + 7'd1;
			case (PS) 
				BIT0: begin 
					DATA[bit_count] <= RX;
				end
				BIT1: begin 
					DATA[bit_count] <= RX;
				end
				BIT2: begin 
					DATA[bit_count] <= RX;
				end
				BIT3: begin 
					DATA[bit_count] <= RX;
				end
				BIT4: begin 
					DATA[bit_count] <= RX;
				end
				BIT5: begin 
					DATA[bit_count] <= RX;
				end
				BIT6: begin 
					DATA[bit_count] <= RX;
				end
				BIT7: begin 
					DATA[bit_count] <= RX;
				end
			endcase
		end
	end
	
	// Present-state logic.
	always@(posedge CLK) begin
		if (RST) begin
			PS <= IDLE_NODATA;
		end
		else begin
			PS <= NS;
		end
	end
	
	// Next-state logic.
	always@(*) begin
		case (PS)
			// IDLE_NODATA: Remain in this state until the RX line goes low.
			IDLE_NODATA: begin
				if (RX == 1'b1) begin
					NS = IDLE_NODATA;
				end
				else begin
					NS = STARTBIT;
				end
			end
			
			// STARTBIT: Count halfway through the start bit. If we see 0 at any point,
			// we assume a spurious pulse on the line. Otherwise, we begin accumulating bits.
			STARTBIT: begin
				if (clock_counter == HALF_PERIOD) begin
					NS = BIT0;
				end
				else if (RX == 1'b1) begin
					NS = IDLE_NODATA;
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
						NS = IDLE_DATA;
					end
					else begin
						NS = STARTBIT;
					end
				end
				else begin
					NS = STOPBIT;
				end
			end
			
			IDLE_DATA: begin
				if (DATA_RETRIEVED) begin
					NS = IDLE_NODATA;
				end
				else begin
					NS = IDLE_DATA;
				end
			end
			
			default: begin
				// We should never get here.
				NS = IDLE_NODATA;
			end
		endcase
	end
	
	// Combinational logic.
	always@(*) begin	
		DATA_READY = 1'b0;
		count = 1'b0;
		reset_count = 1'b0;
		sample = 1'b0;
		
		case (PS)
			// STARTBIT: Count halfway through the start bit. If we see 0 at any point,
			// we assume a spurious pulse on the line. Otherwise, we began accumulating bits.
			STARTBIT: begin
				if (clock_counter == HALF_PERIOD || RX == 1'b1) begin
					reset_count = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT0: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT1: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end			
			end
			
			BIT2: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT3: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT4: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT5: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT6: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
				end
				else begin
					count = 1'b1;
				end
			end
			
			BIT7: begin
				if (clock_counter == PERIOD) begin
					reset_count = 1'b1;
					sample = 1'b1;
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
			
			IDLE_DATA: begin
				DATA_READY = 1'b1;
			end
		endcase	
	end
	
endmodule
