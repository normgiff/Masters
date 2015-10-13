
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name clock -dir "Y:/Desktop/Masters/FPGAPrototypeProjects/clock_cont/clock/planAhead_run_4" -part xc7a100tcsg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "Y:/Desktop/Masters/FPGAPrototypeProjects/clock_cont/clock/clocks.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {Y:/Desktop/Masters/FPGAPrototypeProjects/clock_cont/clock} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "clocks.ucf" [current_fileset -constrset]
add_files [list {clocks.ucf}] -fileset [get_property constrset [current_run]]
link_design
