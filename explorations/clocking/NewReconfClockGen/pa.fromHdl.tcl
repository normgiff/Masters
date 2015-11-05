
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name NewReconfClockGen -dir "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/planAhead_run_1" -part xc7a100tcsg324-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "CLOCK_GEN.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {SYNCHRONIZER.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {RECONF_PULSE_GEN.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ODDR_WRAPPER.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ipcore_dir/CLK_MULTIPLIER.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {CLOCK_MUX.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {CLOCK_GEN.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top CLOCK_GEN $srcset
add_files [list {CLOCK_GEN.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc7a100tcsg324-3
