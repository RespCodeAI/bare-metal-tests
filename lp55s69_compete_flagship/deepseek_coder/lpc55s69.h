#ifndef LPC55S69_H
#define LPC55S69_H

#include <stdint.h>

/* System Control Registers */
#define SYSCON_BASE 0x40000000U
#define AHBCLKCTRL0 (*(volatile uint32_t *)(SYSCON_BASE + 0x100U))
#define AHBCLKCTRL1 (*(volatile uint32_t *)(SYSCON_BASE + 0x104U))
#define FROOSCCTRL  (*(volatile uint32_t *)(SYSCON_BASE + 0x300U))
#define FRODIRECTCLKUEN (*(volatile uint32_t *)(SYSCON_BASE + 0x304U))
#define MAINCLKSELA (*(volatile uint32_t *)(SYSCON_BASE + 0x320U))
#define MAINCLKSELB (*(volatile uint32_t *)(SYSCON_BASE + 0x324U))
#define AHBCLKDIV   (*(volatile uint32_t *)(SYSCON_BASE + 0x328U))

/* GPIO Registers */
#define GPIO_BASE   0xA0000000U
#define GPIO_DIR0   (*(volatile uint32_t *)(GPIO_BASE + 0x00U))
#define GPIO_SET0   (*(volatile uint32_t *)(GPIO_BASE + 0x08U))
#define GPIO_CLR0   (*(volatile uint32_t *)(GPIO_BASE + 0x0CU))
#define GPIO_NOT0   (*(volatile uint32_t *)(GPIO_BASE + 0x10U))
#define GPIO_B0     (*(volatile uint32_t *)(GPIO_BASE + 0x20U))
#define GPIO_B1     (*(volatile uint32_t *)(GPIO_BASE + 0x24U))

/* IOCON Registers */
#define IOCON_BASE  0x40001000U
#define IOCON_PIO1_4 (*(volatile uint32_t *)(IOCON_BASE + 0x104U))

/* Clock Enable Bits */
#define AHBCLKCTRL0_GPIO0 (1U << 13)
#define AHBCLKCTRL0_GPIO1 (1U << 14)
#define AHBCLKCTRL0_IOCON (1U << 18)

/* FRO Configuration */
#define FROOSCCTRL_SEL_12MHZ (0U << 0)
#define FROOSCCTRL_ENABLE    (1U << 0)
#define FRODIRECTCLKUEN_ENABLE (1U << 0)

/* Clock Selection */
#define MAINCLKSELA_FRO_12MHZ (0U << 0)
#define MAINCLKSELB_MAINCLKSELA (0U << 0)

/* IOCON Configuration */
#define IOCON_FUNC0 (0U << 0)          /* GPIO function */
#define IOCON_MODE_INACTIVE (0U << 3)  /* No pull-up/pull-down */
#define IOCON_SLEW_STANDARD (0U << 6)  /* Standard slew rate */
#define IOCON_INVERT_DISABLE (0U << 7) /* No input inversion */
#define IOCON_DIGITAL_ENABLE (1U << 8) /* Digital mode */
#define IOCON_FILTER_DISABLE (0U << 9) /* Input filter disabled */

/* LED Pin */
#define LED_PORT 1
#define LED_PIN  4
#define LED_MASK (1U << LED_PIN)

#endif /* LPC55S69_H */
