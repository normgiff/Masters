
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name clock_cont2 -dir "C:/Users/dkhoury/OneDrive/Documents/Masters/FPGAPrototypeProjects/clock_cont2/planAhead_run_1" -part xc7a100tcsg324-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "ReconfigurableClockGenerator.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {ReconfigurableClockGenerator.v}]]
set_property file_type Verilog $hdlfile
set_property library work $hdlfile
set_property top ReconfigurableClockGenerator $srcset
add_files [list {ReconfigurableClockGenerator.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc7a100tcsg324-3
