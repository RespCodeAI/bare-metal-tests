#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
void Default_Handler(void);

/* Cortex-M33 core handlers */
void NMI_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void SecureFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)            __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)        __attribute__((weak, alias("Default_Handler")));

/* LPC55S69 peripheral interrupts (weak to Default_Handler).
   Provide a complete table shape (0..63 IRQs). */
void IRQ0_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ1_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ2_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ3_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ4_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ5_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ6_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ7_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ8_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ9_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void IRQ10_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ11_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ12_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ13_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ14_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ15_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ16_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ17_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ18_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ19_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ20_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ21_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ22_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ23_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ24_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ25_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ26_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ27_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ28_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ29_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ30_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ31_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ32_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ33_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ34_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ35_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ36_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ37_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ38_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ39_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ40_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ41_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ42_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ43_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ44_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ45_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ46_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ47_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ48_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ49_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ50_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ51_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ52_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ53_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ54_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ55_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ56_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ57_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ58_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ59_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ60_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ61_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ62_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ63_Handler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) = {
    (void (*)(void))(&_estack),
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    SecureFault_Handler,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    /* External interrupts 0..63 */
    IRQ0_Handler,  IRQ1_Handler,  IRQ2_Handler,  IRQ3_Handler,
    IRQ4_Handler,  IRQ5_Handler,  IRQ6_Handler,  IRQ7_Handler,
    IRQ8_Handler,  IRQ9_Handler,  IRQ10_Handler, IRQ11_Handler,
    IRQ12_Handler, IRQ13_Handler, IRQ14_Handler, IRQ15_Handler,
    IRQ16_Handler, IRQ17_Handler, IRQ18_Handler, IRQ19_Handler,
    IRQ20_Handler, IRQ21_Handler, IRQ22_Handler, IRQ23_Handler,
    IRQ24_Handler, IRQ25_Handler, IRQ26_Handler, IRQ27_Handler,
    IRQ28_Handler, IRQ29_Handler, IRQ30_Handler, IRQ31_Handler,
    IRQ32_Handler, IRQ33_Handler, IRQ34_Handler, IRQ35_Handler,
    IRQ36_Handler, IRQ37_Handler, IRQ38_Handler, IRQ39_Handler,
    IRQ40_Handler, IRQ41_Handler, IRQ42_Handler, IRQ43_Handler,
    IRQ44_Handler, IRQ45_Handler, IRQ46_Handler, IRQ47_Handler,
    IRQ48_Handler, IRQ49_Handler, IRQ50_Handler, IRQ51_Handler,
    IRQ52_Handler, IRQ53_Handler, IRQ54_Handler, IRQ55_Handler,
    IRQ56_Handler, IRQ57_Handler, IRQ58_Handler, IRQ59_Handler,
    IRQ60_Handler, IRQ61_Handler, IRQ62_Handler, IRQ63_Handler
};

void Reset_Handler(void)
{
    /* Copy .data from flash to RAM */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero .bss */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0u;
    }

    (void)main();
    while (1) {
        /* If main returns, trap */
    }
}

void Default_Handler(void)
{
    while (1) {
        /* Trap */
    }
}
