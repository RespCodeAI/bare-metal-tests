#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;
extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* LPC55S69 specific interrupt handlers */
void WDT_BOD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void GINT0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void GINT1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PIN_INT0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PIN_INT1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PIN_INT2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PIN_INT3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UTICK0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void MRT0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CTIMER0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CTIMER1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SCT0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CTIMER2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM8_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LP_FLEXCOMM9_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PUF_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CASPER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void Reset_Handler(void) {
    /* Copy .data section from flash to RAM */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }
    
    /* Zero .bss section */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }
    
    /* Call main */
    main();
    
    /* Should never return */
    while (1);
}

void Default_Handler(void) {
    while (1);
}

__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) = {
    /* Cortex-M33 core interrupts */
    (void (*)(void))(&_estack),  /* Initial stack pointer */
    Reset_Handler,               /* Reset */
    NMI_Handler,                 /* NMI */
    HardFault_Handler,           /* Hard Fault */
    MemManage_Handler,           /* Memory Management Fault */
    BusFault_Handler,            /* Bus Fault */
    UsageFault_Handler,          /* Usage Fault */
    0,                           /* Reserved */
    0,                           /* Reserved */
    0,                           /* Reserved */
    0,                           /* Reserved */
    SVC_Handler,                 /* SVCall */
    DebugMon_Handler,            /* Debug Monitor */
    0,                           /* Reserved */
    PendSV_Handler,              /* PendSV */
    SysTick_Handler,             /* SysTick */
    
    /* LPC55S69 specific interrupts */
    WDT_BOD_IRQHandler,          /* 16: Watchdog Timer, Brown-Out Detect */
    DMA0_IRQHandler,             /* 17: DMA0 */
    GINT0_IRQHandler,            /* 18: GPIO Group0 */
    GINT1_IRQHandler,            /* 19: GPIO Group1 */
    PIN_INT0_IRQHandler,         /* 20: Pin Interrupt 0 */
    PIN_INT1_IRQHandler,         /* 21: Pin Interrupt 1 */
    PIN_INT2_IRQHandler,         /* 22: Pin Interrupt 2 */
    PIN_INT3_IRQHandler,         /* 23: Pin Interrupt 3 */
    UTICK0_IRQHandler,           /* 24: Micro-Tick Timer */
    MRT0_IRQHandler,             /* 25: Multi-Rate Timer */
    CTIMER0_IRQHandler,          /* 26: Standard Counter/Timer 0 */
    CTIMER1_IRQHandler,          /* 27: Standard Counter/Timer 1 */
    SCT0_IRQHandler,             /* 28: State Configurable Timer */
    CTIMER2_IRQHandler,          /* 29: Standard Counter/Timer 2 */
    LP_FLEXCOMM0_IRQHandler,     /* 30: LP_FLEXCOMM0 */
    LP_FLEXCOMM1_IRQHandler,     /* 31: LP_FLEXCOMM1 */
    LP_FLEXCOMM2_IRQHandler,     /* 32: LP_FLEXCOMM2 */
    LP_FLEXCOMM3_IRQHandler,     /* 33: LP_FLEXCOMM3 */
    LP_FLEXCOMM4_IRQHandler,     /* 34: LP_FLEXCOMM4 */
    LP_FLEXCOMM5_IRQHandler,     /* 35: LP_FLEXCOMM5 */
    LP_FLEXCOMM6_IRQHandler,     /* 36: LP_FLEXCOMM6 */
    LP_FLEXCOMM7_IRQHandler,     /* 37: LP_FLEXCOMM7 */
    LP_FLEXCOMM8_IRQHandler,     /* 38: LP_FLEXCOMM8 */
    LP_FLEXCOMM9_IRQHandler,     /* 39: LP_FLEXCOMM9 */
    ADC0_IRQHandler,             /* 40: ADC0 */
    ADC1_IRQHandler,             /* 41: ADC1 */
    PUF_IRQHandler,              /* 42: PUF */
    CASPER_IRQHandler,           /* 43: CASPER */
    DMA1_IRQHandler              /* 44: DMA1 */
};
