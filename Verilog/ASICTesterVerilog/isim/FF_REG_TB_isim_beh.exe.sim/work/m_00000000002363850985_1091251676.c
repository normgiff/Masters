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
static const char *ng0 = "C:/Users/dkhoury/OneDrive/Documents/SourceTree-Masters/Verilog/ASICTesterVerilog/FF_REG.v";
static unsigned int ng1[] = {2U, 0U};
static unsigned int ng2[] = {3U, 0U};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {1U, 0U};



static void Always_34_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 4368);
    *((int *)t2) = 1;
    t3 = (t0 + 3584);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(34, ng0);

LAB5:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 1752U);
    t5 = *((char **)t4);
    t4 = (t0 + 2472);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_38_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 3800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 4384);
    *((int *)t2) = 1;
    t3 = (t0 + 3832);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(38, ng0);

LAB5:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1752U);
    t5 = *((char **)t4);
    t4 = (t0 + 2632);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    goto LAB2;

}

static void Always_42_2(char *t0)
{
    char t11[8];
    char t29[8];
    char t30[8];
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
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
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
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;

LAB0:    t1 = (t0 + 4048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 4400);
    *((int *)t2) = 1;
    t3 = (t0 + 4080);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(42, ng0);

LAB5:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 1912U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:
LAB12:
LAB11:    xsi_set_current_line(50, ng0);

LAB16:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1912U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t11, 0, 8);
    t4 = (t3 + 4);
    t7 = (t2 + 4);
    t12 = *((unsigned int *)t3);
    t13 = *((unsigned int *)t2);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t4);
    t16 = *((unsigned int *)t7);
    t17 = (t15 ^ t16);
    t18 = (t14 | t17);
    t19 = *((unsigned int *)t4);
    t20 = *((unsigned int *)t7);
    t21 = (t19 | t20);
    t22 = (~(t21));
    t23 = (t18 & t22);
    if (t23 != 0)
        goto LAB20;

LAB17:    if (t21 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t11) = 1;

LAB20:    t9 = (t11 + 4);
    t24 = *((unsigned int *)t9);
    t25 = (~(t24));
    t26 = *((unsigned int *)t11);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB21;

LAB22:    xsi_set_current_line(54, ng0);

LAB38:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1592U);
    t3 = *((char **)t2);
    memset(t29, 0, 8);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 & 1U);
    if (t16 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t2) != 0)
        goto LAB41;

LAB42:    t7 = (t29 + 4);
    t17 = *((unsigned int *)t29);
    t18 = *((unsigned int *)t7);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB43;

LAB44:    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t7);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t7) > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t29) > 0)
        goto LAB49;

LAB50:    memcpy(t11, t8, 8);

LAB51:    t10 = (t0 + 2312);
    xsi_vlogvar_assign_value(t10, t11, 0, 0, 1);

LAB23:
LAB13:    goto LAB2;

LAB7:    xsi_set_current_line(44, ng0);

LAB14:    xsi_set_current_line(45, ng0);
    t7 = (t0 + 2472);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 2312);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 1);
    goto LAB13;

LAB9:    xsi_set_current_line(47, ng0);

LAB15:    xsi_set_current_line(48, ng0);
    t3 = (t0 + 2632);
    t4 = (t3 + 56U);
    t7 = *((char **)t4);
    t8 = (t0 + 2312);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 1);
    goto LAB13;

LAB19:    t8 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB20;

LAB21:    xsi_set_current_line(51, ng0);

LAB24:    xsi_set_current_line(52, ng0);
    t10 = (t0 + 1592U);
    t31 = *((char **)t10);
    memset(t30, 0, 8);
    t10 = (t31 + 4);
    t32 = *((unsigned int *)t10);
    t33 = (~(t32));
    t34 = *((unsigned int *)t31);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t10) != 0)
        goto LAB27;

LAB28:    t38 = (t30 + 4);
    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t38);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB29;

LAB30:    t44 = *((unsigned int *)t30);
    t45 = (~(t44));
    t46 = *((unsigned int *)t38);
    t47 = (t45 || t46);
    if (t47 > 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t38) > 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t30) > 0)
        goto LAB35;

LAB36:    memcpy(t29, t42, 8);

LAB37:    t48 = (t0 + 2312);
    xsi_vlogvar_assign_value(t48, t29, 0, 0, 1);
    goto LAB23;

LAB25:    *((unsigned int *)t30) = 1;
    goto LAB28;

LAB27:    t37 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB28;

LAB29:    t42 = (t0 + 1752U);
    t43 = *((char **)t42);
    goto LAB30;

LAB31:    t42 = ((char*)((ng3)));
    goto LAB32;

LAB33:    xsi_vlog_unsigned_bit_combine(t29, 1, t43, 1, t42, 1);
    goto LAB37;

LAB35:    memcpy(t29, t43, 8);
    goto LAB37;

LAB39:    *((unsigned int *)t29) = 1;
    goto LAB42;

LAB41:    t4 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB42;

LAB43:    t8 = (t0 + 1752U);
    t9 = *((char **)t8);
    goto LAB44;

LAB45:    t8 = ((char*)((ng4)));
    goto LAB46;

LAB47:    xsi_vlog_unsigned_bit_combine(t11, 1, t9, 1, t8, 1);
    goto LAB51;

LAB49:    memcpy(t11, t9, 8);
    goto LAB51;

}


extern void work_m_00000000002363850985_1091251676_init()
{
	static char *pe[] = {(void *)Always_34_0,(void *)Always_38_1,(void *)Always_42_2};
	xsi_register_didat("work_m_00000000002363850985_1091251676", "isim/FF_REG_TB_isim_beh.exe.sim/work/m_00000000002363850985_1091251676.didat");
	xsi_register_executes(pe);
}
