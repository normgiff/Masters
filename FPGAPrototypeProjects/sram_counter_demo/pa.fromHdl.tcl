
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name sram_counter_demo -dir "C:/Users/dkhoury/OneDrive/Documents/SourceTree-Masters/FPGAPrototypeProjects/sram_counter_demo/planAhead_run_1" -part xc7a100tcsg324-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "TOP.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {MUX21.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {DFF.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {LFSR.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {RANDOM_GEN.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {PULSE_GEN.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {TOP.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top TOP $srcset
add_files [list {TOP.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc7a100tcsg324-3
