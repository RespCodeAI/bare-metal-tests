// TARGET: LPC55S69JBD100
#include <stdint.h>
#include "lpc55s69.h"

static void delay_cycles(volatile uint32_t cycles)
{
    while (cycles--) {
        __asm volatile ("nop");
    }
}

static void clocks_init_minimal(void)
{
    /* Requirement: use 12MHz internal FRO, no PLL.
       On LPC55S6x the boot ROM typically leaves a usable clock running.
       We only ensure AHB clock divider is 1 for predictable delays. */
    SYSCON->AHBCLKDIV = 1u;
}

static void gpio_init_led(void)
{
    /* Enable clocks: GPIO and IOCON via SYSCON AHBCLKCTRL0 */
    SYSCON->AHBCLKCTRL0 |= (1u << SYSCON_AHBCLKCTRL0_GPIO0_BIT);
    SYSCON->AHBCLKCTRL0 |= (1u << SYSCON_AHBCLKCTRL0_IOCON_BIT);

    /* Configure P1_4 IOCON mux as GPIO (FUNC=0). */
    volatile uint32_t *iocon = IOCON_PIO(LED_PORT, LED_PIN);
    uint32_t v = *iocon;
    v &= ~IOCON_FUNC_MASK;
    v |= IOCON_FUNC_GPIO;
    *iocon = v;

    /* Set direction output */
    GPIO->DIR[LED_PORT] |= LED_MASK;

    /* Turn LED off initially (active-low => drive high = off) */
    GPIO->SET[LED_PORT] = LED_MASK;
}

int main(void)
{
    clocks_init_minimal();
    gpio_init_led();

    for (;;) {
        /* Toggle output */
        GPIO->NOT[LED_PORT] = LED_MASK;

        /* Crude delay; with ~12MHz AHB clock this is a visible blink. */
        delay_cycles(1200000u);
    }
}
