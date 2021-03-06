
#include <stdint.h>
__attribute__((noreturn))
extern void main (void);
//extern void __libc_init_array(void) __attribute__((weak));
extern void arch_init_early(void) __attribute__((weak));
extern void board_init_early(void) __attribute__((weak));
extern void init_early(void) __attribute__((weak));
extern void arch_init(void) __attribute__((weak));
extern void board_init(void) __attribute__((weak));
extern void isr_reset(void);

/*
 * libc _sometimes_ supplies this, but doesn't if lto is enabled.  We can't
 * provide a dummy weak impl because our weak impl overrides the libc's weak
 * impl Also dropping this here means that our lto settings allow this to be
 * optimized out even if the libc wasn't built with lto
 */
extern void _init(void) __attribute__((weak));
static void __libc_init_array(void)
{
	typedef void (*init_fn)(void);
	extern init_fn __preinit_array_start[], __preinit_array_end[],
	       __init_array_start[], __init_array_end[];

	init_fn *f;
	f = __preinit_array_start;
	while (f < __preinit_array_end) {
		(*f)();
		f++;
	}

	_init();

	f = __init_array_start;
	while (f < __init_array_end) {
		(*f)();
		f++;
	}
}

__attribute__((noreturn,interrupt,naked))
void isr_reset(void)
{
	extern uint32_t __bss_start[], __bss_end[], __data_start[],
	       __data_end[], __data_load_start[];
	uint32_t *s, *d;

	arch_init_early();
	board_init_early();
	init_early();

	s = __data_load_start;
	d = __data_start;
	while (d < __data_end)
		*d++ = *s++;

	d = __bss_start;
	while (d < __bss_end)
		*d++ = 0;

	__libc_init_array();
	arch_init();
	board_init();
	main();
}
