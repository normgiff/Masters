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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "//psf/Home/Desktop/Masters/FPGAPrototypeProjects/clock_cont/clock.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {1, 0};
static int ng4[] = {16, 0};
static unsigned int ng5[] = {1U, 0U};
static int ng6[] = {8, 0};
static unsigned int ng7[] = {2U, 0U};
static int ng8[] = {4, 0};
static unsigned int ng9[] = {3U, 0U};
static int ng10[] = {2, 0};
static unsigned int ng11[] = {4U, 0U};
static int ng12[] = {3, 0};
static unsigned int ng13[] = {5U, 0U};
static int ng14[] = {7, 0};
static unsigned int ng15[] = {6U, 0U};
static int ng16[] = {15, 0};



static void Initial_13_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(13, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 13);

LAB1:    return;
}

static void Always_17_1(char *t0)
{
    char t11[8];
    char t12[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;

LAB0:    t1 = (t0 + 3416U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(17, ng0);
    t2 = (t0 + 3736);
    *((int *)t2) = 1;
    t3 = (t0 + 3448);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(18, ng0);

LAB5:    xsi_set_current_line(19, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t4, 4);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng13)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 4, t2, 4);
    if (t6 == 1)
        goto LAB19;

LAB20:
LAB22:
LAB21:    xsi_set_current_line(56, ng0);

LAB31:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);

LAB23:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = (t0 + 1208U);
    t8 = *((char **)t7);
    t7 = (t0 + 1928);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_multiply(t11, 13, t8, 12, t10, 5);
    memset(t12, 0, 8);
    t13 = (t4 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB33;

LAB32:    t14 = (t11 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB33;

LAB36:    if (*((unsigned int *)t4) > *((unsigned int *)t11))
        goto LAB35;

LAB34:    *((unsigned int *)t12) = 1;

LAB35:    t16 = (t12 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t12);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB37;

LAB38:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = (t0 + 1208U);
    t8 = *((char **)t7);
    t7 = (t0 + 2088);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_unsigned_multiply(t11, 13, t8, 12, t10, 5);
    memset(t12, 0, 8);
    t13 = (t4 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB42;

LAB41:    t14 = (t11 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB42;

LAB45:    if (*((unsigned int *)t4) > *((unsigned int *)t11))
        goto LAB44;

LAB43:    *((unsigned int *)t12) = 1;

LAB44:    t16 = (t12 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t12);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB46;

LAB47:    xsi_set_current_line(76, ng0);

LAB50:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 13);

LAB48:
LAB39:    goto LAB2;

LAB7:    xsi_set_current_line(21, ng0);

LAB24:    xsi_set_current_line(22, ng0);
    t7 = ((char*)((ng3)));
    t8 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 5, 0LL);
    xsi_set_current_line(23, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB9:    xsi_set_current_line(26, ng0);

LAB25:    xsi_set_current_line(27, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    xsi_set_current_line(28, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB11:    xsi_set_current_line(31, ng0);

LAB26:    xsi_set_current_line(32, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB13:    xsi_set_current_line(36, ng0);

LAB27:    xsi_set_current_line(37, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB15:    xsi_set_current_line(41, ng0);

LAB28:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB17:    xsi_set_current_line(46, ng0);

LAB29:    xsi_set_current_line(47, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB19:    xsi_set_current_line(51, ng0);

LAB30:    xsi_set_current_line(52, ng0);
    t3 = ((char*)((ng16)));
    t4 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 5, 0LL);
    goto LAB23;

LAB33:    t15 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB35;

LAB37:    xsi_set_current_line(62, ng0);

LAB40:    xsi_set_current_line(63, ng0);
    t22 = ((char*)((ng1)));
    t23 = (t0 + 1768);
    xsi_vlogvar_assign_value(t23, t22, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = ((char*)((ng5)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 13, t4, 13, t7, 13);
    t8 = (t0 + 2248);
    xsi_vlogvar_assign_value(t8, t11, 0, 0, 13);
    goto LAB39;

LAB42:    t15 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB44;

LAB46:    xsi_set_current_line(67, ng0);

LAB49:    xsi_set_current_line(68, ng0);
    t22 = ((char*)((ng3)));
    t23 = (t0 + 1768);
    xsi_vlogvar_assign_value(t23, t22, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = ((char*)((ng5)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_add(t11, 13, t4, 13, t7, 13);
    t8 = (t0 + 2248);
    xsi_vlogvar_assign_value(t8, t11, 0, 0, 13);
    goto LAB48;

}


extern void work_m_00000000001137425361_2964965119_init()
{
	static char *pe[] = {(void *)Initial_13_0,(void *)Always_17_1};
	xsi_register_didat("work_m_00000000001137425361_2964965119", "isim/testbench_isim_beh.exe.sim/work/m_00000000001137425361_2964965119.didat");
	xsi_register_executes(pe);
}
