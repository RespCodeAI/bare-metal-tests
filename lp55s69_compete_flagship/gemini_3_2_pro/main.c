// TARGET: LPC55S69JBD100
#include <stdint.h>
#include "lpc55s69.h"

void delay(volatile uint32_t count) {
    while (count--) __asm__("nop");
}

int main(void) {
    /* 1. Enable Clocks */
    // Bit 13: IOCON clock enable
    // Bit 15: GPIO1 clock enable
    SYSCON_AHBCLKCTRL0 |= (1UL << 13) | (1UL << 15);

    /* 2. Configure Pin P1_4 */
    // IOCON offset 0x0A0 is PIO1_4
    // Bit 8 (DIGIMODE): 1 = Digital mode (required for GPIO)
    // Bits 0-3 (FUNC): 0 = GPIO function
    // Bits 4-5 (MODE): 0 = No pull-up/down
    IOCON_PIO1_4 = 0x100;

    /* 3. Set GPIO Direction */
    // Set P1_4 to Output (Bit 4 = 1)
    GPIO_DIR1 |= (1UL << 4);

    /* 4. Blink Loop */
    while (1) {
        // Write 1 to Bit 4 of NOT register to toggle the pin
        GPIO_NOT1 = (1UL << 4);
        delay(2000000);
    }
}
