#ifndef CONFIG_MK20DX128VLH5_H_
#define CONFIG_MK20DX128VLH5_H_

#include <units.h>

#define CONFIG_SYSCLOCK MEGA(50)

#define CONFIG_FLASH_FILL 0xFFFFFFFF
#define INCLUDE_VECTOR()  <config/k20-vector.def>

#define CONFIG_FLASH_OFFS 0
#define CONFIG_FLASH_SIZE  KIBI(128)

#define SRAM_U_BASE   0x20000000

#define CONFIG_RAM_SIZE   KIBI(16)
#define CONFIG_RAM_OFFS     (SRAM_U_BASE - CONFIG_RAM_SIZE / 2)

#endif
