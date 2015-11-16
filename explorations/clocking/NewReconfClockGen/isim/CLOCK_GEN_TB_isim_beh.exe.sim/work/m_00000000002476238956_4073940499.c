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
static const char *ng0 = "C:/Users/dkhoury/Desktop/SourceTree-Masters/explorations/clocking/NewReconfClockGen/SYNCHRONIZER.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1000U, 0U};
static unsigned int ng3[] = {1U, 0U};



static void Always_15_0(char *t0)
{
    char t13[8];
    char t20[8];
    char t30[8];
    char t57[8];
    char t70[8];
    char t77[8];
    char t109[8];
    char t123[8];
    char t130[8];
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
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
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
    unsigned int t48;
    int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t69;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    char *t81;
    char *t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    int t101;
    int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    char *t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    char *t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t122;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    char *t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    int t154;
    int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    char *t162;

LAB0:    t1 = (t0 + 3328U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(15, ng0);
    t2 = (t0 + 3648);
    *((int *)t2) = 1;
    t3 = (t0 + 3360);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(15, ng0);

LAB5:    xsi_set_current_line(16, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(20, ng0);

LAB10:    xsi_set_current_line(21, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t13, 0, 8);
    t11 = (t4 + 4);
    if (*((unsigned int *)t11) != 0)
        goto LAB12;

LAB11:    t12 = (t5 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB13;

LAB14:    t15 = (t13 + 4);
    t6 = *((unsigned int *)t15);
    t7 = (~(t6));
    t8 = *((unsigned int *)t13);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(25, ng0);

LAB20:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    memset(t13, 0, 8);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t2) != 0)
        goto LAB23;

LAB24:    t5 = (t13 + 4);
    t22 = *((unsigned int *)t13);
    t23 = *((unsigned int *)t5);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB25;

LAB26:    memcpy(t30, t13, 8);

LAB27:    memset(t57, 0, 8);
    t21 = (t30 + 4);
    t58 = *((unsigned int *)t21);
    t59 = (~(t58));
    t60 = *((unsigned int *)t30);
    t61 = (t60 & t59);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t21) != 0)
        goto LAB37;

LAB38:    t64 = (t57 + 4);
    t65 = *((unsigned int *)t57);
    t66 = *((unsigned int *)t64);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB39;

LAB40:    memcpy(t77, t57, 8);

LAB41:    memset(t109, 0, 8);
    t110 = (t77 + 4);
    t111 = *((unsigned int *)t110);
    t112 = (~(t111));
    t113 = *((unsigned int *)t77);
    t114 = (t113 & t112);
    t115 = (t114 & 1U);
    if (t115 != 0)
        goto LAB49;

LAB50:    if (*((unsigned int *)t110) != 0)
        goto LAB51;

LAB52:    t117 = (t109 + 4);
    t118 = *((unsigned int *)t109);
    t119 = *((unsigned int *)t117);
    t120 = (t118 || t119);
    if (t120 > 0)
        goto LAB53;

LAB54:    memcpy(t130, t109, 8);

LAB55:    t162 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t162, t130, 0, 0, 1, 0LL);

LAB18:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(16, ng0);

LAB9:    xsi_set_current_line(17, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 1, 0LL);
    xsi_set_current_line(18, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 10, 0LL);
    goto LAB8;

LAB12:    t14 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB14;

LAB13:    *((unsigned int *)t13) = 1;
    goto LAB14;

LAB16:    xsi_set_current_line(21, ng0);

LAB19:    xsi_set_current_line(22, ng0);
    t16 = (t0 + 2408);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng3)));
    memset(t20, 0, 8);
    xsi_vlog_unsigned_add(t20, 10, t18, 10, t19, 10);
    t21 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t21, t20, 0, 0, 10, 0LL);
    xsi_set_current_line(23, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB18;

LAB21:    *((unsigned int *)t13) = 1;
    goto LAB24;

LAB23:    t4 = (t13 + 4);
    *((unsigned int *)t13) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB24;

LAB25:    t11 = (t0 + 1528U);
    t12 = *((char **)t11);
    memset(t20, 0, 8);
    t11 = (t12 + 4);
    t25 = *((unsigned int *)t11);
    t26 = (~(t25));
    t27 = *((unsigned int *)t12);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t11) != 0)
        goto LAB30;

LAB31:    t31 = *((unsigned int *)t13);
    t32 = *((unsigned int *)t20);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t15 = (t13 + 4);
    t16 = (t20 + 4);
    t17 = (t30 + 4);
    t34 = *((unsigned int *)t15);
    t35 = *((unsigned int *)t16);
    t36 = (t34 | t35);
    *((unsigned int *)t17) = t36;
    t37 = *((unsigned int *)t17);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB32;

LAB33:
LAB34:    goto LAB27;

LAB28:    *((unsigned int *)t20) = 1;
    goto LAB31;

LAB30:    t14 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB31;

LAB32:    t39 = *((unsigned int *)t30);
    t40 = *((unsigned int *)t17);
    *((unsigned int *)t30) = (t39 | t40);
    t18 = (t13 + 4);
    t19 = (t20 + 4);
    t41 = *((unsigned int *)t13);
    t42 = (~(t41));
    t43 = *((unsigned int *)t18);
    t44 = (~(t43));
    t45 = *((unsigned int *)t20);
    t46 = (~(t45));
    t47 = *((unsigned int *)t19);
    t48 = (~(t47));
    t49 = (t42 & t44);
    t50 = (t46 & t48);
    t51 = (~(t49));
    t52 = (~(t50));
    t53 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t53 & t51);
    t54 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t54 & t52);
    t55 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t55 & t51);
    t56 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t56 & t52);
    goto LAB34;

LAB35:    *((unsigned int *)t57) = 1;
    goto LAB38;

LAB37:    t63 = (t57 + 4);
    *((unsigned int *)t57) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB38;

LAB39:    t68 = (t0 + 1688U);
    t69 = *((char **)t68);
    memset(t70, 0, 8);
    t68 = (t69 + 4);
    t71 = *((unsigned int *)t68);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (t73 & t72);
    t75 = (t74 & 1U);
    if (t75 != 0)
        goto LAB42;

LAB43:    if (*((unsigned int *)t68) != 0)
        goto LAB44;

LAB45:    t78 = *((unsigned int *)t57);
    t79 = *((unsigned int *)t70);
    t80 = (t78 & t79);
    *((unsigned int *)t77) = t80;
    t81 = (t57 + 4);
    t82 = (t70 + 4);
    t83 = (t77 + 4);
    t84 = *((unsigned int *)t81);
    t85 = *((unsigned int *)t82);
    t86 = (t84 | t85);
    *((unsigned int *)t83) = t86;
    t87 = *((unsigned int *)t83);
    t88 = (t87 != 0);
    if (t88 == 1)
        goto LAB46;

LAB47:
LAB48:    goto LAB41;

LAB42:    *((unsigned int *)t70) = 1;
    goto LAB45;

LAB44:    t76 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t76) = 1;
    goto LAB45;

LAB46:    t89 = *((unsigned int *)t77);
    t90 = *((unsigned int *)t83);
    *((unsigned int *)t77) = (t89 | t90);
    t91 = (t57 + 4);
    t92 = (t70 + 4);
    t93 = *((unsigned int *)t57);
    t94 = (~(t93));
    t95 = *((unsigned int *)t91);
    t96 = (~(t95));
    t97 = *((unsigned int *)t70);
    t98 = (~(t97));
    t99 = *((unsigned int *)t92);
    t100 = (~(t99));
    t101 = (t94 & t96);
    t102 = (t98 & t100);
    t103 = (~(t101));
    t104 = (~(t102));
    t105 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t105 & t103);
    t106 = *((unsigned int *)t83);
    *((unsigned int *)t83) = (t106 & t104);
    t107 = *((unsigned int *)t77);
    *((unsigned int *)t77) = (t107 & t103);
    t108 = *((unsigned int *)t77);
    *((unsigned int *)t77) = (t108 & t104);
    goto LAB48;

LAB49:    *((unsigned int *)t109) = 1;
    goto LAB52;

LAB51:    t116 = (t109 + 4);
    *((unsigned int *)t109) = 1;
    *((unsigned int *)t116) = 1;
    goto LAB52;

LAB53:    t121 = (t0 + 1848U);
    t122 = *((char **)t121);
    memset(t123, 0, 8);
    t121 = (t122 + 4);
    t124 = *((unsigned int *)t121);
    t125 = (~(t124));
    t126 = *((unsigned int *)t122);
    t127 = (t126 & t125);
    t128 = (t127 & 1U);
    if (t128 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t121) != 0)
        goto LAB58;

LAB59:    t131 = *((unsigned int *)t109);
    t132 = *((unsigned int *)t123);
    t133 = (t131 & t132);
    *((unsigned int *)t130) = t133;
    t134 = (t109 + 4);
    t135 = (t123 + 4);
    t136 = (t130 + 4);
    t137 = *((unsigned int *)t134);
    t138 = *((unsigned int *)t135);
    t139 = (t137 | t138);
    *((unsigned int *)t136) = t139;
    t140 = *((unsigned int *)t136);
    t141 = (t140 != 0);
    if (t141 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB55;

LAB56:    *((unsigned int *)t123) = 1;
    goto LAB59;

LAB58:    t129 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t129) = 1;
    goto LAB59;

LAB60:    t142 = *((unsigned int *)t130);
    t143 = *((unsigned int *)t136);
    *((unsigned int *)t130) = (t142 | t143);
    t144 = (t109 + 4);
    t145 = (t123 + 4);
    t146 = *((unsigned int *)t109);
    t147 = (~(t146));
    t148 = *((unsigned int *)t144);
    t149 = (~(t148));
    t150 = *((unsigned int *)t123);
    t151 = (~(t150));
    t152 = *((unsigned int *)t145);
    t153 = (~(t152));
    t154 = (t147 & t149);
    t155 = (t151 & t153);
    t156 = (~(t154));
    t157 = (~(t155));
    t158 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t158 & t156);
    t159 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t159 & t157);
    t160 = *((unsigned int *)t130);
    *((unsigned int *)t130) = (t160 & t156);
    t161 = *((unsigned int *)t130);
    *((unsigned int *)t130) = (t161 & t157);
    goto LAB62;

}


extern void work_m_00000000002476238956_4073940499_init()
{
	static char *pe[] = {(void *)Always_15_0};
	xsi_register_didat("work_m_00000000002476238956_4073940499", "isim/CLOCK_GEN_TB_isim_beh.exe.sim/work/m_00000000002476238956_4073940499.didat");
	xsi_register_executes(pe);
}
