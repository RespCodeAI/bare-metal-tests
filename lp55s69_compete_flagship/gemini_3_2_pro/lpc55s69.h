#ifndef LPC55S69_H
#define LPC55S69_H

#include <stdint.h>

/* Base Addresses */
#define SYSCON_BASE         0x50000000UL
#define IOCON_BASE          0x50002000UL
#define GPIO_BASE           0x4008C000UL

/* SYSCON Registers */
// AHB Clock Control 0 (Offset 0x200)
#define SYSCON_AHBCLKCTRL0  (*(volatile uint32_t *)(SYSCON_BASE + 0x200))

/* IOCON Registers */
// PIO1_4 is at offset 0x0A0
#define IOCON_PIO1_4        (*(volatile uint32_t *)(IOCON_BASE + 0x0A0))

/* GPIO Registers */
// GPIO Direction Port 1 (Offset 0x2000 + 4*1)
#define GPIO_DIR1           (*(volatile uint32_t *)(GPIO_BASE + 0x2004))

// GPIO Toggle Port 1 (Offset 0x2300 + 4*1)
#define GPIO_NOT1           (*(volatile uint32_t *)(GPIO_BASE + 0x2304))

#endif // LPC55S69_H
