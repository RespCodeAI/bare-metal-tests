// LPC55S69JBD100 Register Definitions
#ifndef LPC55S69_H
#define LPC55S69_H

#include <stdint.h>

/* ==========================================================================
 * SYSCON - System Configuration
 * Base: 0x40000000
 * ========================================================================== */
#define SYSCON_BASE             (0x40000000UL)

/* AHB Clock Control 0 - enables clocks for AHB peripherals */
#define SYSCON_AHBCLKCTRL0     (*(volatile uint32_t *)(SYSCON_BASE + 0x200))
/* AHB Clock Control Set 0 - write 1 to set bits */
#define SYSCON_AHBCLKCTRLSET0  (*(volatile uint32_t *)(SYSCON_BASE + 0x220))
/* AHB Clock Control Clear 0 - write 1 to clear bits */
#define SYSCON_AHBCLKCTRLCLR0  (*(volatile uint32_t *)(SYSCON_BASE + 0x240))

/* AHB Clock Control 1 */
#define SYSCON_AHBCLKCTRL1     (*(volatile uint32_t *)(SYSCON_BASE + 0x204))
#define SYSCON_AHBCLKCTRLSET1  (*(volatile uint32_t *)(SYSCON_BASE + 0x224))

/* AHBCLKCTRL0 bit positions */
#define SYSCON_AHBCLKCTRL0_ROM_POS      (1U)
#define SYSCON_AHBCLKCTRL0_SRAM1_POS    (3U)
#define SYSCON_AHBCLKCTRL0_SRAM2_POS    (4U)
#define SYSCON_AHBCLKCTRL0_SRAM3_POS    (5U)
#define SYSCON_AHBCLKCTRL0_FLASH_POS    (7U)
#define SYSCON_AHBCLKCTRL0_FMC_POS      (8U)
#define SYSCON_AHBCLKCTRL0_MUX_POS      (11U)
#define SYSCON_AHBCLKCTRL0_IOCON_POS    (13U)
#define SYSCON_AHBCLKCTRL0_GPIO0_POS    (14U)
#define SYSCON_AHBCLKCTRL0_GPIO1_POS    (15U)

/* AHBCLKCTRL0 bit masks */
#define SYSCON_AHBCLKCTRL0_IOCON        (1UL << SYSCON_AHBCLKCTRL0_IOCON_POS)
#define SYSCON_AHBCLKCTRL0_GPIO0        (1UL << SYSCON_AHBCLKCTRL0_GPIO0_POS)
#define SYSCON_AHBCLKCTRL0_GPIO1        (1UL << SYSCON_AHBCLKCTRL0_GPIO1_POS)
#define SYSCON_AHBCLKCTRL0_SRAM1        (1UL << SYSCON_AHBCLKCTRL0_SRAM1_POS)
#define SYSCON_AHBCLKCTRL0_SRAM2        (1UL << SYSCON_AHBCLKCTRL0_SRAM2_POS)
#define SYSCON_AHBCLKCTRL0_SRAM3        (1UL << SYSCON_AHBCLKCTRL0_SRAM3_POS)

/* Peripheral Reset Control 0 */
#define SYSCON_PRESETCTRL0     (*(volatile uint32_t *)(SYSCON_BASE + 0x100))
#define SYSCON_PRESETCTRLSET0  (*(volatile uint32_t *)(SYSCON_BASE + 0x120))
#define SYSCON_PRESETCTRLCLR0  (*(volatile uint32_t *)(SYSCON_BASE + 0x140))

/* PRESETCTRL0 bit positions (same bit positions as AHBCLKCTRL0 for GPIO/IOCON) */
#define SYSCON_PRESETCTRL0_GPIO0        (1UL << 14)
#define SYSCON_PRESETCTRL0_GPIO1        (1UL << 15)
#define SYSCON_PRESETCTRL0_IOCON        (1UL << 13)

/* ==========================================================================
 * IOCON - I/O Configuration
 * Base: 0x40001000
 * Each pin has a 32-bit register.
 * PORT1 PIN4 = PIO1_4
 * IOCON index for PIO1_4: offset depends on pin mapping.
 * LPC55S69 IOCON register offset = 4 * pin_index
 * Pin indices are laid out as: PIO0_0..PIO0_31, PIO1_0..PIO1_31
 * PIO1_4 index = 32 + 4 = 36, offset = 36 * 4 = 0x90
 * ========================================================================== */
#define IOCON_BASE              (0x40001000UL)
#define IOCON_PIO1_4           (*(volatile uint32_t *)(IOCON_BASE + 0x090))

/* IOCON register bit fields */
#define IOCON_FUNC_POS          (0U)
#define IOCON_FUNC_MASK         (0xFUL << IOCON_FUNC_POS)
#define IOCON_FUNC_GPIO         (0x0UL << IOCON_FUNC_POS)  /* Function 0 = GPIO */
#define IOCON_MODE_POS          (4U)
#define IOCON_MODE_MASK         (0x3UL << IOCON_MODE_POS)
#define IOCON_MODE_INACTIVE     (0x0UL << IOCON_MODE_POS)  /* No pull-up/down */
#define IOCON_MODE_PULLDOWN     (0x1UL << IOCON_MODE_POS)
#define IOCON_MODE_PULLUP       (0x2UL << IOCON_MODE_POS)
#define IOCON_MODE_REPEATER     (0x3UL << IOCON_MODE_POS)
#define IOCON_SLEW_POS          (6U)
#define IOCON_SLEW_STANDARD     (0x0UL << IOCON_SLEW_POS)
#define IOCON_INVERT_POS        (7U)
#define IOCON_DIGIMODE_POS      (8U)
#define IOCON_DIGIMODE          (1UL << IOCON_DIGIMODE_POS)  /* Digital mode enable */
#define IOCON_OD_POS            (9U)
#define IOCON_OD_DISABLE        (0x0UL << IOCON_OD_POS)

/* ==========================================================================
 * GPIO - General Purpose I/O
 * Base: 0x4008C000
 * GPIO has byte, word, direction, set, clear, toggle registers
 * ========================================================================== */
#define GPIO_BASE               (0x4008C000UL)

/* GPIO byte pin registers (1 byte per pin) */
/* B[port][pin] at offset 0x0000 + port*32 + pin */
#define GPIO_B_BASE             (GPIO_BASE + 0x0000)

/* GPIO word pin registers (4 bytes per pin) */
/* W[port][pin] at offset 0x1000 + (port*32 + pin)*4 */
#define GPIO_W_BASE             (GPIO_BASE + 0x1000)

/* GPIO Direction registers */
/* DIR[port] at offset 0x2000 + port*4 */
#define GPIO_DIR0              (*(volatile uint32_t *)(GPIO_BASE + 0x2000))
#define GPIO_DIR1              (*(volatile uint32_t *)(GPIO_BASE + 0x2004))

/* GPIO Set registers - write 1 to set output high */
#define GPIO_SET0              (*(volatile uint32_t *)(GPIO_BASE + 0x2200))
#define GPIO_SET1              (*(volatile uint32_t *)(GPIO_BASE + 0x2204))

/* GPIO Clear registers - write 1 to set output low */
#define GPIO_CLR0              (*(volatile uint32_t *)(GPIO_BASE + 0x2280))
#define GPIO_CLR1              (*(volatile uint32_t *)(GPIO_BASE + 0x2284))

/* GPIO Toggle registers - write 1 to toggle */
#define GPIO_NOT0              (*(volatile uint32_t *)(GPIO_BASE + 0x2300))
#define GPIO_NOT1              (*(volatile uint32_t *)(GPIO_BASE + 0x2304))

/* GPIO Pin registers (read pin state) */
#define GPIO_PIN0              (*(volatile uint32_t *)(GPIO_BASE + 0x2100))
#define GPIO_PIN1              (*(volatile uint32_t *)(GPIO_BASE + 0x2104))

/* ==========================================================================
 * Cortex-M33 System Registers
 * ========================================================================== */
#define SYST_CSR               (*(volatile uint32_t *)0xE000E010)
#define SYST_RVR               (*(volatile uint32_t *)0xE000E014)
#define SYST_CVR               (*(volatile uint32_t *)0xE000E018)

/* PORT1 PIN4 bit mask */
#define LED_RED_PORT            1
#define LED_RED_PIN             4
#define LED_RED_MASK            (1UL << LED_RED_PIN)

#endif /* LPC55S69_H */
