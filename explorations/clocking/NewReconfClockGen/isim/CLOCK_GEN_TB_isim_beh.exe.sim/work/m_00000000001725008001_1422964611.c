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
static const char *ng0 = "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/RECONF_PULSE_GEN.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {3U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {2U, 0U};



static void Always_46_0(char *t0)
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

LAB0:    t1 = (t0 + 4968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 6032);
    *((int *)t2) = 1;
    t3 = (t0 + 5000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(46, ng0);

LAB5:    xsi_set_current_line(47, ng0);
    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(50, ng0);

LAB10:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(47, ng0);

LAB9:    xsi_set_current_line(48, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 3, 0LL);
    goto LAB8;

}

static void Always_61_1(char *t0)
{
    char t17[8];
    char t18[8];
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
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 5216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 6048);
    *((int *)t2) = 1;
    t3 = (t0 + 5248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(61, ng0);

LAB5:    xsi_set_current_line(62, ng0);
    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(67, ng0);

LAB10:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 0LL);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 3408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB11:    t5 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t13 == 1)
        goto LAB12;

LAB13:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t13 == 1)
        goto LAB14;

LAB15:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t13 == 1)
        goto LAB16;

LAB17:
LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(62, ng0);

LAB9:    xsi_set_current_line(63, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 7, 0LL);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 0LL);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 0LL);
    goto LAB8;

LAB12:    xsi_set_current_line(72, ng0);

LAB19:    xsi_set_current_line(73, ng0);
    t11 = (t0 + 3728);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    t15 = (t0 + 2528U);
    t16 = *((char **)t15);
    t15 = ((char*)((ng3)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_minus(t17, 32, t16, 7, t15, 32);
    memset(t18, 0, 8);
    t19 = (t14 + 4);
    t20 = (t17 + 4);
    t6 = *((unsigned int *)t14);
    t7 = *((unsigned int *)t17);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t19);
    t10 = *((unsigned int *)t20);
    t21 = (t9 ^ t10);
    t22 = (t8 | t21);
    t23 = *((unsigned int *)t19);
    t24 = *((unsigned int *)t20);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB23;

LAB20:    if (t25 != 0)
        goto LAB22;

LAB21:    *((unsigned int *)t18) = 1;

LAB23:    t29 = (t18 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t18);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(76, ng0);

LAB28:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 3728);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng4)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_add(t17, 7, t5, 7, t11, 7);
    t12 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t12, t17, 0, 0, 7, 0LL);

LAB26:    goto LAB18;

LAB14:    xsi_set_current_line(80, ng0);

LAB29:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 3888);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 2688U);
    t14 = *((char **)t12);
    t12 = ((char*)((ng3)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_minus(t17, 32, t14, 7, t12, 32);
    memset(t18, 0, 8);
    t15 = (t11 + 4);
    t16 = (t17 + 4);
    t6 = *((unsigned int *)t11);
    t7 = *((unsigned int *)t17);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t15);
    t10 = *((unsigned int *)t16);
    t21 = (t9 ^ t10);
    t22 = (t8 | t21);
    t23 = *((unsigned int *)t15);
    t24 = *((unsigned int *)t16);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB33;

LAB30:    if (t25 != 0)
        goto LAB32;

LAB31:    *((unsigned int *)t18) = 1;

LAB33:    t20 = (t18 + 4);
    t30 = *((unsigned int *)t20);
    t31 = (~(t30));
    t32 = *((unsigned int *)t18);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(84, ng0);

LAB38:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 3888);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng4)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_add(t17, 7, t5, 7, t11, 7);
    t12 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t12, t17, 0, 0, 7, 0LL);

LAB36:    goto LAB18;

LAB16:    xsi_set_current_line(88, ng0);

LAB39:    xsi_set_current_line(89, ng0);
    t3 = (t0 + 4048);
    t5 = (t3 + 56U);
    t11 = *((char **)t5);
    t12 = (t0 + 2368U);
    t14 = *((char **)t12);
    t12 = ((char*)((ng3)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_minus(t17, 32, t14, 7, t12, 32);
    memset(t18, 0, 8);
    t15 = (t11 + 4);
    t16 = (t17 + 4);
    t6 = *((unsigned int *)t11);
    t7 = *((unsigned int *)t17);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t15);
    t10 = *((unsigned int *)t16);
    t21 = (t9 ^ t10);
    t22 = (t8 | t21);
    t23 = *((unsigned int *)t15);
    t24 = *((unsigned int *)t16);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t22 & t26);
    if (t27 != 0)
        goto LAB43;

LAB40:    if (t25 != 0)
        goto LAB42;

LAB41:    *((unsigned int *)t18) = 1;

LAB43:    t20 = (t18 + 4);
    t30 = *((unsigned int *)t20);
    t31 = (~(t30));
    t32 = *((unsigned int *)t18);
    t33 = (t32 & t31);
    t34 = (t33 != 0);
    if (t34 > 0)
        goto LAB44;

LAB45:    xsi_set_current_line(92, ng0);

LAB48:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 4048);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t11 = ((char*)((ng4)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_add(t17, 7, t5, 7, t11, 7);
    t12 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t12, t17, 0, 0, 7, 0LL);

LAB46:    goto LAB18;

LAB22:    t28 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB23;

LAB24:    xsi_set_current_line(73, ng0);

LAB27:    xsi_set_current_line(74, ng0);
    t35 = ((char*)((ng1)));
    t36 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t36, t35, 0, 0, 7, 0LL);
    goto LAB26;

LAB32:    t19 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(81, ng0);

LAB37:    xsi_set_current_line(82, ng0);
    t28 = ((char*)((ng1)));
    t29 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 7, 0LL);
    goto LAB36;

LAB42:    t19 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB43;

LAB44:    xsi_set_current_line(89, ng0);

LAB47:    xsi_set_current_line(90, ng0);
    t28 = ((char*)((ng1)));
    t29 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 7, 0LL);
    goto LAB46;

}

static void Always_100_2(char *t0)
{
    char t18[8];
    char t38[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
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
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t39;

LAB0:    t1 = (t0 + 5464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 6064);
    *((int *)t2) = 1;
    t3 = (t0 + 5496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(100, ng0);

LAB5:    xsi_set_current_line(101, ng0);
    t4 = (t0 + 3408);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t7, 3);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 3, t2, 3);
    if (t8 == 1)
        goto LAB15;

LAB16:
LAB18:
LAB17:    xsi_set_current_line(147, ng0);

LAB71:    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(102, ng0);

LAB20:    xsi_set_current_line(103, ng0);
    t9 = (t0 + 2048U);
    t10 = *((char **)t9);
    t9 = (t10 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (~(t11));
    t13 = *((unsigned int *)t10);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(106, ng0);

LAB25:    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB23:    goto LAB19;

LAB9:    xsi_set_current_line(110, ng0);

LAB26:    xsi_set_current_line(111, ng0);
    t3 = (t0 + 2208U);
    t4 = *((char **)t3);
    t3 = (t4 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (~(t11));
    t13 = *((unsigned int *)t4);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(119, ng0);

LAB40:    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB29:    goto LAB19;

LAB11:    xsi_set_current_line(123, ng0);

LAB41:    xsi_set_current_line(124, ng0);
    t3 = (t0 + 4048);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 2368U);
    t9 = *((char **)t7);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_unsigned_minus(t18, 32, t9, 7, t7, 32);
    memset(t38, 0, 8);
    t10 = (t5 + 4);
    t16 = (t18 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t18);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t10);
    t15 = *((unsigned int *)t16);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t10);
    t22 = *((unsigned int *)t16);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB45;

LAB42:    if (t23 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t38) = 1;

LAB45:    t36 = (t38 + 4);
    t26 = *((unsigned int *)t36);
    t27 = (~(t26));
    t28 = *((unsigned int *)t38);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB46;

LAB47:    xsi_set_current_line(127, ng0);

LAB50:    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB48:    goto LAB19;

LAB13:    xsi_set_current_line(131, ng0);

LAB51:    xsi_set_current_line(132, ng0);
    t3 = (t0 + 3728);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 2528U);
    t9 = *((char **)t7);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_unsigned_minus(t18, 32, t9, 7, t7, 32);
    memset(t38, 0, 8);
    t10 = (t5 + 4);
    t16 = (t18 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t18);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t10);
    t15 = *((unsigned int *)t16);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t10);
    t22 = *((unsigned int *)t16);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB55;

LAB52:    if (t23 != 0)
        goto LAB54;

LAB53:    *((unsigned int *)t38) = 1;

LAB55:    t36 = (t38 + 4);
    t26 = *((unsigned int *)t36);
    t27 = (~(t26));
    t28 = *((unsigned int *)t38);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB56;

LAB57:    xsi_set_current_line(135, ng0);

LAB60:    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB58:    goto LAB19;

LAB15:    xsi_set_current_line(139, ng0);

LAB61:    xsi_set_current_line(140, ng0);
    t3 = (t0 + 3888);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = (t0 + 2688U);
    t9 = *((char **)t7);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_unsigned_minus(t18, 32, t9, 7, t7, 32);
    memset(t38, 0, 8);
    t10 = (t5 + 4);
    t16 = (t18 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t18);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t10);
    t15 = *((unsigned int *)t16);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t10);
    t22 = *((unsigned int *)t16);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB65;

LAB62:    if (t23 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t38) = 1;

LAB65:    t36 = (t38 + 4);
    t26 = *((unsigned int *)t36);
    t27 = (~(t26));
    t28 = *((unsigned int *)t38);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB66;

LAB67:    xsi_set_current_line(143, ng0);

LAB70:    xsi_set_current_line(144, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB68:    goto LAB19;

LAB21:    xsi_set_current_line(103, ng0);

LAB24:    xsi_set_current_line(104, ng0);
    t16 = ((char*)((ng4)));
    t17 = (t0 + 3568);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 3);
    goto LAB23;

LAB27:    xsi_set_current_line(111, ng0);

LAB30:    xsi_set_current_line(112, ng0);
    t5 = (t0 + 2368U);
    t7 = *((char **)t5);
    t5 = ((char*)((ng1)));
    memset(t18, 0, 8);
    t9 = (t7 + 4);
    t10 = (t5 + 4);
    t19 = *((unsigned int *)t7);
    t20 = *((unsigned int *)t5);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t9);
    t23 = *((unsigned int *)t10);
    t24 = (t22 ^ t23);
    t25 = (t21 | t24);
    t26 = *((unsigned int *)t9);
    t27 = *((unsigned int *)t10);
    t28 = (t26 | t27);
    t29 = (~(t28));
    t30 = (t25 & t29);
    if (t30 != 0)
        goto LAB34;

LAB31:    if (t28 != 0)
        goto LAB33;

LAB32:    *((unsigned int *)t18) = 1;

LAB34:    t17 = (t18 + 4);
    t31 = *((unsigned int *)t17);
    t32 = (~(t31));
    t33 = *((unsigned int *)t18);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB35;

LAB36:    xsi_set_current_line(115, ng0);

LAB39:    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 3568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB37:    goto LAB29;

LAB33:    t16 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB34;

LAB35:    xsi_set_current_line(112, ng0);

LAB38:    xsi_set_current_line(113, ng0);
    t36 = ((char*)((ng2)));
    t37 = (t0 + 3568);
    xsi_vlogvar_assign_value(t37, t36, 0, 0, 3);
    goto LAB37;

LAB44:    t17 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB45;

LAB46:    xsi_set_current_line(124, ng0);

LAB49:    xsi_set_current_line(125, ng0);
    t37 = ((char*)((ng2)));
    t39 = (t0 + 3568);
    xsi_vlogvar_assign_value(t39, t37, 0, 0, 3);
    goto LAB48;

LAB54:    t17 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB55;

LAB56:    xsi_set_current_line(132, ng0);

LAB59:    xsi_set_current_line(133, ng0);
    t37 = ((char*)((ng5)));
    t39 = (t0 + 3568);
    xsi_vlogvar_assign_value(t39, t37, 0, 0, 3);
    goto LAB58;

LAB64:    t17 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(140, ng0);

LAB69:    xsi_set_current_line(141, ng0);
    t37 = ((char*)((ng2)));
    t39 = (t0 + 3568);
    xsi_vlogvar_assign_value(t39, t37, 0, 0, 3);
    goto LAB68;

}

static void Always_154_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 5712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 6080);
    *((int *)t2) = 1;
    t3 = (t0 + 5744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(154, ng0);

LAB5:    xsi_set_current_line(155, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 3088);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(156, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(157, ng0);
    t2 = (t0 + 3408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);

LAB6:    t5 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t5, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(158, ng0);

LAB18:    xsi_set_current_line(160, ng0);
    t7 = ((char*)((ng1)));
    t8 = (t0 + 3088);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 1);
    goto LAB17;

LAB9:    xsi_set_current_line(162, ng0);

LAB19:    goto LAB17;

LAB11:    xsi_set_current_line(165, ng0);

LAB20:    goto LAB17;

LAB13:    xsi_set_current_line(168, ng0);

LAB21:    xsi_set_current_line(169, ng0);
    t3 = ((char*)((ng4)));
    t5 = (t0 + 3248);
    xsi_vlogvar_assign_value(t5, t3, 0, 0, 1);
    goto LAB17;

LAB15:    xsi_set_current_line(171, ng0);

LAB22:    goto LAB17;

}


extern void work_m_00000000001725008001_1422964611_init()
{
	static char *pe[] = {(void *)Always_46_0,(void *)Always_61_1,(void *)Always_100_2,(void *)Always_154_3};
	xsi_register_didat("work_m_00000000001725008001_1422964611", "isim/CLOCK_GEN_TB_isim_beh.exe.sim/work/m_00000000001725008001_1422964611.didat");
	xsi_register_executes(pe);
}
