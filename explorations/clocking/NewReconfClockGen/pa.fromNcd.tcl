
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name NewReconfClockGen -dir "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/planAhead_run_4" -part xc6slx16csg324-3
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/CLOCK_GEN.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen} }
set_property target_constrs_file "CLOCK_GEN.ucf" [current_fileset -constrset]
add_files [list {CLOCK_GEN.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/CLOCK_GEN.ncd"
if {[catch {read_twx -name results_1 -file "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/CLOCK_GEN.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/CLOCK_GEN.twx\": $eInfo"
}
