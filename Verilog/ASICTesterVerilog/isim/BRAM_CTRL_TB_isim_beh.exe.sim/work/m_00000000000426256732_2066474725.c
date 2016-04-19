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
static const char *ng0 = "C:/Users/dkhoury/OneDrive/Documents/SourceTree-Masters/Verilog/ASICTesterVerilog/BRAM_CTRL_TB.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {0, 0, 0, 0, 0, 0, 0, 0};
static unsigned int ng4[] = {3735928559U, 0U, 19136237U, 0U, 3735928559U, 0U, 19136237U, 0U};
static unsigned int ng5[] = {0U, 0U};
static const char *ng6 = "READ_DATA_0 should be %d, but is %d.\n";
static unsigned int ng7[] = {3735928559U, 0U, 19136237U, 0U, 3735928559U, 0U, 3240361709U, 0U};
static int ng8[] = {3, 0};
static const char *ng9 = "Incorrect FF read.\n";
static unsigned int ng10[] = {3149638314U, 0U, 3722300620U, 0U, 3203395310U, 0U, 4277001901U, 0U};
static const char *ng11 = "READ_DATA_0 should be %d, but is %d!\n";



static void Initial_47_0(char *t0)
{
    char t4[8];
    char t27[32];
    char t28[32];
    char t29[8];
    char t32[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t30;
    char *t31;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;

LAB0:    t1 = (t0 + 4768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);

LAB4:    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(77, ng0);

LAB9:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB13;

LAB10:    if (t16 != 0)
        goto LAB12;

LAB11:    *((unsigned int *)t4) = 1;

LAB13:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB18;
    goto LAB1;

LAB12:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB13;

LAB14:    xsi_set_current_line(77, ng0);

LAB16:    xsi_set_current_line(78, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    goto LAB9;

LAB18:    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB19:    xsi_set_current_line(87, ng0);

LAB20:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB24;

LAB21:    if (t16 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t4) = 1;

LAB24:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB25;

LAB26:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB29;

LAB30:
LAB31:    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB33;
    goto LAB1;

LAB23:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB24;

LAB25:    xsi_set_current_line(87, ng0);

LAB27:    xsi_set_current_line(88, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB28:    goto LAB20;

LAB29:    xsi_set_current_line(91, ng0);

LAB32:    xsi_set_current_line(92, ng0);
    t6 = ((char*)((ng4)));
    t19 = (t0 + 1048U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t0, (char)118, t6, 128, (char)118, t20, 128);
    goto LAB31;

LAB33:    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB34:    xsi_set_current_line(103, ng0);

LAB35:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB39;

LAB36:    if (t16 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t4) = 1;

LAB39:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB40;

LAB41:    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB44;
    goto LAB1;

LAB38:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB39;

LAB40:    xsi_set_current_line(103, ng0);

LAB42:    xsi_set_current_line(104, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB43:    goto LAB35;

LAB44:    xsi_set_current_line(110, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB45:    xsi_set_current_line(113, ng0);

LAB46:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB50;

LAB47:    if (t16 != 0)
        goto LAB49;

LAB48:    *((unsigned int *)t4) = 1;

LAB50:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB51;

LAB52:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB55;

LAB56:
LAB57:    xsi_set_current_line(123, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB49:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB50;

LAB51:    xsi_set_current_line(113, ng0);

LAB53:    xsi_set_current_line(114, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB54;
    goto LAB1;

LAB54:    goto LAB46;

LAB55:    xsi_set_current_line(117, ng0);

LAB58:    xsi_set_current_line(118, ng0);
    t6 = ((char*)((ng4)));
    t19 = (t0 + 1048U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t0, (char)118, t6, 128, (char)118, t20, 128);
    goto LAB57;

LAB59:    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB60;
    goto LAB1;

LAB60:    xsi_set_current_line(129, ng0);

LAB61:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB65;

LAB62:    if (t16 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t4) = 1;

LAB65:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB66;

LAB67:    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(134, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB70;
    goto LAB1;

LAB64:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(129, ng0);

LAB68:    xsi_set_current_line(130, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB69;
    goto LAB1;

LAB69:    goto LAB61;

LAB70:    xsi_set_current_line(136, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB71:    xsi_set_current_line(139, ng0);

LAB72:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB76;

LAB73:    if (t16 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t4) = 1;

LAB76:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB77;

LAB78:    xsi_set_current_line(143, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB81;

LAB82:
LAB83:    xsi_set_current_line(148, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB85;
    goto LAB1;

LAB75:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB76;

LAB77:    xsi_set_current_line(139, ng0);

LAB79:    xsi_set_current_line(140, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB80;
    goto LAB1;

LAB80:    goto LAB72;

LAB81:    xsi_set_current_line(143, ng0);

LAB84:    xsi_set_current_line(144, ng0);
    t6 = ((char*)((ng7)));
    t19 = (t0 + 1048U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t0, (char)118, t6, 128, (char)118, t20, 128);
    goto LAB83;

LAB85:    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB86;
    goto LAB1;

LAB86:    xsi_set_current_line(154, ng0);

LAB87:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB91;

LAB88:    if (t16 != 0)
        goto LAB90;

LAB89:    *((unsigned int *)t4) = 1;

LAB91:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB92;

LAB93:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB96;

LAB97:
LAB98:    xsi_set_current_line(163, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(164, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB100;
    goto LAB1;

LAB90:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB91;

LAB92:    xsi_set_current_line(154, ng0);

LAB94:    xsi_set_current_line(155, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB95;
    goto LAB1;

LAB95:    goto LAB87;

LAB96:    xsi_set_current_line(158, ng0);

LAB99:    xsi_set_current_line(159, ng0);
    t6 = ((char*)((ng4)));
    t19 = (t0 + 1048U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t0, (char)118, t6, 128, (char)118, t20, 128);
    goto LAB98;

LAB100:    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB101;
    goto LAB1;

LAB101:    xsi_set_current_line(170, ng0);

LAB102:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB106;

LAB103:    if (t16 != 0)
        goto LAB105;

LAB104:    *((unsigned int *)t4) = 1;

LAB106:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB107;

LAB108:    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);
    xsi_set_current_line(176, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB111;
    goto LAB1;

LAB105:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB106;

LAB107:    xsi_set_current_line(170, ng0);

LAB109:    xsi_set_current_line(171, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB110;
    goto LAB1;

LAB110:    goto LAB102;

LAB111:    xsi_set_current_line(178, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(179, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB112;
    goto LAB1;

LAB112:    xsi_set_current_line(181, ng0);

LAB113:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB117;

LAB114:    if (t16 != 0)
        goto LAB116;

LAB115:    *((unsigned int *)t4) = 1;

LAB117:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB118;

LAB119:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    memset(t4, 0, 8);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB122;

LAB123:    if (*((unsigned int *)t5) != 0)
        goto LAB124;

LAB125:    t19 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = (!(t12));
    t14 = *((unsigned int *)t19);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB126;

LAB127:    memcpy(t32, t4, 8);

LAB128:    t57 = (t32 + 4);
    t58 = *((unsigned int *)t57);
    t59 = (~(t58));
    t60 = *((unsigned int *)t32);
    t61 = (t60 & t59);
    t62 = (t61 != 0);
    if (t62 > 0)
        goto LAB136;

LAB137:
LAB138:    xsi_set_current_line(191, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(192, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(193, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB140;
    goto LAB1;

LAB116:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB117;

LAB118:    xsi_set_current_line(181, ng0);

LAB120:    xsi_set_current_line(182, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB121;
    goto LAB1;

LAB121:    goto LAB113;

LAB122:    *((unsigned int *)t4) = 1;
    goto LAB125;

LAB124:    t6 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB125;

LAB126:    t20 = (t0 + 1208U);
    t26 = *((char **)t20);
    t20 = ((char*)((ng7)));
    xsi_vlog_unsigned_not_equal(t28, 128, t26, 128, t20, 128);
    memset(t29, 0, 8);
    t30 = (t28 + 4);
    t16 = *((unsigned int *)t30);
    t17 = (~(t16));
    t18 = *((unsigned int *)t28);
    t21 = (t18 & t17);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t30) != 0)
        goto LAB131;

LAB132:    t23 = *((unsigned int *)t4);
    t24 = *((unsigned int *)t29);
    t25 = (t23 | t24);
    *((unsigned int *)t32) = t25;
    t33 = (t4 + 4);
    t34 = (t29 + 4);
    t35 = (t32 + 4);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = *((unsigned int *)t35);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB133;

LAB134:
LAB135:    goto LAB128;

LAB129:    *((unsigned int *)t29) = 1;
    goto LAB132;

LAB131:    t31 = (t29 + 4);
    *((unsigned int *)t29) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB132;

LAB133:    t41 = *((unsigned int *)t32);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t32) = (t41 | t42);
    t43 = (t4 + 4);
    t44 = (t29 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (~(t45));
    t47 = *((unsigned int *)t4);
    t48 = (t47 & t46);
    t49 = *((unsigned int *)t44);
    t50 = (~(t49));
    t51 = *((unsigned int *)t29);
    t52 = (t51 & t50);
    t53 = (~(t48));
    t54 = (~(t52));
    t55 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t55 & t53);
    t56 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t56 & t54);
    goto LAB135;

LAB136:    xsi_set_current_line(185, ng0);

LAB139:    xsi_set_current_line(186, ng0);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    goto LAB138;

LAB140:    xsi_set_current_line(194, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(195, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB141;
    goto LAB1;

LAB141:    xsi_set_current_line(197, ng0);

LAB142:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB146;

LAB143:    if (t16 != 0)
        goto LAB145;

LAB144:    *((unsigned int *)t4) = 1;

LAB146:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB147;

LAB148:    xsi_set_current_line(202, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 128);
    xsi_set_current_line(203, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(204, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB151;
    goto LAB1;

LAB145:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB146;

LAB147:    xsi_set_current_line(197, ng0);

LAB149:    xsi_set_current_line(198, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB150;
    goto LAB1;

LAB150:    goto LAB142;

LAB151:    xsi_set_current_line(205, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(206, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB152;
    goto LAB1;

LAB152:    xsi_set_current_line(208, ng0);

LAB153:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB157;

LAB154:    if (t16 != 0)
        goto LAB156;

LAB155:    *((unsigned int *)t4) = 1;

LAB157:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB158;

LAB159:    xsi_set_current_line(213, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(214, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB162;
    goto LAB1;

LAB156:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB157;

LAB158:    xsi_set_current_line(208, ng0);

LAB160:    xsi_set_current_line(209, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB161;
    goto LAB1;

LAB161:    goto LAB153;

LAB162:    xsi_set_current_line(215, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(216, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB163;
    goto LAB1;

LAB163:    xsi_set_current_line(218, ng0);

LAB164:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB168;

LAB165:    if (t16 != 0)
        goto LAB167;

LAB166:    *((unsigned int *)t4) = 1;

LAB168:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB169;

LAB170:    xsi_set_current_line(222, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB173;

LAB174:
LAB175:    xsi_set_current_line(226, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(227, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB177;
    goto LAB1;

LAB167:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB168;

LAB169:    xsi_set_current_line(218, ng0);

LAB171:    xsi_set_current_line(219, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB172;
    goto LAB1;

LAB172:    goto LAB164;

LAB173:    xsi_set_current_line(222, ng0);

LAB176:    xsi_set_current_line(223, ng0);
    t6 = ((char*)((ng4)));
    t19 = (t0 + 1048U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng11, 3, t0, (char)118, t6, 128, (char)118, t20, 128);
    goto LAB175;

LAB177:    xsi_set_current_line(228, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 4576);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB178;
    goto LAB1;

LAB178:    xsi_set_current_line(231, ng0);

LAB179:    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB183;

LAB180:    if (t16 != 0)
        goto LAB182;

LAB181:    *((unsigned int *)t4) = 1;

LAB183:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB184;

LAB185:    xsi_set_current_line(235, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng10)));
    xsi_vlog_unsigned_not_equal(t27, 128, t3, 128, t2, 128);
    t5 = (t27 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t27);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB188;

LAB189:
LAB190:    goto LAB1;

LAB182:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB183;

LAB184:    xsi_set_current_line(231, ng0);

LAB186:    xsi_set_current_line(232, ng0);
    t26 = (t0 + 4576);
    xsi_process_wait(t26, 10000LL);
    *((char **)t1) = &&LAB187;
    goto LAB1;

LAB187:    goto LAB179;

LAB188:    xsi_set_current_line(235, ng0);

LAB191:    xsi_set_current_line(236, ng0);
    t6 = ((char*)((ng10)));
    t19 = (t0 + 1048U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, 0, ng11, 3, t0, (char)118, t6, 128, (char)118, t20, 128);
    goto LAB190;

}

static void Always_240_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;

LAB0:    t1 = (t0 + 5016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(240, ng0);

LAB4:    xsi_set_current_line(241, ng0);
    t2 = (t0 + 1928);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t6) == 0)
        goto LAB5;

LAB7:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB8:    t13 = (t3 + 4);
    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (~(t15));
    *((unsigned int *)t3) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB10;

LAB9:    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 7760);
    memset(t23, 0, 8);
    t24 = 1U;
    t25 = t24;
    t26 = (t3 + 4);
    t27 = *((unsigned int *)t3);
    t24 = (t24 & t27);
    t28 = *((unsigned int *)t26);
    t25 = (t25 & t28);
    t29 = (t23 + 4);
    t30 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t30 | t24);
    t31 = *((unsigned int *)t29);
    *((unsigned int *)t29) = (t31 | t25);
    t32 = (t0 + 4824);
    xsi_process_wait(t32, 5000LL);
    *((char **)t1) = &&LAB11;

LAB1:    return;
LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t3) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB9;

LAB11:    t33 = (t0 + 7760);
    t34 = (t0 + 1928);
    xsi_vlogvar_assign_value(t34, t33, 0, 0, 1);
    goto LAB2;

}


extern void work_m_00000000000426256732_2066474725_init()
{
	static char *pe[] = {(void *)Initial_47_0,(void *)Always_240_1};
	xsi_register_didat("work_m_00000000000426256732_2066474725", "isim/BRAM_CTRL_TB_isim_beh.exe.sim/work/m_00000000000426256732_2066474725.didat");
	xsi_register_executes(pe);
}
