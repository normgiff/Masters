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
    work_m_00000000000107525496_2942962510_init();
    work_m_00000000000645526280_1091251676_init();
    work_m_00000000001877520416_0341727208_init();
    work_m_00000000000107525496_1254300568_init();
    work_m_00000000000107525496_2547325773_init();
    unisims_ver_m_00000000000339918974_0558531594_init();
    work_m_00000000004195959980_4010260301_init();
    work_m_00000000004183350651_1237461907_init();
    work_m_00000000001982941240_3913145983_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001982941240_3913145983");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
