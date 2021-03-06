#pragma once

#define IF_INC() "pmc.def"
#define IF_NAME pmc
#define IF_PREFIX sam3
#include "gen-if.h"

#define SAM3_PMC_BASE 0x400E0400
#define SAM3_PMC (*(volatile struct sam3_pmc *)(SAM3_PMC_BASE))

#define SAM3_PMC_CKGR_MOR_KEY (0x37 << 16)
#define SAM3_PMC_CKGR_MOR_MOSCXTEN (1 << 0)
#define SAM3_PMC_CKGR_MOR_MOSCRCEN (1 << 3)
#define SAM3_PMC_CKGR_MOR_MOSCSEL  (1 << 24)
#define SAM3_PMC_CKGR_MOR_MOSCXTST(x) (((x) & 0xff) << 8)
#define SAM3_PMC_CKGR_MOR_CFDEN	   (1 << 25)

#define SAM3_PMC_SR_MOSCXTS  (1 << 0)
#define SAM3_PMC_SR_LOCKA    (1 << 1)
#define SAM3_PMC_SR_LOCKB    (1 << 2)
#define SAM3_PMC_SR_MCKRDY   (1 << 3)
#define SAM3_PMC_SR_MOSCSELS (1 << 16)

#define SAM3_PMC_CKGR_PLLAR_ONE (1 << 29)
#define SAM3_PMC_CKGR_PLLAR_MUL(x) (((x) & 0x7ff) << 16)
#define SAM3_PMC_CKGR_PLLAR_COUNT(x) (((x) & 0x3f) << 8)
#define SAM3_PMC_CKGR_PLLAR_DIV(x) ((x) & 0xff)

#define SAM3_PMC_MCKR_CSS_SLOW 0
#define SAM3_PMC_MCKR_CSS_MAIN 1
#define SAM3_PMC_MCKR_CSS_PLLA 2
#define SAM3_PMC_MCKR_CSS_PLLB 3
#define SAM3_PMC_MCKR_CSS_MASK 3

#define SAM3_PMC_MCKR_PRES(x) (((x) & 0x7) << 4)
#define SAM3_PMC_MCKR_PRES_MASK SAM3_PMC_MCKR_PRES(0x7)

#define SAM3_PMC_WPMR_KEY    (0x504D43 << 8)
#define SAM3_PMC_WPMR_ENABLE (1 << 0)
