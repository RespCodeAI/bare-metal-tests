#ifndef LPC55S69_H
#define LPC55S69_H

#include <stdint.h>

/* Core/system control blocks */
#define SCS_BASE            (0xE000E000UL)
#define SysTick_BASE        (SCS_BASE +  0x0010UL)

typedef struct {
    volatile uint32_t CTRL;   /* 0x00 */
    volatile uint32_t LOAD;   /* 0x04 */
    volatile uint32_t VAL;    /* 0x08 */
    volatile uint32_t CALIB;  /* 0x0C */
} SysTick_Type;

#define SysTick             ((SysTick_Type *)SysTick_BASE)

/* LPC55S69 memory-mapped peripheral base addresses */
#define SYSCON_BASE         (0x40000000UL)
#define IOCON_BASE          (0x40001000UL)
#define GPIO_BASE           (0x4008C000UL) /* GPIO base for LPC55S6x */

/* SYSCON register map (subset) */
typedef struct {
    volatile uint32_t SYSMEMREMAP;     /* 0x000 */
    volatile uint32_t PRESETCTRL0;     /* 0x004 */
    volatile uint32_t PRESETCTRL1;     /* 0x008 */
    volatile uint32_t PRESETCTRL2;     /* 0x00C */
    volatile uint32_t PRESETCTRL3;     /* 0x010 */
    volatile uint32_t PRESETCTRL4;     /* 0x014 */
    uint32_t RESERVED0[3];            /* 0x018..0x020 */
    volatile uint32_t AHBCLKCTRL0;     /* 0x024 */
    volatile uint32_t AHBCLKCTRL1;     /* 0x028 */
    volatile uint32_t AHBCLKCTRL2;     /* 0x02C */
    volatile uint32_t AHBCLKCTRL3;     /* 0x030 */
    volatile uint32_t AHBCLKCTRL4;     /* 0x034 */
    uint32_t RESERVED1[6];            /* 0x038..0x04C */
    volatile uint32_t MAINCLKSELA;     /* 0x050 */
    volatile uint32_t MAINCLKSELB;     /* 0x054 */
    volatile uint32_t MAINCLKSELC;     /* 0x058 */
    uint32_t RESERVED2[1];            /* 0x05C */
    volatile uint32_t AHBCLKDIV;       /* 0x060 */
    uint32_t RESERVED3[1];            /* 0x064 */
    volatile uint32_t SYSTICKCLKDIV;   /* 0x068 */
    uint32_t RESERVED4[1];            /* 0x06C */
    volatile uint32_t TRACECLKDIV;     /* 0x070 */
    uint32_t RESERVED5[3];            /* 0x074..0x07C */
    volatile uint32_t FROHFDIV;        /* 0x080 */
} SYSCON_Type;

#define SYSCON              ((SYSCON_Type *)SYSCON_BASE)

/* AHBCLKCTRL0 bits used (per LPC55S6x user manual): */
#define SYSCON_AHBCLKCTRL0_GPIO0_BIT   (13u)
#define SYSCON_AHBCLKCTRL0_IOCON_BIT   (18u)

/* IOCON pin control (LPC55S6x: one 32-bit register per pin) */
static inline volatile uint32_t *IOCON_PIO(uint32_t port, uint32_t pin)
{
    /* IOCON register spacing: each pin control register is 4 bytes.
       Layout: PIO0_0..PIO0_31, then PIO1_0.. etc.
       Address = IOCON_BASE + (port*32 + pin)*4
    */
    return (volatile uint32_t *)(IOCON_BASE + (((port * 32u) + pin) * 4u));
}

/* IOCON function/mode bits (simplified subset) */
#define IOCON_FUNC_MASK             (0x0Fu)
#define IOCON_FUNC_GPIO             (0x00u) /* FUNC=0 selects GPIO on most pins */

/* GPIO register map (LPC55S6x GPIO) */
typedef struct {
    volatile uint32_t B[4096];         /* Byte pin registers (0x0000) */
    volatile uint32_t W[4096];         /* Word pin registers (0x4000) */
    volatile uint32_t DIR[2];          /* 0x8000: DIR0, DIR1 */
    uint32_t RESERVED0[30];
    volatile uint32_t MASK[2];         /* 0x8080 */
    uint32_t RESERVED1[30];
    volatile uint32_t PIN[2];          /* 0x8100 */
    uint32_t RESERVED2[30];
    volatile uint32_t MPIN[2];         /* 0x8180 */
    uint32_t RESERVED3[30];
    volatile uint32_t SET[2];          /* 0x8200 */
    uint32_t RESERVED4[30];
    volatile uint32_t CLR[2];          /* 0x8280 */
    uint32_t RESERVED5[30];
    volatile uint32_t NOT[2];          /* 0x8300 */
} GPIO_Type;

#define GPIO               ((GPIO_Type *)GPIO_BASE)

/* Board LED: Red LED on P1_4, active-low */
#define LED_PORT           (1u)
#define LED_PIN            (4u)
#define LED_MASK           (1u << LED_PIN)

#endif /* LPC55S69_H */
