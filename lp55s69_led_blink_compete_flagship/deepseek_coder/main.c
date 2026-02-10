// TARGET: LPC55S69JBD100
#include "lpc55s69.h"

static void delay_ms(uint32_t ms) {
    /* Simple delay using 12MHz clock */
    /* Approximately 12,000 cycles per ms */
    volatile uint32_t i;
    for (; ms > 0; ms--) {
        for (i = 0; i < 12000; i++) {
            __asm__("nop");
        }
    }
}

static void system_clock_init(void) {
    /* Enable FRO 12MHz oscillator */
    FROOSCCTRL = FROOSCCTRL_SEL_12MHZ | FROOSCCTRL_ENABLE;
    
    /* Enable FRO direct clock */
    FRODIRECTCLKUEN = FRODIRECTCLKUEN_ENABLE;
    
    /* Select FRO 12MHz as main clock source A */
    MAINCLKSELA = MAINCLKSELA_FRO_12MHZ;
    
    /* Select MAINCLKSELA as main clock */
    MAINCLKSELB = MAINCLKSELB_MAINCLKSELA;
    
    /* Set AHB clock divider to 1 (12MHz) */
    AHBCLKDIV = 1U;
}

static void gpio_init(void) {
    /* Enable clocks for GPIO1 and IOCON */
    AHBCLKCTRL0 |= AHBCLKCTRL0_GPIO1 | AHBCLKCTRL0_IOCON;
    
    /* Configure PORT1_PIN4 as GPIO with digital mode */
    IOCON_PIO1_4 = IOCON_FUNC0 | IOCON_MODE_INACTIVE |
                   IOCON_SLEW_STANDARD | IOCON_INVERT_DISABLE |
                   IOCON_DIGITAL_ENABLE | IOCON_FILTER_DISABLE;
    
    /* Set PORT1_PIN4 as output */
    GPIO_DIR0 |= LED_MASK;
    
    /* Initially turn LED off (active low, so set = off) */
    GPIO_SET0 = LED_MASK;
}

int main(void) {
    /* Initialize system clock to 12MHz */
    system_clock_init();
    
    /* Initialize GPIO for LED */
    gpio_init();
    
    /* Main loop */
    while (1) {
        /* Toggle LED */
        GPIO_NOT0 = LED_MASK;
        
        /* Delay 500ms */
        delay_ms(500);
    }
}
