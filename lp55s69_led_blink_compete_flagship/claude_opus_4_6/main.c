// TARGET: LPC55S69JBD100
//
// Bare-metal LED blink for NXP LPC55S69-EVK
// Red LED on PORT1 PIN4 (active low)
// Clock source: 12 MHz internal FRO (default after reset)
//

#include <stdint.h>
#include "lpc55s69.h"

/* Simple delay loop. At 12 MHz FRO, ~3 cycles per iteration.
 * delay(1000000) ~ 250ms roughly */
static void delay(volatile uint32_t count)
{
    while (count--) {
        __asm volatile ("nop");
    }
}

static void clock_init(void)
{
    /* Enable clocks for IOCON, GPIO0, GPIO1, and SRAM1-3 via SET register.
     * SRAM0 clock is always enabled after reset.
     * Writing to the SET register only sets the specified bits
     * without disturbing other clock enables. */
    SYSCON_AHBCLKCTRLSET0 = SYSCON_AHBCLKCTRL0_IOCON
                          | SYSCON_AHBCLKCTRL0_GPIO0
                          | SYSCON_AHBCLKCTRL0_GPIO1
                          | SYSCON_AHBCLKCTRL0_SRAM1
                          | SYSCON_AHBCLKCTRL0_SRAM2
                          | SYSCON_AHBCLKCTRL0_SRAM3;

    /* De-assert peripheral resets for GPIO0, GPIO1, IOCON.
     * In the PRESETCTRL register, 0 = reset asserted, 1 = released.
     * The CLR register writes 1 to clear the reset (i.e., release from reset).
     * Wait -- actually, the PRESETCTRL SET register sets bits to 1 which
     * means "not in reset". Let's release reset properly:
     * Writing 1 to PRESETCTRLCLR asserts reset (sets bit to 0).
     * Writing 1 to PRESETCTRLSET releases reset (sets bit to 1).
     * We want to release from reset, so write to SET register. */
    SYSCON_PRESETCTRLSET0 = SYSCON_PRESETCTRL0_IOCON
                          | SYSCON_PRESETCTRL0_GPIO0
                          | SYSCON_PRESETCTRL0_GPIO1;
}

static void led_init(void)
{
    /* Configure PIO1_4 via IOCON:
     * - FUNC = 0 (GPIO)
     * - MODE = 0 (no pull-up/pull-down - board has external pull)
     * - DIGIMODE = 1 (digital mode, required for GPIO)
     * - SLEW = 0 (standard)
     * - OD = 0 (normal push-pull) */
    IOCON_PIO1_4 = IOCON_FUNC_GPIO
                 | IOCON_MODE_INACTIVE
                 | IOCON_DIGIMODE
                 | IOCON_SLEW_STANDARD
                 | IOCON_OD_DISABLE;

    /* Set PORT1 PIN4 as output */
    GPIO_DIR1 |= LED_RED_MASK;

    /* Start with LED off (active low, so set pin HIGH to turn off) */
    GPIO_SET1 = LED_RED_MASK;
}

int main(void)
{
    clock_init();
    led_init();

    while (1) {
        /* Toggle PORT1 PIN4 using the NOT (toggle) register */
        GPIO_NOT1 = LED_RED_MASK;

        /* Delay ~500ms at 12 MHz FRO */
        delay(2000000);
    }

    /* Never reached */
    return 0;
}
