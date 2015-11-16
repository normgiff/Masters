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
static int ng0[] = {1, 0};
static int ng1[] = {0, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static const char *ng4 = "Attribute Syntax Error : The attribute INIT on ODDR2 instance %m is set to %d.  Legal values for this attribute are 0 or 1.";
static int ng5[] = {1313820229, 0};
static int ng6[] = {17200, 0};
static int ng7[] = {17201, 0};
static const char *ng8 = "Attribute Syntax Error : The attribute DDR_ALIGNMENT on ODDR2 instance %m is set to %s.  Legal values for this attribute are NONE, C0 or C1.";
static int ng9[] = {1398361667, 0, 65, 0};
static int ng10[] = {1398361667, 0, 0, 0};
static const char *ng11 = "Attribute Syntax Error : The attribute SRTYPE on ODDR2 instance %m is set to %s.  Legal values for this attribute are ASYNC or SYNC.";

static void NetReassign_75_11(char *);
static void NetReassign_76_12(char *);
static void NetReassign_86_13(char *);
static void NetReassign_87_14(char *);
static void NetReassign_90_15(char *);
static void NetReassign_91_16(char *);


static int PathDecl_190_9(char *t1)
{
    int t0;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;

LAB0:    t2 = (t1 + 1616U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t4 = *((unsigned int *)t2);
    t5 = (~(t4));
    t6 = *((unsigned int *)t3);
    t7 = (t6 & t5);
    t8 = (t7 != 0);
    t0 = t8;

LAB1:    return t0;
}

static int PathDecl_191_10(char *t1)
{
    int t0;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;

LAB0:    t2 = (t1 + 1776U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t4 = *((unsigned int *)t2);
    t5 = (~(t4));
    t6 = *((unsigned int *)t3);
    t7 = (t6 & t5);
    t8 = (t7 != 0);
    t0 = t8;

LAB1:    return t0;
}

static void NetDecl_33_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 4216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 10296);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 8152);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 0U);
    t18 = (t0 + 8008);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Gate_41_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 4464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8216);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t6, 0, 8);
    t7 = 1U;
    t8 = t7;
    t9 = ((((char*)((ng0)))) + 0);
    t10 = ((((char*)((ng0)))) + 4);
    t11 = *((unsigned int *)t9);
    t7 = (t7 & t11);
    t12 = *((unsigned int *)t10);
    t8 = (t8 & t12);
    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t14 | t7);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t8);
    t16 = (t0 + 8216);
    xsi_driver_vfirst_trans(t16, 0, 0);

LAB1:    return;
}

static void Gate_42_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 4712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8280);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t6, 0, 8);
    t7 = 1U;
    t8 = t7;
    t9 = ((((char*)((ng1)))) + 0);
    t10 = ((((char*)((ng1)))) + 4);
    t11 = *((unsigned int *)t9);
    t7 = (t7 & t11);
    t12 = *((unsigned int *)t10);
    t8 = (t8 & t12);
    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t14 | t7);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t8);
    t16 = (t0 + 8280);
    xsi_driver_vfirst_trans(t16, 0, 0);

LAB1:    return;
}

static void Gate_43_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 4960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t6, 0, 8);
    t7 = 1U;
    t8 = t7;
    t9 = ((((char*)((ng1)))) + 0);
    t10 = ((((char*)((ng1)))) + 4);
    t11 = *((unsigned int *)t9);
    t7 = (t7 & t11);
    t12 = *((unsigned int *)t10);
    t8 = (t8 & t12);
    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t14 | t7);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t8);
    t16 = (t0 + 8344);
    xsi_driver_vfirst_trans(t16, 0, 0);

LAB1:    return;
}

static void Gate_48_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 5208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3136);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8408);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 4);
    t11 = (t4 + 4);
    if (*((unsigned int *)t11) == 1)
        goto LAB4;

LAB5:    t12 = *((unsigned int *)t4);
    t13 = (t12 & 1);
    *((unsigned int *)t9) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;

LAB6:    t16 = (t0 + 8408);
    xsi_driver_vfirst_trans(t16, 0, 0);
    t17 = (t0 + 8024);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t9) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB6;

}

static void Initial_51_5(char *t0)
{
    char t3[8];
    char t19[8];
    char t33[8];
    char t49[8];
    char t57[8];
    char t97[8];
    char t103[8];
    char t119[8];
    char t127[8];
    char t167[16];
    char t168[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
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
    char *t18;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    int t81;
    int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    char *t104;
    char *t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t131;
    char *t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    int t151;
    int t152;
    unsigned int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    char *t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    char *t165;
    char *t166;

LAB0:
LAB2:    t1 = (t0 + 608);
    t2 = *((char **)t1);
    t1 = ((char*)((ng2)));
    memset(t3, 0, 8);
    t4 = (t2 + 4);
    t5 = (t1 + 4);
    t6 = *((unsigned int *)t2);
    t7 = *((unsigned int *)t1);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = (t8 | t11);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 | t14);
    t16 = (~(t15));
    t17 = (t12 & t16);
    if (t17 != 0)
        goto LAB4;

LAB3:    if (t15 != 0)
        goto LAB5;

LAB6:    memset(t19, 0, 8);
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t3);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB7;

LAB8:    if (*((unsigned int *)t20) != 0)
        goto LAB9;

LAB10:    t27 = (t19 + 4);
    t28 = *((unsigned int *)t19);
    t29 = *((unsigned int *)t27);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB11;

LAB12:    memcpy(t57, t19, 8);

LAB13:    t89 = (t57 + 4);
    t90 = *((unsigned int *)t89);
    t91 = (~(t90));
    t92 = *((unsigned int *)t57);
    t93 = (t92 & t91);
    t94 = (t93 != 0);
    if (t94 > 0)
        goto LAB25;

LAB26:
LAB27:    t1 = (t0 + 472);
    t2 = *((char **)t1);
    t1 = ((char*)((ng5)));
    memset(t3, 0, 8);
    t4 = (t2 + 4);
    t5 = (t1 + 4);
    t6 = *((unsigned int *)t2);
    t7 = *((unsigned int *)t1);
    t8 = (t6 ^ t7);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = (t8 | t11);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t5);
    t15 = (t13 | t14);
    t16 = (~(t15));
    t17 = (t12 & t16);
    if (t17 != 0)
        goto LAB30;

LAB29:    if (t15 != 0)
        goto LAB31;

LAB32:    memset(t19, 0, 8);
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t3);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB33;

LAB34:    if (*((unsigned int *)t20) != 0)
        goto LAB35;

LAB36:    t27 = (t19 + 4);
    t28 = *((unsigned int *)t19);
    t29 = *((unsigned int *)t27);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB37;

LAB38:    memcpy(t57, t19, 8);

LAB39:    memset(t97, 0, 8);
    t89 = (t57 + 4);
    t90 = *((unsigned int *)t89);
    t91 = (~(t90));
    t92 = *((unsigned int *)t57);
    t93 = (t92 & t91);
    t94 = (t93 & 1U);
    if (t94 != 0)
        goto LAB51;

LAB52:    if (*((unsigned int *)t89) != 0)
        goto LAB53;

LAB54:    t96 = (t97 + 4);
    t98 = *((unsigned int *)t97);
    t99 = *((unsigned int *)t96);
    t100 = (t98 || t99);
    if (t100 > 0)
        goto LAB55;

LAB56:    memcpy(t127, t97, 8);

LAB57:    t159 = (t127 + 4);
    t160 = *((unsigned int *)t159);
    t161 = (~(t160));
    t162 = *((unsigned int *)t127);
    t163 = (t162 & t161);
    t164 = (t163 != 0);
    if (t164 > 0)
        goto LAB69;

LAB70:
LAB71:    t1 = (t0 + 744);
    t2 = *((char **)t1);
    t1 = ((char*)((ng9)));
    xsi_vlog_unsigned_not_equal(t167, 40, t2, 40, t1, 40);
    memset(t3, 0, 8);
    t4 = (t167 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t167);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB73;

LAB74:    if (*((unsigned int *)t4) != 0)
        goto LAB75;

LAB76:    t18 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t18);
    t13 = (t11 || t12);
    if (t13 > 0)
        goto LAB77;

LAB78:    memcpy(t33, t3, 8);

LAB79:    t56 = (t33 + 4);
    t58 = *((unsigned int *)t56);
    t59 = (~(t58));
    t60 = *((unsigned int *)t33);
    t64 = (t60 & t59);
    t65 = (t64 != 0);
    if (t65 > 0)
        goto LAB87;

LAB88:
LAB89:
LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB6;

LAB5:    t18 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB6;

LAB7:    *((unsigned int *)t19) = 1;
    goto LAB10;

LAB9:    t26 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB10;

LAB11:    t31 = (t0 + 608);
    t32 = *((char **)t31);
    t31 = ((char*)((ng3)));
    memset(t33, 0, 8);
    t34 = (t32 + 4);
    t35 = (t31 + 4);
    t36 = *((unsigned int *)t32);
    t37 = *((unsigned int *)t31);
    t38 = (t36 ^ t37);
    t39 = *((unsigned int *)t34);
    t40 = *((unsigned int *)t35);
    t41 = (t39 ^ t40);
    t42 = (t38 | t41);
    t43 = *((unsigned int *)t34);
    t44 = *((unsigned int *)t35);
    t45 = (t43 | t44);
    t46 = (~(t45));
    t47 = (t42 & t46);
    if (t47 != 0)
        goto LAB15;

LAB14:    if (t45 != 0)
        goto LAB16;

LAB17:    memset(t49, 0, 8);
    t50 = (t33 + 4);
    t51 = *((unsigned int *)t50);
    t52 = (~(t51));
    t53 = *((unsigned int *)t33);
    t54 = (t53 & t52);
    t55 = (t54 & 1U);
    if (t55 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t50) != 0)
        goto LAB20;

LAB21:    t58 = *((unsigned int *)t19);
    t59 = *((unsigned int *)t49);
    t60 = (t58 & t59);
    *((unsigned int *)t57) = t60;
    t61 = (t19 + 4);
    t62 = (t49 + 4);
    t63 = (t57 + 4);
    t64 = *((unsigned int *)t61);
    t65 = *((unsigned int *)t62);
    t66 = (t64 | t65);
    *((unsigned int *)t63) = t66;
    t67 = *((unsigned int *)t63);
    t68 = (t67 != 0);
    if (t68 == 1)
        goto LAB22;

LAB23:
LAB24:    goto LAB13;

LAB15:    *((unsigned int *)t33) = 1;
    goto LAB17;

LAB16:    t48 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t48) = 1;
    goto LAB17;

LAB18:    *((unsigned int *)t49) = 1;
    goto LAB21;

LAB20:    t56 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t56) = 1;
    goto LAB21;

LAB22:    t69 = *((unsigned int *)t57);
    t70 = *((unsigned int *)t63);
    *((unsigned int *)t57) = (t69 | t70);
    t71 = (t19 + 4);
    t72 = (t49 + 4);
    t73 = *((unsigned int *)t19);
    t74 = (~(t73));
    t75 = *((unsigned int *)t71);
    t76 = (~(t75));
    t77 = *((unsigned int *)t49);
    t78 = (~(t77));
    t79 = *((unsigned int *)t72);
    t80 = (~(t79));
    t81 = (t74 & t76);
    t82 = (t78 & t80);
    t83 = (~(t81));
    t84 = (~(t82));
    t85 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t85 & t83);
    t86 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t86 & t84);
    t87 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t87 & t83);
    t88 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t88 & t84);
    goto LAB24;

LAB25:
LAB28:    t95 = (t0 + 608);
    t96 = *((char **)t95);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t96, 1);
    xsi_vlog_finish(1);
    goto LAB27;

LAB30:    *((unsigned int *)t3) = 1;
    goto LAB32;

LAB31:    t18 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB32;

LAB33:    *((unsigned int *)t19) = 1;
    goto LAB36;

LAB35:    t26 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB36;

LAB37:    t31 = (t0 + 472);
    t32 = *((char **)t31);
    t31 = ((char*)((ng6)));
    memset(t33, 0, 8);
    t34 = (t32 + 4);
    t35 = (t31 + 4);
    t36 = *((unsigned int *)t32);
    t37 = *((unsigned int *)t31);
    t38 = (t36 ^ t37);
    t39 = *((unsigned int *)t34);
    t40 = *((unsigned int *)t35);
    t41 = (t39 ^ t40);
    t42 = (t38 | t41);
    t43 = *((unsigned int *)t34);
    t44 = *((unsigned int *)t35);
    t45 = (t43 | t44);
    t46 = (~(t45));
    t47 = (t42 & t46);
    if (t47 != 0)
        goto LAB41;

LAB40:    if (t45 != 0)
        goto LAB42;

LAB43:    memset(t49, 0, 8);
    t50 = (t33 + 4);
    t51 = *((unsigned int *)t50);
    t52 = (~(t51));
    t53 = *((unsigned int *)t33);
    t54 = (t53 & t52);
    t55 = (t54 & 1U);
    if (t55 != 0)
        goto LAB44;

LAB45:    if (*((unsigned int *)t50) != 0)
        goto LAB46;

LAB47:    t58 = *((unsigned int *)t19);
    t59 = *((unsigned int *)t49);
    t60 = (t58 & t59);
    *((unsigned int *)t57) = t60;
    t61 = (t19 + 4);
    t62 = (t49 + 4);
    t63 = (t57 + 4);
    t64 = *((unsigned int *)t61);
    t65 = *((unsigned int *)t62);
    t66 = (t64 | t65);
    *((unsigned int *)t63) = t66;
    t67 = *((unsigned int *)t63);
    t68 = (t67 != 0);
    if (t68 == 1)
        goto LAB48;

LAB49:
LAB50:    goto LAB39;

LAB41:    *((unsigned int *)t33) = 1;
    goto LAB43;

LAB42:    t48 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t48) = 1;
    goto LAB43;

LAB44:    *((unsigned int *)t49) = 1;
    goto LAB47;

LAB46:    t56 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t56) = 1;
    goto LAB47;

LAB48:    t69 = *((unsigned int *)t57);
    t70 = *((unsigned int *)t63);
    *((unsigned int *)t57) = (t69 | t70);
    t71 = (t19 + 4);
    t72 = (t49 + 4);
    t73 = *((unsigned int *)t19);
    t74 = (~(t73));
    t75 = *((unsigned int *)t71);
    t76 = (~(t75));
    t77 = *((unsigned int *)t49);
    t78 = (~(t77));
    t79 = *((unsigned int *)t72);
    t80 = (~(t79));
    t81 = (t74 & t76);
    t82 = (t78 & t80);
    t83 = (~(t81));
    t84 = (~(t82));
    t85 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t85 & t83);
    t86 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t86 & t84);
    t87 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t87 & t83);
    t88 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t88 & t84);
    goto LAB50;

LAB51:    *((unsigned int *)t97) = 1;
    goto LAB54;

LAB53:    t95 = (t97 + 4);
    *((unsigned int *)t97) = 1;
    *((unsigned int *)t95) = 1;
    goto LAB54;

LAB55:    t101 = (t0 + 472);
    t102 = *((char **)t101);
    t101 = ((char*)((ng7)));
    memset(t103, 0, 8);
    t104 = (t102 + 4);
    t105 = (t101 + 4);
    t106 = *((unsigned int *)t102);
    t107 = *((unsigned int *)t101);
    t108 = (t106 ^ t107);
    t109 = *((unsigned int *)t104);
    t110 = *((unsigned int *)t105);
    t111 = (t109 ^ t110);
    t112 = (t108 | t111);
    t113 = *((unsigned int *)t104);
    t114 = *((unsigned int *)t105);
    t115 = (t113 | t114);
    t116 = (~(t115));
    t117 = (t112 & t116);
    if (t117 != 0)
        goto LAB59;

LAB58:    if (t115 != 0)
        goto LAB60;

LAB61:    memset(t119, 0, 8);
    t120 = (t103 + 4);
    t121 = *((unsigned int *)t120);
    t122 = (~(t121));
    t123 = *((unsigned int *)t103);
    t124 = (t123 & t122);
    t125 = (t124 & 1U);
    if (t125 != 0)
        goto LAB62;

LAB63:    if (*((unsigned int *)t120) != 0)
        goto LAB64;

LAB65:    t128 = *((unsigned int *)t97);
    t129 = *((unsigned int *)t119);
    t130 = (t128 & t129);
    *((unsigned int *)t127) = t130;
    t131 = (t97 + 4);
    t132 = (t119 + 4);
    t133 = (t127 + 4);
    t134 = *((unsigned int *)t131);
    t135 = *((unsigned int *)t132);
    t136 = (t134 | t135);
    *((unsigned int *)t133) = t136;
    t137 = *((unsigned int *)t133);
    t138 = (t137 != 0);
    if (t138 == 1)
        goto LAB66;

LAB67:
LAB68:    goto LAB57;

LAB59:    *((unsigned int *)t103) = 1;
    goto LAB61;

LAB60:    t118 = (t103 + 4);
    *((unsigned int *)t103) = 1;
    *((unsigned int *)t118) = 1;
    goto LAB61;

LAB62:    *((unsigned int *)t119) = 1;
    goto LAB65;

LAB64:    t126 = (t119 + 4);
    *((unsigned int *)t119) = 1;
    *((unsigned int *)t126) = 1;
    goto LAB65;

LAB66:    t139 = *((unsigned int *)t127);
    t140 = *((unsigned int *)t133);
    *((unsigned int *)t127) = (t139 | t140);
    t141 = (t97 + 4);
    t142 = (t119 + 4);
    t143 = *((unsigned int *)t97);
    t144 = (~(t143));
    t145 = *((unsigned int *)t141);
    t146 = (~(t145));
    t147 = *((unsigned int *)t119);
    t148 = (~(t147));
    t149 = *((unsigned int *)t142);
    t150 = (~(t149));
    t151 = (t144 & t146);
    t152 = (t148 & t150);
    t153 = (~(t151));
    t154 = (~(t152));
    t155 = *((unsigned int *)t133);
    *((unsigned int *)t133) = (t155 & t153);
    t156 = *((unsigned int *)t133);
    *((unsigned int *)t133) = (t156 & t154);
    t157 = *((unsigned int *)t127);
    *((unsigned int *)t127) = (t157 & t153);
    t158 = *((unsigned int *)t127);
    *((unsigned int *)t127) = (t158 & t154);
    goto LAB68;

LAB69:
LAB72:    t165 = (t0 + 472);
    t166 = *((char **)t165);
    xsi_vlogfile_write(1, 0, 0, ng8, 2, t0, (char)118, t166, 32);
    xsi_vlog_finish(1);
    goto LAB71;

LAB73:    *((unsigned int *)t3) = 1;
    goto LAB76;

LAB75:    t5 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB76;

LAB77:    t20 = (t0 + 744);
    t26 = *((char **)t20);
    t20 = ((char*)((ng10)));
    xsi_vlog_unsigned_not_equal(t168, 40, t26, 40, t20, 40);
    memset(t19, 0, 8);
    t27 = (t168 + 4);
    t14 = *((unsigned int *)t27);
    t15 = (~(t14));
    t16 = *((unsigned int *)t168);
    t17 = (t16 & t15);
    t21 = (t17 & 1U);
    if (t21 != 0)
        goto LAB80;

LAB81:    if (*((unsigned int *)t27) != 0)
        goto LAB82;

LAB83:    t22 = *((unsigned int *)t3);
    t23 = *((unsigned int *)t19);
    t24 = (t22 & t23);
    *((unsigned int *)t33) = t24;
    t32 = (t3 + 4);
    t34 = (t19 + 4);
    t35 = (t33 + 4);
    t25 = *((unsigned int *)t32);
    t28 = *((unsigned int *)t34);
    t29 = (t25 | t28);
    *((unsigned int *)t35) = t29;
    t30 = *((unsigned int *)t35);
    t36 = (t30 != 0);
    if (t36 == 1)
        goto LAB84;

LAB85:
LAB86:    goto LAB79;

LAB80:    *((unsigned int *)t19) = 1;
    goto LAB83;

LAB82:    t31 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB83;

LAB84:    t37 = *((unsigned int *)t33);
    t38 = *((unsigned int *)t35);
    *((unsigned int *)t33) = (t37 | t38);
    t48 = (t3 + 4);
    t50 = (t19 + 4);
    t39 = *((unsigned int *)t3);
    t40 = (~(t39));
    t41 = *((unsigned int *)t48);
    t42 = (~(t41));
    t43 = *((unsigned int *)t19);
    t44 = (~(t43));
    t45 = *((unsigned int *)t50);
    t46 = (~(t45));
    t81 = (t40 & t42);
    t82 = (t44 & t46);
    t47 = (~(t81));
    t51 = (~(t82));
    t52 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t52 & t47);
    t53 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t47);
    t55 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t55 & t51);
    goto LAB86;

LAB87:
LAB90:    t61 = (t0 + 744);
    t62 = *((char **)t61);
    xsi_vlogfile_write(1, 0, 0, ng11, 2, t0, (char)118, t62, 40);
    xsi_vlog_finish(1);
    goto LAB89;

}

static void Always_71_6(char *t0)
{
    char t6[8];
    char t30[16];
    char t37[8];
    char t38[8];
    char t51[8];
    char t59[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
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
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    int t83;
    int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;

LAB0:    t1 = (t0 + 5704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8040);
    *((int *)t2) = 1;
    t3 = (t0 + 5736);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 2416U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB14:    t2 = (t0 + 3136);
    xsi_vlogvar_deassign(t2, 0, 0);
    t2 = (t0 + 3296);
    xsi_vlogvar_deassign(t2, 0, 0);
    t2 = (t0 + 744);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    xsi_vlog_unsigned_equal(t30, 40, t3, 40, t2, 40);
    t4 = (t30 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (~(t9));
    t11 = *((unsigned int *)t30);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB15;

LAB16:
LAB17:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:
LAB13:    t28 = (t0 + 3136);
    xsi_set_assignedflag(t28);
    t29 = (t0 + 10304);
    *((int *)t29) = 1;
    NetReassign_75_11(t0);
    t2 = (t0 + 3296);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 10308);
    *((int *)t3) = 1;
    NetReassign_76_12(t0);
    goto LAB12;

LAB15:
LAB18:    t5 = (t0 + 2576U);
    t7 = *((char **)t5);
    t5 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t8 = (t7 + 4);
    t21 = (t5 + 4);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t5);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t8);
    t18 = *((unsigned int *)t21);
    t19 = (t17 ^ t18);
    t20 = (t16 | t19);
    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t21);
    t25 = (t23 | t24);
    t26 = (~(t25));
    t27 = (t20 & t26);
    if (t27 != 0)
        goto LAB22;

LAB19:    if (t25 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t6) = 1;

LAB22:    t28 = (t6 + 4);
    t31 = *((unsigned int *)t28);
    t32 = (~(t31));
    t33 = *((unsigned int *)t6);
    t34 = (t33 & t32);
    t35 = (t34 != 0);
    if (t35 > 0)
        goto LAB23;

LAB24:    t2 = (t0 + 2576U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB30;

LAB27:    if (t18 != 0)
        goto LAB29;

LAB28:    *((unsigned int *)t6) = 1;

LAB30:    memset(t37, 0, 8);
    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t8) != 0)
        goto LAB33;

LAB34:    t22 = (t37 + 4);
    t31 = *((unsigned int *)t37);
    t32 = *((unsigned int *)t22);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB35;

LAB36:    memcpy(t59, t37, 8);

LAB37:    t91 = (t59 + 4);
    t92 = *((unsigned int *)t91);
    t93 = (~(t92));
    t94 = *((unsigned int *)t59);
    t95 = (t94 & t93);
    t96 = (t95 != 0);
    if (t96 > 0)
        goto LAB49;

LAB50:
LAB51:
LAB25:    goto LAB17;

LAB21:    t22 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB22;

LAB23:
LAB26:    t29 = (t0 + 3136);
    xsi_set_assignedflag(t29);
    t36 = (t0 + 10312);
    *((int *)t36) = 1;
    NetReassign_86_13(t0);
    t2 = (t0 + 3296);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 10316);
    *((int *)t3) = 1;
    NetReassign_87_14(t0);
    goto LAB25;

LAB29:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB30;

LAB31:    *((unsigned int *)t37) = 1;
    goto LAB34;

LAB33:    t21 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB34;

LAB35:    t28 = (t0 + 2736U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng0)));
    memset(t38, 0, 8);
    t36 = (t29 + 4);
    t39 = (t28 + 4);
    t34 = *((unsigned int *)t29);
    t35 = *((unsigned int *)t28);
    t40 = (t34 ^ t35);
    t41 = *((unsigned int *)t36);
    t42 = *((unsigned int *)t39);
    t43 = (t41 ^ t42);
    t44 = (t40 | t43);
    t45 = *((unsigned int *)t36);
    t46 = *((unsigned int *)t39);
    t47 = (t45 | t46);
    t48 = (~(t47));
    t49 = (t44 & t48);
    if (t49 != 0)
        goto LAB41;

LAB38:    if (t47 != 0)
        goto LAB40;

LAB39:    *((unsigned int *)t38) = 1;

LAB41:    memset(t51, 0, 8);
    t52 = (t38 + 4);
    t53 = *((unsigned int *)t52);
    t54 = (~(t53));
    t55 = *((unsigned int *)t38);
    t56 = (t55 & t54);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t52) != 0)
        goto LAB44;

LAB45:    t60 = *((unsigned int *)t37);
    t61 = *((unsigned int *)t51);
    t62 = (t60 & t61);
    *((unsigned int *)t59) = t62;
    t63 = (t37 + 4);
    t64 = (t51 + 4);
    t65 = (t59 + 4);
    t66 = *((unsigned int *)t63);
    t67 = *((unsigned int *)t64);
    t68 = (t66 | t67);
    *((unsigned int *)t65) = t68;
    t69 = *((unsigned int *)t65);
    t70 = (t69 != 0);
    if (t70 == 1)
        goto LAB46;

LAB47:
LAB48:    goto LAB37;

LAB40:    t50 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB41;

LAB42:    *((unsigned int *)t51) = 1;
    goto LAB45;

LAB44:    t58 = (t51 + 4);
    *((unsigned int *)t51) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB45;

LAB46:    t71 = *((unsigned int *)t59);
    t72 = *((unsigned int *)t65);
    *((unsigned int *)t59) = (t71 | t72);
    t73 = (t37 + 4);
    t74 = (t51 + 4);
    t75 = *((unsigned int *)t37);
    t76 = (~(t75));
    t77 = *((unsigned int *)t73);
    t78 = (~(t77));
    t79 = *((unsigned int *)t51);
    t80 = (~(t79));
    t81 = *((unsigned int *)t74);
    t82 = (~(t81));
    t83 = (t76 & t78);
    t84 = (t80 & t82);
    t85 = (~(t83));
    t86 = (~(t84));
    t87 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t87 & t85);
    t88 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t88 & t86);
    t89 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t89 & t85);
    t90 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t90 & t86);
    goto LAB48;

LAB49:
LAB52:    t97 = (t0 + 3136);
    xsi_set_assignedflag(t97);
    t98 = (t0 + 10320);
    *((int *)t98) = 1;
    NetReassign_90_15(t0);
    t2 = (t0 + 3296);
    xsi_set_assignedflag(t2);
    t3 = (t0 + 10324);
    *((int *)t3) = 1;
    NetReassign_91_16(t0);
    goto LAB51;

}

static void Always_105_7(char *t0)
{
    char t6[8];
    char t22[8];
    char t36[16];
    char t37[8];
    char t45[8];
    char t85[8];
    char t93[8];
    char t105[8];
    char t113[8];
    char t153[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
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
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t103;
    char *t104;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    int t137;
    int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;

LAB0:    t1 = (t0 + 5952U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8056);
    *((int *)t2) = 1;
    t3 = (t0 + 5984);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 2576U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB14;

LAB15:    memcpy(t45, t22, 8);

LAB16:    t77 = (t45 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB24;

LAB25:    t2 = (t0 + 2576U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB31;

LAB28:    if (t18 != 0)
        goto LAB30;

LAB29:    *((unsigned int *)t6) = 1;

LAB31:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t8) != 0)
        goto LAB34;

LAB35:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB36;

LAB37:    memcpy(t85, t22, 8);

LAB38:    memset(t93, 0, 8);
    t83 = (t85 + 4);
    t94 = *((unsigned int *)t83);
    t95 = (~(t94));
    t96 = *((unsigned int *)t85);
    t97 = (t96 & t95);
    t98 = (t97 & 1U);
    if (t98 != 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t83) != 0)
        goto LAB52;

LAB53:    t99 = (t93 + 4);
    t100 = *((unsigned int *)t93);
    t101 = *((unsigned int *)t99);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB54;

LAB55:    memcpy(t113, t93, 8);

LAB56:    t145 = (t113 + 4);
    t146 = *((unsigned int *)t145);
    t147 = (~(t146));
    t148 = *((unsigned int *)t113);
    t149 = (t148 & t147);
    t150 = (t149 != 0);
    if (t150 > 0)
        goto LAB64;

LAB65:    t2 = (t0 + 1936U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB71;

LAB68:    if (t18 != 0)
        goto LAB70;

LAB69:    *((unsigned int *)t6) = 1;

LAB71:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t8) != 0)
        goto LAB74;

LAB75:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB76;

LAB77:    memcpy(t85, t22, 8);

LAB78:    memset(t93, 0, 8);
    t83 = (t85 + 4);
    t94 = *((unsigned int *)t83);
    t95 = (~(t94));
    t96 = *((unsigned int *)t85);
    t97 = (t96 & t95);
    t98 = (t97 & 1U);
    if (t98 != 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t83) != 0)
        goto LAB92;

LAB93:    t99 = (t93 + 4);
    t100 = *((unsigned int *)t93);
    t101 = *((unsigned int *)t99);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB94;

LAB95:    memcpy(t153, t93, 8);

LAB96:    t161 = (t153 + 4);
    t162 = *((unsigned int *)t161);
    t163 = (~(t162));
    t164 = *((unsigned int *)t153);
    t165 = (t164 & t163);
    t166 = (t165 != 0);
    if (t166 > 0)
        goto LAB108;

LAB109:
LAB110:
LAB66:
LAB26:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t22) = 1;
    goto LAB13;

LAB12:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t34 = (t0 + 744);
    t35 = *((char **)t34);
    t34 = ((char*)((ng10)));
    xsi_vlog_unsigned_equal(t36, 40, t35, 40, t34, 40);
    memset(t37, 0, 8);
    t38 = (t36 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t36);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t38) != 0)
        goto LAB19;

LAB20:    t46 = *((unsigned int *)t22);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t22 + 4);
    t50 = (t37 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t37) = 1;
    goto LAB20;

LAB19:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB20;

LAB21:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t22 + 4);
    t60 = (t37 + 4);
    t61 = *((unsigned int *)t22);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB23;

LAB24:
LAB27:    t83 = ((char*)((ng1)));
    t84 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t84, t83, 0, 0, 1, 0LL);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB26;

LAB30:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB31;

LAB32:    *((unsigned int *)t22) = 1;
    goto LAB35;

LAB34:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB35;

LAB36:    t29 = (t0 + 2736U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng0)));
    memset(t37, 0, 8);
    t34 = (t30 + 4);
    t35 = (t29 + 4);
    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t29);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t35);
    t46 = (t42 ^ t43);
    t47 = (t41 | t46);
    t48 = *((unsigned int *)t34);
    t52 = *((unsigned int *)t35);
    t53 = (t48 | t52);
    t54 = (~(t53));
    t55 = (t47 & t54);
    if (t55 != 0)
        goto LAB42;

LAB39:    if (t53 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t37) = 1;

LAB42:    memset(t45, 0, 8);
    t44 = (t37 + 4);
    t56 = *((unsigned int *)t44);
    t57 = (~(t56));
    t58 = *((unsigned int *)t37);
    t61 = (t58 & t57);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t44) != 0)
        goto LAB45;

LAB46:    t63 = *((unsigned int *)t22);
    t64 = *((unsigned int *)t45);
    t65 = (t63 & t64);
    *((unsigned int *)t85) = t65;
    t50 = (t22 + 4);
    t51 = (t45 + 4);
    t59 = (t85 + 4);
    t66 = *((unsigned int *)t50);
    t67 = *((unsigned int *)t51);
    t68 = (t66 | t67);
    *((unsigned int *)t59) = t68;
    t71 = *((unsigned int *)t59);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB47;

LAB48:
LAB49:    goto LAB38;

LAB41:    t38 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t45) = 1;
    goto LAB46;

LAB45:    t49 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB46;

LAB47:    t73 = *((unsigned int *)t85);
    t74 = *((unsigned int *)t59);
    *((unsigned int *)t85) = (t73 | t74);
    t60 = (t22 + 4);
    t77 = (t45 + 4);
    t75 = *((unsigned int *)t22);
    t76 = (~(t75));
    t78 = *((unsigned int *)t60);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t86 = (~(t82));
    t69 = (t76 & t79);
    t70 = (t81 & t86);
    t87 = (~(t69));
    t88 = (~(t70));
    t89 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t89 & t87);
    t90 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t90 & t88);
    t91 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t91 & t87);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t92 & t88);
    goto LAB49;

LAB50:    *((unsigned int *)t93) = 1;
    goto LAB53;

LAB52:    t84 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB53;

LAB54:    t103 = (t0 + 744);
    t104 = *((char **)t103);
    t103 = ((char*)((ng10)));
    xsi_vlog_unsigned_equal(t36, 40, t104, 40, t103, 40);
    memset(t105, 0, 8);
    t106 = (t36 + 4);
    t107 = *((unsigned int *)t106);
    t108 = (~(t107));
    t109 = *((unsigned int *)t36);
    t110 = (t109 & t108);
    t111 = (t110 & 1U);
    if (t111 != 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t106) != 0)
        goto LAB59;

LAB60:    t114 = *((unsigned int *)t93);
    t115 = *((unsigned int *)t105);
    t116 = (t114 & t115);
    *((unsigned int *)t113) = t116;
    t117 = (t93 + 4);
    t118 = (t105 + 4);
    t119 = (t113 + 4);
    t120 = *((unsigned int *)t117);
    t121 = *((unsigned int *)t118);
    t122 = (t120 | t121);
    *((unsigned int *)t119) = t122;
    t123 = *((unsigned int *)t119);
    t124 = (t123 != 0);
    if (t124 == 1)
        goto LAB61;

LAB62:
LAB63:    goto LAB56;

LAB57:    *((unsigned int *)t105) = 1;
    goto LAB60;

LAB59:    t112 = (t105 + 4);
    *((unsigned int *)t105) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB60;

LAB61:    t125 = *((unsigned int *)t113);
    t126 = *((unsigned int *)t119);
    *((unsigned int *)t113) = (t125 | t126);
    t127 = (t93 + 4);
    t128 = (t105 + 4);
    t129 = *((unsigned int *)t93);
    t130 = (~(t129));
    t131 = *((unsigned int *)t127);
    t132 = (~(t131));
    t133 = *((unsigned int *)t105);
    t134 = (~(t133));
    t135 = *((unsigned int *)t128);
    t136 = (~(t135));
    t137 = (t130 & t132);
    t138 = (t134 & t136);
    t139 = (~(t137));
    t140 = (~(t138));
    t141 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t141 & t139);
    t142 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t142 & t140);
    t143 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t143 & t139);
    t144 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t144 & t140);
    goto LAB63;

LAB64:
LAB67:    t151 = ((char*)((ng0)));
    t152 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t152, t151, 0, 0, 1, 0LL);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 3296);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB66;

LAB70:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB71;

LAB72:    *((unsigned int *)t22) = 1;
    goto LAB75;

LAB74:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB75;

LAB76:    t29 = (t0 + 2576U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng1)));
    memset(t37, 0, 8);
    t34 = (t30 + 4);
    t35 = (t29 + 4);
    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t29);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t35);
    t46 = (t42 ^ t43);
    t47 = (t41 | t46);
    t48 = *((unsigned int *)t34);
    t52 = *((unsigned int *)t35);
    t53 = (t48 | t52);
    t54 = (~(t53));
    t55 = (t47 & t54);
    if (t55 != 0)
        goto LAB82;

LAB79:    if (t53 != 0)
        goto LAB81;

LAB80:    *((unsigned int *)t37) = 1;

LAB82:    memset(t45, 0, 8);
    t44 = (t37 + 4);
    t56 = *((unsigned int *)t44);
    t57 = (~(t56));
    t58 = *((unsigned int *)t37);
    t61 = (t58 & t57);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t44) != 0)
        goto LAB85;

LAB86:    t63 = *((unsigned int *)t22);
    t64 = *((unsigned int *)t45);
    t65 = (t63 & t64);
    *((unsigned int *)t85) = t65;
    t50 = (t22 + 4);
    t51 = (t45 + 4);
    t59 = (t85 + 4);
    t66 = *((unsigned int *)t50);
    t67 = *((unsigned int *)t51);
    t68 = (t66 | t67);
    *((unsigned int *)t59) = t68;
    t71 = *((unsigned int *)t59);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB87;

LAB88:
LAB89:    goto LAB78;

LAB81:    t38 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB82;

LAB83:    *((unsigned int *)t45) = 1;
    goto LAB86;

LAB85:    t49 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB86;

LAB87:    t73 = *((unsigned int *)t85);
    t74 = *((unsigned int *)t59);
    *((unsigned int *)t85) = (t73 | t74);
    t60 = (t22 + 4);
    t77 = (t45 + 4);
    t75 = *((unsigned int *)t22);
    t76 = (~(t75));
    t78 = *((unsigned int *)t60);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t86 = (~(t82));
    t69 = (t76 & t79);
    t70 = (t81 & t86);
    t87 = (~(t69));
    t88 = (~(t70));
    t89 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t89 & t87);
    t90 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t90 & t88);
    t91 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t91 & t87);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t92 & t88);
    goto LAB89;

LAB90:    *((unsigned int *)t93) = 1;
    goto LAB93;

LAB92:    t84 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB93;

LAB94:    t103 = (t0 + 2736U);
    t104 = *((char **)t103);
    t103 = ((char*)((ng1)));
    memset(t105, 0, 8);
    t106 = (t104 + 4);
    t112 = (t103 + 4);
    t107 = *((unsigned int *)t104);
    t108 = *((unsigned int *)t103);
    t109 = (t107 ^ t108);
    t110 = *((unsigned int *)t106);
    t111 = *((unsigned int *)t112);
    t114 = (t110 ^ t111);
    t115 = (t109 | t114);
    t116 = *((unsigned int *)t106);
    t120 = *((unsigned int *)t112);
    t121 = (t116 | t120);
    t122 = (~(t121));
    t123 = (t115 & t122);
    if (t123 != 0)
        goto LAB100;

LAB97:    if (t121 != 0)
        goto LAB99;

LAB98:    *((unsigned int *)t105) = 1;

LAB100:    memset(t113, 0, 8);
    t118 = (t105 + 4);
    t124 = *((unsigned int *)t118);
    t125 = (~(t124));
    t126 = *((unsigned int *)t105);
    t129 = (t126 & t125);
    t130 = (t129 & 1U);
    if (t130 != 0)
        goto LAB101;

LAB102:    if (*((unsigned int *)t118) != 0)
        goto LAB103;

LAB104:    t131 = *((unsigned int *)t93);
    t132 = *((unsigned int *)t113);
    t133 = (t131 & t132);
    *((unsigned int *)t153) = t133;
    t127 = (t93 + 4);
    t128 = (t113 + 4);
    t145 = (t153 + 4);
    t134 = *((unsigned int *)t127);
    t135 = *((unsigned int *)t128);
    t136 = (t134 | t135);
    *((unsigned int *)t145) = t136;
    t139 = *((unsigned int *)t145);
    t140 = (t139 != 0);
    if (t140 == 1)
        goto LAB105;

LAB106:
LAB107:    goto LAB96;

LAB99:    t117 = (t105 + 4);
    *((unsigned int *)t105) = 1;
    *((unsigned int *)t117) = 1;
    goto LAB100;

LAB101:    *((unsigned int *)t113) = 1;
    goto LAB104;

LAB103:    t119 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB104;

LAB105:    t141 = *((unsigned int *)t153);
    t142 = *((unsigned int *)t145);
    *((unsigned int *)t153) = (t141 | t142);
    t151 = (t93 + 4);
    t152 = (t113 + 4);
    t143 = *((unsigned int *)t93);
    t144 = (~(t143));
    t146 = *((unsigned int *)t151);
    t147 = (~(t146));
    t148 = *((unsigned int *)t113);
    t149 = (~(t148));
    t150 = *((unsigned int *)t152);
    t154 = (~(t150));
    t137 = (t144 & t147);
    t138 = (t149 & t154);
    t155 = (~(t137));
    t156 = (~(t138));
    t157 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t157 & t155);
    t158 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t158 & t156);
    t159 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t159 & t155);
    t160 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t160 & t156);
    goto LAB107;

LAB108:
LAB111:    t167 = (t0 + 2096U);
    t168 = *((char **)t167);
    t167 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t167, t168, 0, 0, 1, 0LL);
    t2 = (t0 + 2256U);
    t3 = *((char **)t2);
    t2 = (t0 + 3296);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    goto LAB110;

}

static void Always_123_8(char *t0)
{
    char t6[8];
    char t22[8];
    char t36[16];
    char t37[8];
    char t45[8];
    char t85[8];
    char t93[8];
    char t105[8];
    char t113[8];
    char t153[8];
    char t169[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
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
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t103;
    char *t104;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t117;
    char *t118;
    char *t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    int t137;
    int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    char *t151;
    char *t152;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;
    char *t170;
    char *t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    char *t184;
    char *t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    char *t191;
    char *t192;

LAB0:    t1 = (t0 + 6200U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 8072);
    *((int *)t2) = 1;
    t3 = (t0 + 6232);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 2576U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    memset(t22, 0, 8);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t30);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB14;

LAB15:    memcpy(t45, t22, 8);

LAB16:    t77 = (t45 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB24;

LAB25:    t2 = (t0 + 2576U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB31;

LAB28:    if (t18 != 0)
        goto LAB30;

LAB29:    *((unsigned int *)t6) = 1;

LAB31:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t8) != 0)
        goto LAB34;

LAB35:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB36;

LAB37:    memcpy(t85, t22, 8);

LAB38:    memset(t93, 0, 8);
    t83 = (t85 + 4);
    t94 = *((unsigned int *)t83);
    t95 = (~(t94));
    t96 = *((unsigned int *)t85);
    t97 = (t96 & t95);
    t98 = (t97 & 1U);
    if (t98 != 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t83) != 0)
        goto LAB52;

LAB53:    t99 = (t93 + 4);
    t100 = *((unsigned int *)t93);
    t101 = *((unsigned int *)t99);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB54;

LAB55:    memcpy(t113, t93, 8);

LAB56:    t145 = (t113 + 4);
    t146 = *((unsigned int *)t145);
    t147 = (~(t146));
    t148 = *((unsigned int *)t113);
    t149 = (t148 & t147);
    t150 = (t149 != 0);
    if (t150 > 0)
        goto LAB64;

LAB65:    t2 = (t0 + 1936U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng0)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB71;

LAB68:    if (t18 != 0)
        goto LAB70;

LAB69:    *((unsigned int *)t6) = 1;

LAB71:    memset(t22, 0, 8);
    t8 = (t6 + 4);
    t24 = *((unsigned int *)t8);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t8) != 0)
        goto LAB74;

LAB75:    t23 = (t22 + 4);
    t31 = *((unsigned int *)t22);
    t32 = *((unsigned int *)t23);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB76;

LAB77:    memcpy(t85, t22, 8);

LAB78:    memset(t93, 0, 8);
    t83 = (t85 + 4);
    t94 = *((unsigned int *)t83);
    t95 = (~(t94));
    t96 = *((unsigned int *)t85);
    t97 = (t96 & t95);
    t98 = (t97 & 1U);
    if (t98 != 0)
        goto LAB90;

LAB91:    if (*((unsigned int *)t83) != 0)
        goto LAB92;

LAB93:    t99 = (t93 + 4);
    t100 = *((unsigned int *)t93);
    t101 = *((unsigned int *)t99);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB94;

LAB95:    memcpy(t153, t93, 8);

LAB96:    t161 = (t153 + 4);
    t162 = *((unsigned int *)t161);
    t163 = (~(t162));
    t164 = *((unsigned int *)t153);
    t165 = (t164 & t163);
    t166 = (t165 != 0);
    if (t166 > 0)
        goto LAB108;

LAB109:
LAB110:
LAB66:
LAB26:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t22) = 1;
    goto LAB13;

LAB12:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t34 = (t0 + 744);
    t35 = *((char **)t34);
    t34 = ((char*)((ng10)));
    xsi_vlog_unsigned_equal(t36, 40, t35, 40, t34, 40);
    memset(t37, 0, 8);
    t38 = (t36 + 4);
    t39 = *((unsigned int *)t38);
    t40 = (~(t39));
    t41 = *((unsigned int *)t36);
    t42 = (t41 & t40);
    t43 = (t42 & 1U);
    if (t43 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t38) != 0)
        goto LAB19;

LAB20:    t46 = *((unsigned int *)t22);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t22 + 4);
    t50 = (t37 + 4);
    t51 = (t45 + 4);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t37) = 1;
    goto LAB20;

LAB19:    t44 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t44) = 1;
    goto LAB20;

LAB21:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t22 + 4);
    t60 = (t37 + 4);
    t61 = *((unsigned int *)t22);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB23;

LAB24:
LAB27:    t83 = ((char*)((ng1)));
    t84 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t84, t83, 0, 0, 1, 0LL);
    goto LAB26;

LAB30:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB31;

LAB32:    *((unsigned int *)t22) = 1;
    goto LAB35;

LAB34:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB35;

LAB36:    t29 = (t0 + 2736U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng0)));
    memset(t37, 0, 8);
    t34 = (t30 + 4);
    t35 = (t29 + 4);
    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t29);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t35);
    t46 = (t42 ^ t43);
    t47 = (t41 | t46);
    t48 = *((unsigned int *)t34);
    t52 = *((unsigned int *)t35);
    t53 = (t48 | t52);
    t54 = (~(t53));
    t55 = (t47 & t54);
    if (t55 != 0)
        goto LAB42;

LAB39:    if (t53 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t37) = 1;

LAB42:    memset(t45, 0, 8);
    t44 = (t37 + 4);
    t56 = *((unsigned int *)t44);
    t57 = (~(t56));
    t58 = *((unsigned int *)t37);
    t61 = (t58 & t57);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t44) != 0)
        goto LAB45;

LAB46:    t63 = *((unsigned int *)t22);
    t64 = *((unsigned int *)t45);
    t65 = (t63 & t64);
    *((unsigned int *)t85) = t65;
    t50 = (t22 + 4);
    t51 = (t45 + 4);
    t59 = (t85 + 4);
    t66 = *((unsigned int *)t50);
    t67 = *((unsigned int *)t51);
    t68 = (t66 | t67);
    *((unsigned int *)t59) = t68;
    t71 = *((unsigned int *)t59);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB47;

LAB48:
LAB49:    goto LAB38;

LAB41:    t38 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t45) = 1;
    goto LAB46;

LAB45:    t49 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB46;

LAB47:    t73 = *((unsigned int *)t85);
    t74 = *((unsigned int *)t59);
    *((unsigned int *)t85) = (t73 | t74);
    t60 = (t22 + 4);
    t77 = (t45 + 4);
    t75 = *((unsigned int *)t22);
    t76 = (~(t75));
    t78 = *((unsigned int *)t60);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t86 = (~(t82));
    t69 = (t76 & t79);
    t70 = (t81 & t86);
    t87 = (~(t69));
    t88 = (~(t70));
    t89 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t89 & t87);
    t90 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t90 & t88);
    t91 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t91 & t87);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t92 & t88);
    goto LAB49;

LAB50:    *((unsigned int *)t93) = 1;
    goto LAB53;

LAB52:    t84 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB53;

LAB54:    t103 = (t0 + 744);
    t104 = *((char **)t103);
    t103 = ((char*)((ng10)));
    xsi_vlog_unsigned_equal(t36, 40, t104, 40, t103, 40);
    memset(t105, 0, 8);
    t106 = (t36 + 4);
    t107 = *((unsigned int *)t106);
    t108 = (~(t107));
    t109 = *((unsigned int *)t36);
    t110 = (t109 & t108);
    t111 = (t110 & 1U);
    if (t111 != 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t106) != 0)
        goto LAB59;

LAB60:    t114 = *((unsigned int *)t93);
    t115 = *((unsigned int *)t105);
    t116 = (t114 & t115);
    *((unsigned int *)t113) = t116;
    t117 = (t93 + 4);
    t118 = (t105 + 4);
    t119 = (t113 + 4);
    t120 = *((unsigned int *)t117);
    t121 = *((unsigned int *)t118);
    t122 = (t120 | t121);
    *((unsigned int *)t119) = t122;
    t123 = *((unsigned int *)t119);
    t124 = (t123 != 0);
    if (t124 == 1)
        goto LAB61;

LAB62:
LAB63:    goto LAB56;

LAB57:    *((unsigned int *)t105) = 1;
    goto LAB60;

LAB59:    t112 = (t105 + 4);
    *((unsigned int *)t105) = 1;
    *((unsigned int *)t112) = 1;
    goto LAB60;

LAB61:    t125 = *((unsigned int *)t113);
    t126 = *((unsigned int *)t119);
    *((unsigned int *)t113) = (t125 | t126);
    t127 = (t93 + 4);
    t128 = (t105 + 4);
    t129 = *((unsigned int *)t93);
    t130 = (~(t129));
    t131 = *((unsigned int *)t127);
    t132 = (~(t131));
    t133 = *((unsigned int *)t105);
    t134 = (~(t133));
    t135 = *((unsigned int *)t128);
    t136 = (~(t135));
    t137 = (t130 & t132);
    t138 = (t134 & t136);
    t139 = (~(t137));
    t140 = (~(t138));
    t141 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t141 & t139);
    t142 = *((unsigned int *)t119);
    *((unsigned int *)t119) = (t142 & t140);
    t143 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t143 & t139);
    t144 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t144 & t140);
    goto LAB63;

LAB64:
LAB67:    t151 = ((char*)((ng0)));
    t152 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t152, t151, 0, 0, 1, 0LL);
    goto LAB66;

LAB70:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB71;

LAB72:    *((unsigned int *)t22) = 1;
    goto LAB75;

LAB74:    t21 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB75;

LAB76:    t29 = (t0 + 2576U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng1)));
    memset(t37, 0, 8);
    t34 = (t30 + 4);
    t35 = (t29 + 4);
    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t29);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t34);
    t43 = *((unsigned int *)t35);
    t46 = (t42 ^ t43);
    t47 = (t41 | t46);
    t48 = *((unsigned int *)t34);
    t52 = *((unsigned int *)t35);
    t53 = (t48 | t52);
    t54 = (~(t53));
    t55 = (t47 & t54);
    if (t55 != 0)
        goto LAB82;

LAB79:    if (t53 != 0)
        goto LAB81;

LAB80:    *((unsigned int *)t37) = 1;

LAB82:    memset(t45, 0, 8);
    t44 = (t37 + 4);
    t56 = *((unsigned int *)t44);
    t57 = (~(t56));
    t58 = *((unsigned int *)t37);
    t61 = (t58 & t57);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB83;

LAB84:    if (*((unsigned int *)t44) != 0)
        goto LAB85;

LAB86:    t63 = *((unsigned int *)t22);
    t64 = *((unsigned int *)t45);
    t65 = (t63 & t64);
    *((unsigned int *)t85) = t65;
    t50 = (t22 + 4);
    t51 = (t45 + 4);
    t59 = (t85 + 4);
    t66 = *((unsigned int *)t50);
    t67 = *((unsigned int *)t51);
    t68 = (t66 | t67);
    *((unsigned int *)t59) = t68;
    t71 = *((unsigned int *)t59);
    t72 = (t71 != 0);
    if (t72 == 1)
        goto LAB87;

LAB88:
LAB89:    goto LAB78;

LAB81:    t38 = (t37 + 4);
    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB82;

LAB83:    *((unsigned int *)t45) = 1;
    goto LAB86;

LAB85:    t49 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB86;

LAB87:    t73 = *((unsigned int *)t85);
    t74 = *((unsigned int *)t59);
    *((unsigned int *)t85) = (t73 | t74);
    t60 = (t22 + 4);
    t77 = (t45 + 4);
    t75 = *((unsigned int *)t22);
    t76 = (~(t75));
    t78 = *((unsigned int *)t60);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t86 = (~(t82));
    t69 = (t76 & t79);
    t70 = (t81 & t86);
    t87 = (~(t69));
    t88 = (~(t70));
    t89 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t89 & t87);
    t90 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t90 & t88);
    t91 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t91 & t87);
    t92 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t92 & t88);
    goto LAB89;

LAB90:    *((unsigned int *)t93) = 1;
    goto LAB93;

LAB92:    t84 = (t93 + 4);
    *((unsigned int *)t93) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB93;

LAB94:    t103 = (t0 + 2736U);
    t104 = *((char **)t103);
    t103 = ((char*)((ng1)));
    memset(t105, 0, 8);
    t106 = (t104 + 4);
    t112 = (t103 + 4);
    t107 = *((unsigned int *)t104);
    t108 = *((unsigned int *)t103);
    t109 = (t107 ^ t108);
    t110 = *((unsigned int *)t106);
    t111 = *((unsigned int *)t112);
    t114 = (t110 ^ t111);
    t115 = (t109 | t114);
    t116 = *((unsigned int *)t106);
    t120 = *((unsigned int *)t112);
    t121 = (t116 | t120);
    t122 = (~(t121));
    t123 = (t115 & t122);
    if (t123 != 0)
        goto LAB100;

LAB97:    if (t121 != 0)
        goto LAB99;

LAB98:    *((unsigned int *)t105) = 1;

LAB100:    memset(t113, 0, 8);
    t118 = (t105 + 4);
    t124 = *((unsigned int *)t118);
    t125 = (~(t124));
    t126 = *((unsigned int *)t105);
    t129 = (t126 & t125);
    t130 = (t129 & 1U);
    if (t130 != 0)
        goto LAB101;

LAB102:    if (*((unsigned int *)t118) != 0)
        goto LAB103;

LAB104:    t131 = *((unsigned int *)t93);
    t132 = *((unsigned int *)t113);
    t133 = (t131 & t132);
    *((unsigned int *)t153) = t133;
    t127 = (t93 + 4);
    t128 = (t113 + 4);
    t145 = (t153 + 4);
    t134 = *((unsigned int *)t127);
    t135 = *((unsigned int *)t128);
    t136 = (t134 | t135);
    *((unsigned int *)t145) = t136;
    t139 = *((unsigned int *)t145);
    t140 = (t139 != 0);
    if (t140 == 1)
        goto LAB105;

LAB106:
LAB107:    goto LAB96;

LAB99:    t117 = (t105 + 4);
    *((unsigned int *)t105) = 1;
    *((unsigned int *)t117) = 1;
    goto LAB100;

LAB101:    *((unsigned int *)t113) = 1;
    goto LAB104;

LAB103:    t119 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB104;

LAB105:    t141 = *((unsigned int *)t153);
    t142 = *((unsigned int *)t145);
    *((unsigned int *)t153) = (t141 | t142);
    t151 = (t93 + 4);
    t152 = (t113 + 4);
    t143 = *((unsigned int *)t93);
    t144 = (~(t143));
    t146 = *((unsigned int *)t151);
    t147 = (~(t146));
    t148 = *((unsigned int *)t113);
    t149 = (~(t148));
    t150 = *((unsigned int *)t152);
    t154 = (~(t150));
    t137 = (t144 & t147);
    t138 = (t149 & t154);
    t155 = (~(t137));
    t156 = (~(t138));
    t157 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t157 & t155);
    t158 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t158 & t156);
    t159 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t159 & t155);
    t160 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t160 & t156);
    goto LAB107;

LAB108:
LAB111:    t167 = (t0 + 472);
    t168 = *((char **)t167);
    t167 = ((char*)((ng5)));
    memset(t169, 0, 8);
    t170 = (t168 + 4);
    t171 = (t167 + 4);
    t172 = *((unsigned int *)t168);
    t173 = *((unsigned int *)t167);
    t174 = (t172 ^ t173);
    t175 = *((unsigned int *)t170);
    t176 = *((unsigned int *)t171);
    t177 = (t175 ^ t176);
    t178 = (t174 | t177);
    t179 = *((unsigned int *)t170);
    t180 = *((unsigned int *)t171);
    t181 = (t179 | t180);
    t182 = (~(t181));
    t183 = (t178 & t182);
    if (t183 != 0)
        goto LAB115;

LAB112:    if (t181 != 0)
        goto LAB114;

LAB113:    *((unsigned int *)t169) = 1;

LAB115:    t185 = (t169 + 4);
    t186 = *((unsigned int *)t185);
    t187 = (~(t186));
    t188 = *((unsigned int *)t169);
    t189 = (t188 & t187);
    t190 = (t189 != 0);
    if (t190 > 0)
        goto LAB116;

LAB117:    t2 = (t0 + 3296);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);

LAB118:    goto LAB110;

LAB114:    t184 = (t169 + 4);
    *((unsigned int *)t169) = 1;
    *((unsigned int *)t184) = 1;
    goto LAB115;

LAB116:    t191 = (t0 + 2256U);
    t192 = *((char **)t191);
    t191 = (t0 + 3136);
    xsi_vlogvar_wait_assign_value(t191, t192, 0, 0, 1, 0LL);
    goto LAB118;

}

static void NetReassign_75_11(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 6448U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t3 = 0;
    t2 = (t0 + 608);
    t4 = *((char **)t2);
    t2 = (t0 + 10304);
    if (*((int *)t2) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 3136);
    xsi_vlogvar_assignassignvalue(t5, t4, 0, 0, 0, 1, ((int*)(t2)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_76_12(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 6696U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t3 = 0;
    t2 = (t0 + 608);
    t4 = *((char **)t2);
    t2 = (t0 + 10308);
    if (*((int *)t2) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 3296);
    xsi_vlogvar_assignassignvalue(t5, t4, 0, 0, 0, 1, ((int*)(t2)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_86_13(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 6944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t3 = 0;
    t2 = ((char*)((ng1)));
    t4 = (t0 + 10312);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 3136);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_87_14(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 7192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t3 = 0;
    t2 = ((char*)((ng1)));
    t4 = (t0 + 10316);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 3296);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_90_15(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 7440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t3 = 0;
    t2 = ((char*)((ng0)));
    t4 = (t0 + 10320);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 3136);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}

static void NetReassign_91_16(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 7688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t3 = 0;
    t2 = ((char*)((ng0)));
    t4 = (t0 + 10324);
    if (*((int *)t4) > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    t5 = (t0 + 3296);
    xsi_vlogvar_assignassignvalue(t5, t2, 0, 0, 0, 1, ((int*)(t4)));
    t3 = 1;
    goto LAB5;

}


extern void unisims_ver_m_00000000002304772977_1565319552_init()
{
	static char *pe[] = {(void *)NetDecl_33_0,(void *)Gate_41_1,(void *)Gate_42_2,(void *)Gate_43_3,(void *)Gate_48_4,(void *)Initial_51_5,(void *)Always_71_6,(void *)Always_105_7,(void *)Always_123_8,(void *)NetReassign_75_11,(void *)NetReassign_76_12,(void *)NetReassign_86_13,(void *)NetReassign_87_14,(void *)NetReassign_90_15,(void *)NetReassign_91_16};
	xsi_register_didat("unisims_ver_m_00000000002304772977_1565319552", "isim/CLOCK_GEN_TB_isim_beh.exe.sim/unisims_ver/m_00000000002304772977_1565319552.didat");
	xsi_register_executes(pe);
	xsi_register_modpathfunc(0, (void *)PathDecl_190_9);
	xsi_register_modpathfunc(1, (void *)PathDecl_191_10);
}
