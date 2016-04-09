// Template vectors are 128-bit wide.
parameter TEMPLATE_0_ADDR_A0 = 13'd0;
parameter TEMPLATE_0_ADDR_B0 = 13'd32;
parameter TEMPLATE_0_ADDR_A1 = 13'd64;
parameter TEMPLATE_0_ADDR_B1 = 13'd96;
parameter TEMPLATE_INCR_FACTOR = 13'd128;

// FF vectors are 256-bit wide.
parameter FF_0_ADDR_A0 = 13'd512;
parameter FF_0_ADDR_B0 = 13'd544;
parameter FF_0_ADDR_A1 = 13'd576;
parameter FF_0_ADDR_B1 = 13'd608;
parameter FF_0_ADDR_A2 = 13'd640;
parameter FF_0_ADDR_B2 = 13'd672;
parameter FF_0_ADDR_A3 = 13'd704;
parameter FF_0_ADDR_B3 = 13'd736;
parameter FF_INCR_FACTOR = 13'd256;

// Test cycle vectors are 128-bit wide.
parameter TC_0_ADDR_A0 = 13'd1536;
parameter TC_0_ADDR_B0 = 13'd1568;
parameter TC_0_ADDR_A1 = 13'd1600;
parameter TC_0_ADDR_B1 = 13'd1632;
parameter TC_INCR_FACTOR = 13'd128;

// Input vectors are 128-bit wide.
// Size of BRAM is: 8k * 32 = 32768
// Number of input vectors is: (32768-2048)/128 = 240
// If more input vectors are needed, a user will need to create an additional test. 
// Should this limit become a problem, allowing input vectors to "jump" to addresses
// after their execution may be best. External SRAM is also a possibility but that
// requires I/O pins...
parameter INPUT_START_ADDR_A = 8'd64;
parameter INPUT_START_ADDR_B = 8'd65;
parameter INPUT_INCR_FACTOR = 8'd1;

// State parameters.
parameter IDLE = 0;
parameter INPUT_WRITE_1 = 1;
parameter INPUT_WRITE_2 = 2;
parameter TEMPLATE_WRITE_1 = 3;
parameter TEMPLATE_WRITE_2 = 4;
parameter FF_WRITE_1 = 5;
parameter FF_WRITE_2 = 6;
parameter FF_WRITE_3 = 7;
parameter FF_WRITE_4 = 8;
parameter INPUT_READ_0 = 9;
parameter INPUT_READ_1 = 10;
parameter INPUT_READ_2 = 11;
parameter TEMPLATE_READ_0 = 12;
parameter TEMPLATE_READ_1 = 13;
parameter TEMPLATE_READ_2 = 14;
parameter FF_READ_0 = 15;
parameter FF_READ_1 = 16;
parameter FF_READ_2 = 17;
parameter FF_READ_3 = 18;
parameter FF_READ_4 = 19;
parameter CHECK_TEMPLATE = 20;

// Valid templates are 0, 1, 2, and 3.
// Using 4 allows us to recognize a template change
// for the first read of an input vector.
parameter RESET_TEMPLATE = 4;