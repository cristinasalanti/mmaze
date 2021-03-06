#pragma once

#include <stdint.h>

#include <armv6m.h>
/*
 * http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0432c/CHDCICDF.html
 *
 * 0: 5 cycles
 * 1: 9 cycles
 * n: (n + 1) * 4 + 1 cycles
 *
 * Max delay: 0x400000001 cycles (17179869185)
 */
static inline void delay_cycles_p1x4(uint32_t ct)
{
	__asm__ __volatile__ (
		".thumb \n\t"
		".syntax unified \n\t"
		"1:	subs %0, %0, #1 \n\t" /* 1 cycle */
		"	bne 1b \n\t"	/* 3 for all but last (1) */
		"       nop \n\t"
		"	nop \n\t"
		"	nop \n\t"
	: "=l" (ct)	/* outputs */
	: "0" (ct)	/* inputs */
	: "cc"		/* clobbers */
	);
}

/*
 * minimum delay: 4 cycles
 * granularity: 4 cycles
 * accuracy: +1,-3
 *
 * maximum delay: with arg=0, 0xffffffff cycles
 *
 *  (x + 1) * 4 = cycles
 *  cycles / 4 = x + 1
 *  cycles / 4 - 1 = x
 */
__attribute__((__always_inline__))
static inline void delay_cycles(uint32_t cycles)
{
	delay_cycles_p1x4(cycles / 4 - 1);
}
