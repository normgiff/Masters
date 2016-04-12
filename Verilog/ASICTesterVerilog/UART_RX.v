`timescale 1ns / 1ps

/* 
 * Module: UART_RX
 * Function: Serial communication with BeagleBone Black (rev C).
 *           Baud rate is fixed at 115,200. (Bits are held for 8.68 microseconds on the wire.)
 * Inputs: 
 * 	CLK (100 MHz)
 * 	RST
 *    DATA_READY   
 *    DATA_RETRIEVED
 *    DATA 
 */
module UART_RX(CLK, RST, RX, DATA_READY, DATA_RETRIEVED, DATA);
	input CLK;
	input RST;
	
	input RX;
	input DATA_RETRIEVED;

	output reg DATA_READY;
	output reg [7:0] DATA;

	parameter BAUD_RATE = 115200;
	
	// Subtract 1 to account for switching states.
	parameter PERIOD = 867 - 1;
	parameter HALF_PERIOD = 433 - 1;
	
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
	
	reg [3:0] PS;
	reg [3:0] NS;
	
	reg [9:0] clock_counter;
	reg count;
	reg reset_count;
	reg sample;
	
	// Used to sample bits.
	always@(posedge CLK) begin
		if (RST) begin
			DATA <= 8'd0;
		end
		else if (sample) begin
			case (PS) 
				BIT0: begin 
					DATA[0] <= RX;
				end
				BIT1: begin 
					DATA[1] <= RX;
				end
				BIT2: begin 
					DATA[2] <= RX;
				end
				BIT3: begin 
					DATA[3] <= RX;
				end
				BIT4: begin 
					DATA[4] <= RX;
				end
				BIT5: begin 
					DATA[5] <= RX;
				end
				BIT6: begin 
					DATA[6] <= RX;
				end
				BIT7: begin 
					DATA[7] <= RX;
				end
			endcase
		end
	end
	
	// Clock used for counting.
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
			// we assume a spurious pulse on the line. Otherwise, we began accumulating bits.
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
					NS = IDLE_DATA;
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
