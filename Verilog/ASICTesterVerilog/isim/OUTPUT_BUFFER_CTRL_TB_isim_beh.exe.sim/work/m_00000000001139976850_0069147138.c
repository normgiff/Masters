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
static const char *ng0 = "C:/Users/dkhoury/OneDrive/Documents/SourceTree-Masters/Verilog/ASICTesterVerilog/OUTPUT_BUFFER_CTRL.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};



static void Always_64_0(char *t0)
{
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;

LAB0:    t1 = (t0 + 5904U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 7216);
    *((int *)t2) = 1;
    t3 = (t0 + 5936);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(64, ng0);

LAB5:    xsi_set_current_line(65, ng0);
    t4 = (t0 + 2024U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(69, ng0);

LAB10:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 4184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 4344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB15;

LAB16:
LAB17:
LAB13:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 4504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 4664);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB23;

LAB24:
LAB25:
LAB21:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(65, ng0);

LAB9:    xsi_set_current_line(66, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3864);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 6, 0LL);
    goto LAB8;

LAB11:    xsi_set_current_line(70, ng0);

LAB14:    xsi_set_current_line(71, ng0);
    t11 = (t0 + 4024);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng2)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 6, t13, 6, t14, 6);
    t16 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t16, t15, 0, 0, 6, 0LL);
    goto LAB13;

LAB15:    xsi_set_current_line(73, ng0);

LAB18:    xsi_set_current_line(74, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4024);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 6, 0LL);
    goto LAB17;

LAB19:    xsi_set_current_line(76, ng0);

LAB22:    xsi_set_current_line(77, ng0);
    t11 = (t0 + 3864);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng2)));
    memset(t15, 0, 8);
    xsi_vlog_unsigned_add(t15, 8, t13, 8, t14, 8);
    t16 = (t0 + 3864);
    xsi_vlogvar_wait_assign_value(t16, t15, 0, 0, 8, 0LL);
    goto LAB21;

LAB23:    xsi_set_current_line(79, ng0);

LAB26:    xsi_set_current_line(80, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3864);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 8, 0LL);
    goto LAB25;

}

static void Always_86_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 6152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 7232);
    *((int *)t2) = 1;
    t3 = (t0 + 6184);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(86, ng0);

LAB5:    xsi_set_current_line(87, ng0);
    t4 = (t0 + 2024U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(90, ng0);

LAB10:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 4984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4824);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 2, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(87, ng0);

LAB9:    xsi_set_current_line(88, ng0);
    t11 = (t0 + 472);
    t12 = *((char **)t11);
    t11 = (t0 + 4824);
    xsi_vlogvar_wait_assign_value(t11, t12, 0, 0, 2, 0LL);
    goto LAB8;

}

static void Always_96_2(char *t0)
{
    char t18[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;

LAB0:    t1 = (t0 + 6400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 7248);
    *((int *)t2) = 1;
    t3 = (t0 + 6432);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(96, ng0);

LAB5:    xsi_set_current_line(97, ng0);
    t4 = (t0 + 4824);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = (t0 + 472);
    t8 = *((char **)t7);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t8, 32);
    if (t9 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t3, 32);
    if (t9 == 1)
        goto LAB9;

LAB10:    t2 = (t0 + 744);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t3, 32);
    if (t9 == 1)
        goto LAB11;

LAB12:    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t9 = xsi_vlog_unsigned_case_compare(t6, 2, t3, 32);
    if (t9 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(133, ng0);

LAB58:    xsi_set_current_line(135, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = (t0 + 4984);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(98, ng0);

LAB18:    xsi_set_current_line(99, ng0);
    t7 = (t0 + 2184U);
    t10 = *((char **)t7);
    t7 = (t10 + 4);
    t11 = *((unsigned int *)t7);
    t12 = (~(t11));
    t13 = *((unsigned int *)t10);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2344U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t11 = *((unsigned int *)t2);
    t12 = (~(t11));
    t13 = *((unsigned int *)t3);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(105, ng0);

LAB27:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 472);
    t3 = *((char **)t2);
    t2 = (t0 + 4984);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB25:
LAB21:    goto LAB17;

LAB9:    xsi_set_current_line(109, ng0);

LAB28:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 4024);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 1016);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t5 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t8);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t10);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB32;

LAB29:    if (t23 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t18) = 1;

LAB32:    t17 = (t18 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB33;

LAB34:    xsi_set_current_line(113, ng0);

LAB37:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t2 = (t0 + 4984);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB35:    goto LAB17;

LAB11:    xsi_set_current_line(117, ng0);

LAB38:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 4024);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 1016);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t5 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t8);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t10);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB42;

LAB39:    if (t23 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t18) = 1;

LAB42:    t17 = (t18 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB43;

LAB44:    xsi_set_current_line(121, ng0);

LAB47:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 744);
    t3 = *((char **)t2);
    t2 = (t0 + 4984);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB45:    goto LAB17;

LAB13:    xsi_set_current_line(125, ng0);

LAB48:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 3864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 1152);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t5 + 4);
    t10 = (t8 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t8);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t10);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t10);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB52;

LAB49:    if (t23 != 0)
        goto LAB51;

LAB50:    *((unsigned int *)t18) = 1;

LAB52:    t17 = (t18 + 4);
    t26 = *((unsigned int *)t17);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(129, ng0);

LAB57:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t2 = (t0 + 4984);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 2);

LAB55:    goto LAB17;

LAB19:    xsi_set_current_line(99, ng0);

LAB22:    xsi_set_current_line(100, ng0);
    t16 = (t0 + 608);
    t17 = *((char **)t16);
    t16 = (t0 + 4984);
    xsi_vlogvar_assign_value(t16, t17, 0, 0, 2);
    goto LAB21;

LAB23:    xsi_set_current_line(102, ng0);

LAB26:    xsi_set_current_line(103, ng0);
    t4 = (t0 + 744);
    t5 = *((char **)t4);
    t4 = (t0 + 4984);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 2);
    goto LAB25;

LAB31:    t16 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(110, ng0);

LAB36:    xsi_set_current_line(111, ng0);
    t31 = (t0 + 472);
    t32 = *((char **)t31);
    t31 = (t0 + 4984);
    xsi_vlogvar_assign_value(t31, t32, 0, 0, 2);
    goto LAB35;

LAB41:    t16 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB42;

LAB43:    xsi_set_current_line(118, ng0);

LAB46:    xsi_set_current_line(119, ng0);
    t31 = (t0 + 880);
    t32 = *((char **)t31);
    t31 = (t0 + 4984);
    xsi_vlogvar_assign_value(t31, t32, 0, 0, 2);
    goto LAB45;

LAB51:    t16 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB52;

LAB53:    xsi_set_current_line(126, ng0);

LAB56:    xsi_set_current_line(127, ng0);
    t31 = (t0 + 472);
    t32 = *((char **)t31);
    t31 = (t0 + 4984);
    xsi_vlogvar_assign_value(t31, t32, 0, 0, 2);
    goto LAB55;

}

static void Always_141_3(char *t0)
{
    char t10[8];
    char t11[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;

LAB0:    t1 = (t0 + 6648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 7264);
    *((int *)t2) = 1;
    t3 = (t0 + 6680);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(141, ng0);

LAB5:    xsi_set_current_line(142, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 3224);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(146, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2904);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4504);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4664);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(152, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 4824);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = (t0 + 472);
    t6 = *((char **)t5);
    t7 = xsi_vlog_unsigned_case_compare(t4, 2, t6, 32);
    if (t7 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t3 = *((char **)t2);
    t7 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t7 == 1)
        goto LAB9;

LAB10:    t2 = (t0 + 744);
    t3 = *((char **)t2);
    t7 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t7 == 1)
        goto LAB11;

LAB12:    t2 = (t0 + 880);
    t3 = *((char **)t2);
    t7 = xsi_vlog_unsigned_case_compare(t4, 2, t3, 32);
    if (t7 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(212, ng0);

LAB79:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(155, ng0);

LAB18:    xsi_set_current_line(156, ng0);
    t5 = ((char*)((ng2)));
    t8 = (t0 + 2904);
    xsi_vlogvar_assign_value(t8, t5, 0, 0, 1);
    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4664);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB17;

LAB9:    xsi_set_current_line(161, ng0);

LAB19:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 4024);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 1016);
    t9 = *((char **)t8);
    t8 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_unsigned_rshift(t10, 32, t9, 32, t8, 32);
    memset(t11, 0, 8);
    t12 = (t6 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB21;

LAB20:    t13 = (t10 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB21;

LAB24:    if (*((unsigned int *)t6) < *((unsigned int *)t10))
        goto LAB22;

LAB23:    t15 = (t11 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t11);
    t19 = (t18 & t17);
    t20 = (t19 != 0);
    if (t20 > 0)
        goto LAB25;

LAB26:    xsi_set_current_line(165, ng0);

LAB29:    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3224);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB27:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1016);
    t8 = *((char **)t6);
    memset(t10, 0, 8);
    t6 = (t5 + 4);
    t9 = (t8 + 4);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t8);
    t18 = (t16 ^ t17);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t9);
    t23 = (t19 ^ t20);
    t24 = (t18 | t23);
    t25 = *((unsigned int *)t6);
    t26 = *((unsigned int *)t9);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB33;

LAB30:    if (t27 != 0)
        goto LAB32;

LAB31:    *((unsigned int *)t10) = 1;

LAB33:    t13 = (t10 + 4);
    t30 = *((unsigned int *)t13);
    t31 = (~(t30));
    t32 = *((unsigned int *)t10);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(172, ng0);

LAB38:    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB36:    goto LAB17;

LAB11:    xsi_set_current_line(177, ng0);

LAB39:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 4024);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 1016);
    t9 = *((char **)t8);
    t8 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_unsigned_rshift(t10, 32, t9, 32, t8, 32);
    memset(t11, 0, 8);
    t12 = (t6 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB41;

LAB40:    t13 = (t10 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB41;

LAB44:    if (*((unsigned int *)t6) < *((unsigned int *)t10))
        goto LAB42;

LAB43:    t15 = (t11 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t11);
    t19 = (t18 & t17);
    t20 = (t19 != 0);
    if (t20 > 0)
        goto LAB45;

LAB46:    xsi_set_current_line(182, ng0);

LAB49:    xsi_set_current_line(183, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3384);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(184, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB47:    xsi_set_current_line(187, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1016);
    t8 = *((char **)t6);
    memset(t10, 0, 8);
    t6 = (t5 + 4);
    t9 = (t8 + 4);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t8);
    t18 = (t16 ^ t17);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t9);
    t23 = (t19 ^ t20);
    t24 = (t18 | t23);
    t25 = *((unsigned int *)t6);
    t26 = *((unsigned int *)t9);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB53;

LAB50:    if (t27 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t10) = 1;

LAB53:    t13 = (t10 + 4);
    t30 = *((unsigned int *)t13);
    t31 = (~(t30));
    t32 = *((unsigned int *)t10);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB54;

LAB55:    xsi_set_current_line(190, ng0);

LAB58:    xsi_set_current_line(191, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB56:    goto LAB17;

LAB13:    xsi_set_current_line(195, ng0);

LAB59:    xsi_set_current_line(196, ng0);
    t2 = (t0 + 4024);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 1016);
    t9 = *((char **)t8);
    t8 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_unsigned_rshift(t10, 32, t9, 32, t8, 32);
    memset(t11, 0, 8);
    t12 = (t6 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB61;

LAB60:    t13 = (t10 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB61;

LAB64:    if (*((unsigned int *)t6) < *((unsigned int *)t10))
        goto LAB62;

LAB63:    t15 = (t11 + 4);
    t16 = *((unsigned int *)t15);
    t17 = (~(t16));
    t18 = *((unsigned int *)t11);
    t19 = (t18 & t17);
    t20 = (t19 != 0);
    if (t20 > 0)
        goto LAB65;

LAB66:    xsi_set_current_line(199, ng0);

LAB69:    xsi_set_current_line(200, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB67:    xsi_set_current_line(203, ng0);
    t2 = (t0 + 4024);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1016);
    t8 = *((char **)t6);
    memset(t10, 0, 8);
    t6 = (t5 + 4);
    t9 = (t8 + 4);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t8);
    t18 = (t16 ^ t17);
    t19 = *((unsigned int *)t6);
    t20 = *((unsigned int *)t9);
    t23 = (t19 ^ t20);
    t24 = (t18 | t23);
    t25 = *((unsigned int *)t6);
    t26 = *((unsigned int *)t9);
    t27 = (t25 | t26);
    t28 = (~(t27));
    t29 = (t24 & t28);
    if (t29 != 0)
        goto LAB73;

LAB70:    if (t27 != 0)
        goto LAB72;

LAB71:    *((unsigned int *)t10) = 1;

LAB73:    t13 = (t10 + 4);
    t30 = *((unsigned int *)t13);
    t31 = (~(t30));
    t32 = *((unsigned int *)t10);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB74;

LAB75:    xsi_set_current_line(207, ng0);

LAB78:    xsi_set_current_line(208, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4184);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB76:    goto LAB17;

LAB21:    t14 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB23;

LAB22:    *((unsigned int *)t11) = 1;
    goto LAB23;

LAB25:    xsi_set_current_line(162, ng0);

LAB28:    xsi_set_current_line(163, ng0);
    t21 = ((char*)((ng1)));
    t22 = (t0 + 3224);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 1);
    goto LAB27;

LAB32:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(169, ng0);

LAB37:    xsi_set_current_line(170, ng0);
    t14 = ((char*)((ng2)));
    t15 = (t0 + 4344);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 1);
    goto LAB36;

LAB41:    t14 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB43;

LAB42:    *((unsigned int *)t11) = 1;
    goto LAB43;

LAB45:    xsi_set_current_line(178, ng0);

LAB48:    xsi_set_current_line(179, ng0);
    t21 = ((char*)((ng1)));
    t22 = (t0 + 3384);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 1);
    xsi_set_current_line(180, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3704);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB47;

LAB52:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(187, ng0);

LAB57:    xsi_set_current_line(188, ng0);
    t14 = ((char*)((ng2)));
    t15 = (t0 + 4344);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 1);
    goto LAB56;

LAB61:    t14 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB63;

LAB62:    *((unsigned int *)t11) = 1;
    goto LAB63;

LAB65:    xsi_set_current_line(196, ng0);

LAB68:    xsi_set_current_line(197, ng0);
    t21 = ((char*)((ng1)));
    t22 = (t0 + 3544);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 1);
    goto LAB67;

LAB72:    t12 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB73;

LAB74:    xsi_set_current_line(203, ng0);

LAB77:    xsi_set_current_line(204, ng0);
    t14 = ((char*)((ng2)));
    t15 = (t0 + 4504);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 1);
    xsi_set_current_line(205, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4344);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB76;

}

static void Always_219_4(char *t0)
{
    char t13[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    int t22;

LAB0:    t1 = (t0 + 6896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(219, ng0);
    t2 = (t0 + 7280);
    *((int *)t2) = 1;
    t3 = (t0 + 6928);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(219, ng0);

LAB5:    xsi_set_current_line(220, ng0);
    t4 = (t0 + 2024U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(223, ng0);
    t2 = (t0 + 4504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t4);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB10;

LAB11:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(220, ng0);

LAB9:    xsi_set_current_line(221, ng0);
    t11 = ((char*)((ng4)));
    t12 = (t0 + 3064);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 128, 0LL);
    goto LAB8;

LAB10:    xsi_set_current_line(223, ng0);

LAB13:    xsi_set_current_line(224, ng0);
    t11 = (t0 + 2504U);
    t12 = *((char **)t11);
    t11 = (t0 + 3064);
    t14 = (t0 + 3064);
    t15 = (t14 + 72U);
    t16 = *((char **)t15);
    t17 = (t0 + 3864);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    xsi_vlog_generic_convert_bit_index(t13, t16, 2, t19, 8, 2);
    t20 = (t13 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (!(t21));
    if (t22 == 1)
        goto LAB14;

LAB15:    goto LAB12;

LAB14:    xsi_vlogvar_wait_assign_value(t11, t12, 0, *((unsigned int *)t13), 1, 0LL);
    goto LAB15;

}


extern void work_m_00000000001139976850_0069147138_init()
{
	static char *pe[] = {(void *)Always_64_0,(void *)Always_86_1,(void *)Always_96_2,(void *)Always_141_3,(void *)Always_219_4};
	xsi_register_didat("work_m_00000000001139976850_0069147138", "isim/OUTPUT_BUFFER_CTRL_TB_isim_beh.exe.sim/work/m_00000000001139976850_0069147138.didat");
	xsi_register_executes(pe);
}
