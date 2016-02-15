/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000003859187337_2688871300_init();
    work_m_00000000000153337840_1279891299_init();
    work_m_00000000000487929383_1246873435_init();
    work_m_00000000003276001430_4063039020_init();
    work_m_00000000001060009401_1271211882_init();
    work_m_00000000000865301513_1970878987_init();
    work_m_00000000000636819421_1896724647_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000000636819421_1896724647");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
