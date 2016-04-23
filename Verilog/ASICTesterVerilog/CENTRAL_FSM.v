`timescale 1ns / 1ps

// Central finite state machine (FSM).
module CENTRAL_FSM(CLK, RST, 
                   RX, TX,
                   OE_BAR, CS_BAR, WE_BAR, 
                   COUNTER_CLK, COUNTER_RST, 
                   MR_BAR, PL_BAR, STCP, SHCP, Q,
                   VT_EN,
						 SIGNALS);

	// global clock and reset
	input CLK;
	input RST;
	
	// UART
	input RX;
	output TX;
	
	// SRAM
	output OE_BAR;
	output CS_BAR;
	output WE_BAR;
	
	// Counter
	output COUNTER_CLK;
	output COUNTER_RST;
	
	// Output buffers (parallel->serial shift registers)
	output MR_BAR;
	output PL_BAR;
	output STCP;
	output SHCP;
	input Q;
	
	// Voltage translators
	output VT_EN;
	
	// Signals to DUT
	output [127:0] SIGNALS;
	
	// States and UART codes
	`include "CENTRAL_FSM_PARAMS.v"

	reg [5:0] PS;
	reg [5:0] NS;
	
	// Present-state logic.
	always@(posedge CLK) begin
		if (rst) begin
			PS <= IDLE;
		end
		else begin
			PS <= NS;
		end
	end
	
	// Soft-reset applied after tests are completed.
	wire soft_reset = (PS == TESTS_COMPLETED);
	
	assign rst = soft_reset || RST;
	
	// Counter used to change hardware during a test.
	reg [7:0] cycle_length_1_counter;
	reg next_address;
	reg turn_on_sram;
	reg transfer_new_signals;
	reg end_of_test_cycle;
	always@(posedge CLK) begin
		if (rst) begin
			cycle_length_1_counter <= 8'b0;
			next_address <= 1'b0;
			turn_on_sram <= 1'b0;
			transfer_new_signals <= 1'b0;
			end_of_test_cycle <= 1'b0;
		end
		else begin
			next_address <= 1'b0;
			transfer_new_signals <= 1'b0;
			end_of_test_cycle <= 1'b0;
			
			if (perform_test) begin
			
				if (cycle_length_1_counter == cycle_length_1) begin
					cycle_length_1_counter <= 8'b0;
					end_of_test_cycle <= 1'b1;
				end
				else begin
					cycle_length_1_counter <= cycle_length_1_counter + 8'd1;
					
					case (cycle_length_1_counter)
					
						leading_edge_1: begin
							// Turn on SRAM as soon as we start applying inputs.
							turn_on_sram <= 1'b1;
						end
						
						trailing_edge_1 - 8'd1: begin
							// As soon as we hit the trailing edge, turn off the SRAM blocks
							// by raising CS_BAR.
							turn_on_sram <= 1'b0;
						end
						
						cycle_length_1 - 8'd1: begin
							// Go to the next counter address right at the end of a test cycle.
							// Also, transfer the new signals.
							next_address <= 1'b1;
							transfer_new_signals <= 1'b1;
						end						
						
					endcase
					
				end
			end
			else begin
				// Reset the counter if we need to halt a test, or if testing is complete.
				cycle_length_1_counter <= 8'd0;
			end
		end
	end
	
	// Next-state logic.
	always@(*) begin

		// We get to this state if none of the below conditions match.
		NS = ERROR_STATE;

		case (PS)			
			IDLE: begin
				if (rxdata_ready) begin
					NS = DECODE_UART_CODE;
				end
				else begin
					NS = IDLE;
				end
			end
			
			DECODE_UART_CODE: begin
				case (rxdata[7:0])
				
					TEMPLATE_HDR: begin
						NS = PREPARE_FOR_TEMPLATE_VECTOR_1;
					end
					
					INPUT_HDR: begin
						NS = PREPARE_FOR_INPUT_VECTOR_1;
					end
					
					CYCLE_HDR: begin
						NS = PREPARE_FOR_CYCLE_VECTOR_1;
					end
					
					FF_HDR: begin
						NS = PREPARE_FOR_FF_VECTOR_1;
					end
					
					CYCLE_CONFIG_HDR: begin
						NS = STORE_CYCLE_CONFIG_DATA;
					end
					
					EXECUTE_TESTS: begin
						if (more_to_read) begin
							NS = RESET_HARDWARE_PRETEST;
						end
						else begin
							NS = UART_CAPTURE_NO_TESTS;
						end
					end
					
					SEND_BACK_DATA: begin
						NS = LOAD_SRAM_DATA_1;
					end
					
					default: begin
						// Unknown command received.
						NS = UART_CAPTURE_UNKNOWN_CODE;
					end
				
				endcase
			end
			
			/////////////////////////////////////
			// Reading and storing template vector
			/////////////////////////////////////
			
			PREPARE_FOR_TEMPLATE_VECTOR_1: begin
				NS = PREPARE_FOR_TEMPLATE_VECTOR_2;
			end
			
			PREPARE_FOR_TEMPLATE_VECTOR_2: begin
				NS = WAIT_FOR_TEMPLATE_VECTOR_1;
			end
			
			WAIT_FOR_TEMPLATE_VECTOR_1: begin
				if (txsent) begin
					NS = WAIT_FOR_TEMPLATE_VECTOR_2;
				end
				else begin
					NS = WAIT_FOR_TEMPLATE_VECTOR_1;
				end
			end
			
			WAIT_FOR_TEMPLATE_VECTOR_2: begin
				if (rxdata_ready) begin
					NS = STORE_TEMPLATE_VECTOR_1;
				end
				else begin
					NS = WAIT_FOR_TEMPLATE_VECTOR_2;
				end
			end
			
			STORE_TEMPLATE_VECTOR_1: begin
				NS = STORE_TEMPLATE_VECTOR_2;				
			end
			
			STORE_TEMPLATE_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = UART_CAPTURE_ACK;
				end
				else begin
					NS = STORE_TEMPLATE_VECTOR_2;
				end
			end
			
			/////////////////////////////////////
			// Reading and storing input vector
			/////////////////////////////////////
			
			PREPARE_FOR_INPUT_VECTOR_1: begin
				NS = PREPARE_FOR_INPUT_VECTOR_2;
			end
			
			PREPARE_FOR_INPUT_VECTOR_2: begin
				NS = WAIT_FOR_INPUT_VECTOR_1;
			end
			
			WAIT_FOR_INPUT_VECTOR_1: begin
				if (txsent) begin
					NS = WAIT_FOR_INPUT_VECTOR_2;
				end
				else begin
					NS = WAIT_FOR_INPUT_VECTOR_1;
				end
			end
			
			WAIT_FOR_INPUT_VECTOR_2: begin
				if (rxdata_ready) begin
					NS = STORE_INPUT_VECTOR_1;
				end
				else begin
					NS = WAIT_FOR_INPUT_VECTOR_2;
				end
			end
			
			STORE_INPUT_VECTOR_1: begin
				NS = STORE_INPUT_VECTOR_2;				
			end
			
			STORE_INPUT_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = UART_CAPTURE_ACK;
				end
				else begin
					NS = STORE_INPUT_VECTOR_2;
				end
			end
			
			/////////////////////////////////////
			// Reading and storing cycle vector
			/////////////////////////////////////
			
			PREPARE_FOR_CYCLE_VECTOR_1: begin
				NS = PREPARE_FOR_CYCLE_VECTOR_2;
			end
			
			PREPARE_FOR_CYCLE_VECTOR_2: begin
				NS = WAIT_FOR_CYCLE_VECTOR_1;
			end
			
			WAIT_FOR_CYCLE_VECTOR_1: begin
				if (txsent) begin
					NS = WAIT_FOR_CYCLE_VECTOR_2;
				end
				else begin
					NS = WAIT_FOR_CYCLE_VECTOR_1;
				end
			end
			
			WAIT_FOR_CYCLE_VECTOR_2: begin
				if (rxdata_ready) begin
					NS = STORE_CYCLE_VECTOR_1;
				end
				else begin
					NS = WAIT_FOR_CYCLE_VECTOR_2;
				end
			end
			
			STORE_CYCLE_VECTOR_1: begin
				NS = STORE_CYCLE_VECTOR_2;				
			end
			
			STORE_CYCLE_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = UART_CAPTURE_ACK;
				end
				else begin
					NS = STORE_CYCLE_VECTOR_2;
				end
			end
			
			/////////////////////////////////////
			// Reading and storing force-format vector
			/////////////////////////////////////
			
			PREPARE_FOR_FF_VECTOR_1: begin
				NS = PREPARE_FOR_FF_VECTOR_2;
			end
			
			PREPARE_FOR_FF_VECTOR_2: begin
				NS = WAIT_FOR_FF_VECTOR_1;
			end
			
			WAIT_FOR_FF_VECTOR_1: begin
				if (txsent) begin
					NS = WAIT_FOR_FF_VECTOR_2;
				end
				else begin
					NS = WAIT_FOR_FF_VECTOR_1;
				end
			end
			
			WAIT_FOR_FF_VECTOR_2: begin
				if (rxdata_ready) begin
					NS = SAVE_LOWER_FF_VECTOR_1;
				end
				else begin
					NS = WAIT_FOR_FF_VECTOR_2;
				end
			end
			
			SAVE_LOWER_FF_VECTOR_1: begin
				NS = SAVE_LOWER_FF_VECTOR_2;
			end
			
			SAVE_LOWER_FF_VECTOR_2: begin
				if (txsent) begin
					NS = PREPARE_FOR_FF_VECTOR_3;
				end			
			end
			
			PREPARE_FOR_FF_VECTOR_3: begin
				NS = PREPARE_FOR_FF_VECTOR_4;
			end
			
			PREPARE_FOR_FF_VECTOR_4: begin
				NS = WAIT_FOR_FF_VECTOR_3;
			end
			
			WAIT_FOR_FF_VECTOR_3: begin
				if (txsent) begin
					NS = WAIT_FOR_FF_VECTOR_4;
				end
				else begin
					NS = WAIT_FOR_FF_VECTOR_3;
				end
			end
			
			WAIT_FOR_FF_VECTOR_4: begin
				if (rxdata_ready) begin
					NS = STORE_FF_VECTOR_1;
				end
				else begin
					NS = WAIT_FOR_FF_VECTOR_2;
				end
			end
			
			STORE_FF_VECTOR_1: begin
				NS = STORE_FF_VECTOR_2;				
			end
			
			STORE_FF_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = UART_CAPTURE_ACK;
				end
				else begin
					NS = STORE_FF_VECTOR_2;
				end
			end
			
			/////////////////////////////////////
			// Cycle configuration data
			/////////////////////////////////////
			
			STORE_CYCLE_CONFIG_DATA: begin
				NS = UART_CAPTURE_ACK;
			end
			
			/////////////////////////////////////
			// Performing tests
			/////////////////////////////////////
			
			RESET_HARDWARE_PRETEST: begin
				NS = READ_INPUT_VECTOR_1;
			end
			
			READ_INPUT_VECTOR_1: begin
				NS = READ_INPUT_VECTOR_2;
			end
			
			READ_INPUT_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = LOAD_INPUT_VECTOR;
				end
				else begin
					NS = READ_INPUT_VECTOR_2;
				end
			end
			
			LOAD_INPUT_VECTOR: begin
				if (perform_test) begin
					NS = CHECK_INPUT_VECTOR;
				end
				else begin
					NS = READ_TEMPLATE_VECTOR_1;
				end
			end
			
			READ_TEMPLATE_VECTOR_1: begin
				NS = READ_TEMPLATE_VECTOR_2;
			end
			
			READ_TEMPLATE_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = LOAD_TEMPLATE_VECTOR;
				end
				else begin
					NS = READ_TEMPLATE_VECTOR_2;
				end
			end
			
			LOAD_TEMPLATE_VECTOR: begin
				NS = READ_CYCLE_VECTOR_1;
			end
			
			READ_CYCLE_VECTOR_1: begin
				NS = READ_CYCLE_VECTOR_2;
			end
			
			READ_CYCLE_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = LOAD_CYCLE_VECTOR;
				end
				else begin
					NS = READ_CYCLE_VECTOR_2;
				end
			end
			
			LOAD_CYCLE_VECTOR: begin
				NS = READ_FF_VECTOR_1;
			end
			
			READ_FF_VECTOR_1: begin
				NS = READ_FF_VECTOR_2;
			end
			
			READ_FF_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					NS = LOAD_FF_VECTOR;
				end
				else begin
					NS = READ_FF_VECTOR_2;
				end
			end
			
			LOAD_FF_VECTOR: begin
				NS = TRANSFER_VECTORS;
			end
			
			TRANSFER_VECTORS: begin
				NS = APPLY_INPUTS;
			end
			
			APPLY_INPUTS: begin
				// During a test cycle, we must do the following (in order): 
				// 1) Cycle 1: Enable the FF logic and begin counting. 
				// 1) Cycle 1: If there are more input vectors to read, request the next input vector.
				//             Otherwise, the tests are complete.
				// 2) Cycle 2: Set the SRAM blocks to write-mode by lowering CS_BAR.
				// 3) Cycle 4: As soon as the next input vector is read, we have two cases: 
				//             If the template bits have changed, go to the LOAD_INPUT_VECTOR state
				//             in order to halt real-time testing and load the new config bits.
				//             Otherwise, load the next input vector (don't transfer it yet!).
				// 4) Trailing edge cycle: Disable write-mode by raising CS_BAR.
				// 5) Cycle after trailing edge: Advance the counter.
				if (more_to_read) begin
					NS = READ_INPUT_VECTOR_1;				
				end
				else begin
					if (end_of_test_cycle) begin
						NS = TESTS_COMPLETED;
					end
					else begin
						NS = APPLY_INPUTS;
					end
				end
			end
			
			CHECK_INPUT_VECTOR: begin
				if (template_change) begin
					// Halt real-time testing, load the new configuration bits.
					// The new input vector has already been loaded.
					NS = READ_TEMPLATE_VECTOR_1;
				end
				else begin
					// Transfer the new input vector once the test cycle is complete.
					if (transfer_new_signals) begin
						NS = APPLY_INPUTS;
					end
					else begin
						NS = CHECK_INPUT_VECTOR;
					end
				end
			end
			
			TESTS_COMPLETED: begin
				// The tests have been completed.
				// Perform a soft reset, which also resets the counters, turns off SRAM blocks, 
				// disables all tristates, and disables voltage translators.
				// Then, clear the UART read buffer and transmit an acknowledgement.
				NS = UART_CAPTURE_ACK;
			end
			
			LOAD_SRAM_DATA_1: begin
				// TODO: Send the next output vector back to BBB.
				// NOTE: BBB must invoke this command as many times as needed.
				// Therefore, the BBB has to keep track of the total number of input vectors.
				NS = LOAD_SRAM_DATA_2;
			end
			
			LOAD_SRAM_DATA_2: begin
				NS = LOAD_SRAM_DATA_3;
			end
			
			LOAD_SRAM_DATA_3: begin
				// Wait for the SRAM data to be loaded.
				if (output_buffer_ctrl_ready) begin
					NS = TRANSMIT_SRAM_DATA;
				end
				else begin
					NS = LOAD_SRAM_DATA_3; 
				end
			end
			
			TRANSMIT_SRAM_DATA: begin
				NS = UART_TRANSMIT_1;
			end
					
			/////////////////////////////////////
			// General UART code transmission
			/////////////////////////////////////
			
			UART_CAPTURE_ACK: begin
				NS = UART_TRANSMIT_1;
			end
			
			UART_CAPTURE_UNKNOWN_CODE: begin
				NS = UART_TRANSMIT_1;
			end
			
			UART_CAPTURE_NO_TESTS: begin
				NS = UART_TRANSMIT_1;
			end
			
			UART_TRANSMIT_1: begin
				NS = UART_TRANSMIT_2;
			end
			
			UART_TRANSMIT_2: begin
				if (txsent) begin
					NS = IDLE;
				end
				else begin
					NS = UART_TRANSMIT_2;
				end
			end
			
			ERROR_STATE: begin
				NS = ERROR_STATE;
			end

		endcase
	
	end
	
	////////////////////////////////////////////////////////////////
	// Modules and associated logic
	////////////////////////////////////////////////////////////////
	
	// Block RAM controller
	reg input_write;
	reg template_write;
	reg ff_write;
	reg tc_write;
	reg [127:0] write_data_0;
	reg [127:0] write_data_1;
	reg template_read;
	reg [1:0] template_bits;
	reg input_read;
	reg ff_read;
	reg tc_read;
	wire [127:0] read_data_0;
	wire [127:0] read_data_1;
	wire template_change;
	wire bram_ctrl_ready;
	wire more_to_read;
	reg [1:0] current_template_bits;
	
	always@(posedge CLK) begin
		if (rst) begin
			current_template_bits <= 2'b0;
		end
		else begin
			case (PS) 
				READ_INPUT_VECTOR_2: begin
					if (bram_ctrl_ready) begin
						current_template_bits <= read_data_0[127:126];
					end
				end
			endcase
		end
	end
	
	always@(*) begin
	
		template_write = 1'b0;
		input_write = 1'b0;
		ff_write = 1'b0;
		tc_write = 1'b0;
		write_data_0 = 128'b0;
		write_data_1 = 128'b0;
		
		template_read = 1'b0;
		template_bits = current_template_bits;
		input_read = 1'b0;
		ff_read = 1'b0;
		tc_read = 1'b0;
			
		case(PS)
		
			STORE_TEMPLATE_VECTOR_1: begin
				template_write = 1'b1;
				write_data_0 = rxdata;
			end
			
			STORE_TEMPLATE_VECTOR_2: begin
				write_data_0 = rxdata;
			end
			
			STORE_INPUT_VECTOR_1: begin
				input_write = 1'b1;
				write_data_0 = rxdata;
			end
			
			STORE_INPUT_VECTOR_2: begin
				write_data_0 = rxdata;
			end
			
			STORE_CYCLE_VECTOR_1: begin
				tc_write = 1'b1;
				write_data_0 = rxdata;
			end
			
			STORE_CYCLE_VECTOR_2: begin
				write_data_0 = rxdata;
			end
			
			STORE_FF_VECTOR_1: begin
				ff_write = 1'b1;
				write_data_0 = rxdata;
				write_data_1 = ff_read_0;
			end
			
			STORE_FF_VECTOR_1: begin
				write_data_0 = rxdata;
				write_data_1 = ff_read_0;
			end
			
			READ_INPUT_VECTOR_1: begin
				input_read = 1'b1;
			end
			
			READ_TEMPLATE_VECTOR_1: begin
				template_read = 1'b1;
			end
			
			READ_CYCLE_VECTOR_1: begin
				tc_read = 1'b1;
			end
			
			READ_FF_VECTOR_1: begin
				ff_read = 1'b1;
			end
			
		endcase
		
	end
	
	BRAM_CTRL bram_ctrl0(
								.CLK(CLK), 
								.RST(rst), 
								.INPUT_WRITE(input_write), 
								.TEMPLATE_WRITE(template_write), 
								.FF_WRITE(ff_write), 
								.TC_WRITE(tc_write),
								.WRITE_DATA_0(write_data_0), 
								.WRITE_DATA_1(write_data_1),
								.TEMPLATE_READ(template_read), 
								.TEMPLATE_BITS(template_bits), 
								.INPUT_READ(input_read), 
								.FF_READ(ff_read), 
								.TC_READ(tc_read),
								.READ_DATA_0(read_data_0), 
								.READ_DATA_1(read_data_1), 
								.TEMPLATE_CHANGE(template_change), 
								.READY(bram_ctrl_ready),
								.MORE_TO_READ(more_to_read)
								);								
	
	// Counter controller
	reg advance_counter;
	reg reset_counter;
	
	always@(posedge CLK) begin
		if (rst) begin
			advance_counter <= 1'b0;
			reset_counter <= 1'b1;
		end
		else begin
			advance_counter <= 1'b0;
			reset_counter <= 1'b0;
			
			case (PS)
				RESET_HARDWARE_PRETEST: begin
					reset_counter <= 1'b1;
				end
				
				TESTS_COMPLETED: begin
					reset_counter <= 1'b1;
				end
				
				TRANSMIT_SRAM_DATA: begin
					// Advance the counter for the next time SRAM data is requested.
					advance_counter <= 1'b1;
				end
				
				default: begin
					if (next_address) begin
						advance_counter <= 1'b1;
					end
				end

			endcase	
		end
	end
	
	COUNTER_CTRL counter_ctrl0(
										.CLK(CLK), 
										.RST(rst), 
										.ADVANCE_COUNTER(advance_counter), 
										.RESET_COUNTER(reset_counter), 
										.COUNTER_CLK(COUNTER_CLK), 
										.COUNTER_RST(COUNTER_RST)
										);
										
	// DUT controller
	reg perform_test;
	wire [127:0] bus128_0;
	wire [127:0] bus128_1;
	reg sig_load;
	reg sig_transfer;
	reg ff_load;
	reg ff_transfer;
	reg template_load;
	reg template_transfer;
	reg cycle_load;
	reg cycle_transfer;
	reg [6:0] leading_edge_1;
	reg [6:0] trailing_edge_1;
	reg [7:0] cycle_length_1;
	reg [6:0] leading_edge_2;
	reg [6:0] trailing_edge_2;
	reg [7:0] cycle_length_2;
	
	assign bus128_0 = read_data_0;
	assign bus128_1 = read_data_1;
	
	// Logic to store cycle configuration parameters.
	always@(posedge CLK) begin
		if (rst) begin
			leading_edge_1 <= 7'b0;
			trailing_edge_1 <= 7'b0;
			cycle_length_1 <= 8'b0;
			leading_edge_2 <= 7'b0;
			trailing_edge_2 <= 7'b0;
			cycle_length_2 <= 8'b0;
		end
		else if (PS == STORE_CYCLE_CONFIG_DATA) begin
			leading_edge_1 <= rxdata[14:8];
			trailing_edge_1 <= rxdata[22:16];
			cycle_length_1 <= rxdata[31:24];
			leading_edge_2 <= rxdata[38:32];
			trailing_edge_2 <= rxdata[46:40];
			cycle_length_2 <= rxdata[55:48];
		end
	end
	
	always@(posedge CLK) begin
		if (rst) begin
			perform_test <= 1'b0;
		end
		else if (PS == APPLY_INPUTS) begin
			perform_test <= 1'b1;
		end
		else if (PS == CHECK_INPUT_VECTOR) begin
			if (template_change) begin
				perform_test <= 1'b0;
			end
		end
	end
	
	always@(*) begin
		sig_load = 1'b0;
		sig_transfer = 1'b0;
		ff_load = 1'b0;
		ff_transfer = 1'b0;
		template_load = 1'b0;
		template_transfer = 1'b0;
		cycle_load = 1'b0;
		cycle_transfer = 1'b0;
	
		case (PS)
			LOAD_INPUT_VECTOR: begin
				sig_load = 1'b1;
			end
			
			LOAD_TEMPLATE_VECTOR: begin
				template_load = 1'b1;
			end
			
			LOAD_CYCLE_VECTOR: begin
				cycle_load = 1'b1;
			end
			
			LOAD_FF_VECTOR: begin
				ff_load = 1'b1;
			end
			
			TRANSFER_VECTORS: begin
				sig_transfer = 1'b1;
				template_transfer = 1'b1;
				cycle_transfer = 1'b1;
				ff_transfer = 1'b1;
			end
			
		endcase
	end
	
	DUT_CTRL dut_ctrl0(
							 .CLK(CLK), 
							 .RST(rst), 
							 .PERFORM_TEST(perform_test), 
							 .BUS128_0(bus128_0), 
							 .BUS128_1(bus128_1),
							 .SIG_LOAD(sig_load), 
							 .SIG_TRANSFER(sig_transfer), 
							 .FF_LOAD(ff_load), 
							 .FF_TRANSFER(ff_transfer), 
							 .TEMPLATE_LOAD(template_load), 
							 .TEMPLATE_TRANSFER(template_transfer),
							 .CYCLE_LOAD(cycle_load), 
							 .CYCLE_TRANSFER(cycle_transfer),
							 .LEADING_EDGE_1(leading_edge_1), 
							 .TRAILING_EDGE_1(trailing_edge_1), 
							 .CYCLE_LENGTH_1(cycle_length_1),
							 .LEADING_EDGE_2(leading_edge_2), 
							 .TRAILING_EDGE_2(trailing_edge_2), 
							 .CYCLE_LENGTH_2(cycle_length_2), 
							 .OUTPUT_SIGNALS(SIGNALS)
							 );
							 
	// Output buffer controller
	reg clear_buffer;
	reg capture_sram_data;
	wire output_buffer_ctrl_ready;
	wire [127:0] sram_data;
	
	always@(posedge CLK) begin
		if (rst) begin
			clear_buffer <= 1'b1;
			capture_sram_data <= 1'b0;
		end
		else begin
			clear_buffer <= 1'b0;
			capture_sram_data <= 1'b0;
			
			if (output_buffer_ctrl_ready) begin
			
				if (PS == LOAD_SRAM_DATA_3) begin
					capture_sram_data <= 1'b1;
				end
				
			end
		end
	end
		
	OUTPUT_BUFFER_CTRL output_buffer_ctrl0(
													   .CLK(CLK), 
														.RST(rst), 
														.CLEAR_BUFFER(clear_buffer), 
														.CAPTURE_SRAM_DATA(capture_sram_data), 
														.READY(output_buffer_ctrl_ready), 
														.SRAM_DATA(sram_data), 
														.Q(Q), 
														.MR_BAR(MR_BAR), 
														.PL_BAR(PL_BAR), 
														.SHCP(SHCP), 
														.STCP(STCP)
														);
														
	// SRAM controller
	reg oe_bar_in;
	reg cs_bar_in;
	reg we_bar_in;
	
	always@(posedge CLK) begin
		if (RST || PS == IDLE) begin
			oe_bar_in <= 1'b1;
			cs_bar_in <= 1'b1;
			we_bar_in <= 1'b0; // Write-mode by default is better to prevent multiple-driver issues.
		end
		else begin		
			case (PS)
				RESET_HARDWARE_PRETEST: begin
					// Turn on the SRAM blocks.
					oe_bar_in <= 1'b0;
				end
				
				TESTS_COMPLETED: begin
					// Turn off the SRAM blocks.
					oe_bar_in <= 1'b1;
				end
				
				LOAD_SRAM_DATA_1: begin
					// Turn on the SRAM blocks.
					oe_bar_in <= 1'b0;
				end
				
				LOAD_SRAM_DATA_2: begin
					// Turn on the SRAM blocks.
					cs_bar_in <= 1'b0;
				end
				
				LOAD_SRAM_DATA_3: begin
					// Set to read mode.
					we_bar_in <= 1'b1;
				end

				default: begin
					if (perform_test) begin
						// OK to keep WE low the entire time that we perform a test, I think...
						we_bar_in <= 1'b0;
					end
					if (turn_on_sram) begin
						cs_bar_in <= 1'b0;
					end	
					else begin
						cs_bar_in <= 1'b1;
					end
				end
			endcase
		end
	end
	
	SRAM_CTRL sram_ctrl_0(
								 .OE_BAR_IN(oe_bar_in), 
								 .CS_BAR_IN(cs_bar_in), 
								 .WE_BAR_IN(we_bar_in), 
								 .OE_BAR(OE_BAR), 
								 .CS_BAR(CS_BAR), 
								 .WE_BAR(WE_BAR)
								 );

	// UART controller
	wire rxdata_ready;
	reg rxdata_retrieved;
	wire [127:0] rxdata;
	reg [127:0] txdata;
	reg txcapture;
	reg txtransmit;
	wire txsent;
	reg txack;
	
	reg [127:0] ff_read_0;
	// Force-format vectors require two UART reads.
	// We need to save one of the reads for later use.
	
	always@(posedge CLK) begin
		if (rst) begin
			ff_read_0 <= 128'b0;
		end
		else if (PS == SAVE_LOWER_FF_VECTOR_1) begin
			ff_read_0 <= rxdata;
		end
	end
	
	always@(*) begin
		rxdata_retrieved = 1'b0;
		txcapture = 1'b0;
		txtransmit = 1'b0;
		txack = 1'b0;
		txdata = 128'd0;
		
		case (PS)
		
			/////////////////////////////////////
			// Reading and storing template vector
			/////////////////////////////////////
			
			PREPARE_FOR_TEMPLATE_VECTOR_1: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
				
				// Ready the UART controller for transmission of acknowledgement.
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;
			end
			
			PREPARE_FOR_TEMPLATE_VECTOR_2: begin
				// Transmit the acknowledgement to the BBB.
				txtransmit = 1'b1;
			end
			
			WAIT_FOR_TEMPLATE_VECTOR_1: begin
				// Acknowledge completion of the transmission.
				if (txsent) begin
					txack = 1'b1;
				end
			end
			
			WAIT_FOR_TEMPLATE_VECTOR_2: begin
				// Wait until the template vector arrives.
			end
		
			STORE_TEMPLATE_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					// We finished storing the template vector.
					rxdata_retrieved = 1'b1;
				end
			end
			
			/////////////////////////////////////
			// Reading and storing input vector
			/////////////////////////////////////
			
			PREPARE_FOR_INPUT_VECTOR_1: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
				
				// Ready the UART controller for transmission of acknowledgement.
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;
			end
			
			PREPARE_FOR_INPUT_VECTOR_2: begin
				// Transmit the acknowledgement to the BBB.
				txtransmit = 1'b1;
			end
			
			WAIT_FOR_INPUT_VECTOR_1: begin
				// Acknowledge completion of the transmission.
				if (txsent) begin
					txack = 1'b1;
				end
			end
			
			WAIT_FOR_INPUT_VECTOR_2: begin
				// Wait until the input vector arrives.
			end
		
			STORE_INPUT_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					// We finished storing the input vector.
					rxdata_retrieved = 1'b1;
				end
			end
			
			/////////////////////////////////////
			// Reading and storing cycle vector
			/////////////////////////////////////
			
			PREPARE_FOR_CYCLE_VECTOR_1: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
				
				// Ready the UART controller for transmission of acknowledgement.
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;
			end
			
			PREPARE_FOR_CYCLE_VECTOR_2: begin
				// Transmit the acknowledgement to the BBB.
				txtransmit = 1'b1;
			end
			
			WAIT_FOR_CYCLE_VECTOR_1: begin
				// Acknowledge completion of the transmission.
				if (txsent) begin
					txack = 1'b1;
				end
			end
			
			WAIT_FOR_CYCLE_VECTOR_2: begin
				// Wait until the cycle vector arrives.
			end
		
			STORE_CYCLE_VECTOR_2: begin
				if (bram_ctrl_ready) begin
					// We finished storing the input vector.
					rxdata_retrieved = 1'b1;
				end
			end
			
			/////////////////////////////////////
			// Reading and storing force-format vector
			/////////////////////////////////////
			
			PREPARE_FOR_FF_VECTOR_1: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
				
				// Ready the UART controller for transmission of acknowledgement.
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;
			end
			
			PREPARE_FOR_FF_VECTOR_2: begin
				// Transmit the acknowledgement to the BBB.
				txtransmit = 1'b1;
			end
			
			WAIT_FOR_FF_VECTOR_1: begin
				// Acknowledge completion of the transmission.
				if (txsent) begin
					txack = 1'b1;
				end
			end
			
			WAIT_FOR_FF_VECTOR_2: begin
				// Wait until the lower half of the FF vector arrives.
			end
			
			SAVE_LOWER_FF_VECTOR_1: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
				
				// Ready the UART controller for transmission of acknowledgement.
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;				
			end
			
			SAVE_LOWER_FF_VECTOR_2: begin
				// Acknowledge completion of the transmission. 
				if (txsent) begin
					txack = 1'b1;
				end				
			end
			
			PREPARE_FOR_FF_VECTOR_3: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
				
				// Ready the UART controller for transmission of acknowledgement.
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;
			end
			
			PREPARE_FOR_FF_VECTOR_4: begin
				// Transmit the acknowledgement to the BBB.
				txtransmit = 1'b1;
			end
			
			WAIT_FOR_FF_VECTOR_3: begin
				// Acknowledge completion of the transmission.
				if (txsent) begin
					txack = 1'b1;
				end
			end
			
			WAIT_FOR_FF_VECTOR_4: begin
				// Wait until the upper half of the FF vector arrives.
			end
			
			/////////////////////////////////////
			// Cycle configuration data
			/////////////////////////////////////
			
			STORE_CYCLE_CONFIG_DATA: begin
				// Clear the UART read buffer.
				rxdata_retrieved = 1'b1;
			end
			
			/////////////////////////////////////
			// Test completion and data retrieval
			/////////////////////////////////////
			
			TESTS_COMPLETED: begin
				rxdata_retrieved = 1'b1;
			end
			
			TRANSMIT_SRAM_DATA: begin
				txdata = sram_data;
				txcapture = 1'b1;
			end
			
			/////////////////////////////////////
			// General UART code transmission
			/////////////////////////////////////
			
			UART_CAPTURE_ACK: begin
				txdata = {120'b0, ACKNOWLEDGE};
				txcapture = 1'b1;
			end
			
			UART_CAPTURE_UNKNOWN_CODE: begin
				txdata = {120'b0, UNKNOWN_CODE};
				txcapture = 1'b1;
			end
			
			UART_CAPTURE_NO_TESTS: begin
				txdata = {120'b0, NO_INPUT_VECTORS};
				txcapture = 1'b1;
			end
		
			UART_TRANSMIT_1: begin
				txtransmit = 1'b1;
			end
			
			UART_TRANSMIT_2: begin
				if (txsent) begin
					txack = 1'b1;
				end				
			end
			
		endcase
	end
	
	UART_CTRL uart_ctrl_0(
								 .CLK(CLK), 
								 .RST(rst), 
								 .RX(RX), 
								 .RXDATA_READY(rxdata_ready), 
								 .RXDATA_RETRIEVED(rxdata_retrieved), 
								 .RXDATA(rxdata), 
								 .TX(TX), 
								 .TXDATA(txdata), 
								 .TXCAPTURE(txcapture), 
								 .TXTRANSMIT(txtransmit), 
								 .TXSENT(txsent), 
								 .TXACK(txack)
								 );
	

	// Voltage translator controller
	reg vt_en;
	
	always@(posedge CLK) begin
		if (rst) begin
			vt_en <= 1'b0;
		end
		else begin
			case (PS) 
				RESET_HARDWARE_PRETEST: begin
					vt_en <= 1'b1;
				end
			endcase
		end
	end
	
	// The voltage translators are always enabled except when
	// reading from the SRAM blocks, in which case they must be
	// disabled to prevent multiple-driver issues.
	
	VOLTAGE_TRANSLATOR_CTRL voltage_translator_ctrl(
																	.EN_IN(vt_en), 
																	.EN(VT_EN)
																	);

endmodule
