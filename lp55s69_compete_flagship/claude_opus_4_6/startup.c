// Startup code for LPC55S69JBD100 (Cortex-M33)
// Provides vector table, Reset_Handler with .data/.bss initialization

#include <stdint.h>

/* Linker-provided symbols */
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/* main() prototype */
extern int main(void);

/* Forward declarations */
void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SecureFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)      __attribute__((weak, alias("Default_Handler")));

/* LPC55S69 Peripheral IRQ Handlers (60 interrupts) */
void WDT_BOD_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void DMA0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void GINT0_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void GINT1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void PIN_INT0_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PIN_INT1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PIN_INT2_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PIN_INT3_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void UTICK0_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void MRT0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void CTIMER0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void CTIMER1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void SCT0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void CTIMER3_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM0_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM1_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM2_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM3_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM4_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM5_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM6_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM7_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void ADC0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void Reserved39_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void ACMP_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void Reserved41_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void Reserved42_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void USB0_NEEDCLK_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void USB0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void Reserved46_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void MAILBOX_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void PIN_INT4_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PIN_INT5_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PIN_INT6_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void PIN_INT7_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void CTIMER2_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void CTIMER4_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void OS_EVENT_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void Reserved55_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void Reserved56_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void Reserved57_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void Reserved59_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void Reserved60_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void Reserved61_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void USB1_PHY_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void USB1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void USB1_NEEDCLK_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void SEC_HYPERVISOR_CALL_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void SEC_GPIO_INT0_IRQ0_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void SEC_GPIO_INT0_IRQ1_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void PLU_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void SEC_VIO_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void HASHCRYPT_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void CASER_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void PUF_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void PQ_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void DMA1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void FLEXCOMM8_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));

/* ==========================================================================
 * Vector Table
 * Placed at the start of flash in .isr_vector section
 * Cortex-M33 core vectors + LPC55S69 peripheral interrupt vectors
 * ========================================================================== */
__attribute__((section(".isr_vector"), used))
void (* const g_pfnVectors[])(void) = {
    /* Cortex-M33 Core Exceptions */
    (void (*)(void))(&_estack),       /*  0: Initial Stack Pointer */
    Reset_Handler,                     /*  1: Reset Handler */
    NMI_Handler,                       /*  2: NMI Handler */
    HardFault_Handler,                 /*  3: Hard Fault Handler */
    MemManage_Handler,                 /*  4: MPU Fault Handler */
    BusFault_Handler,                  /*  5: Bus Fault Handler */
    UsageFault_Handler,                /*  6: Usage Fault Handler */
    SecureFault_Handler,               /*  7: Secure Fault Handler (M33) */
    0,                                 /*  8: Reserved */
    0,                                 /*  9: Reserved */
    0,                                 /* 10: Reserved */
    SVC_Handler,                       /* 11: SVCall Handler */
    DebugMon_Handler,                  /* 12: Debug Monitor Handler */
    0,                                 /* 13: Reserved */
    PendSV_Handler,                    /* 14: PendSV Handler */
    SysTick_Handler,                   /* 15: SysTick Handler */

    /* LPC55S69 Peripheral Interrupts (IRQ 0..74) */
    WDT_BOD_IRQHandler,                /* IRQ  0: Watchdog / BOD */
    DMA0_IRQHandler,                   /* IRQ  1: DMA0 */
    GINT0_IRQHandler,                  /* IRQ  2: GPIO Group Int 0 */
    GINT1_IRQHandler,                  /* IRQ  3: GPIO Group Int 1 */
    PIN_INT0_IRQHandler,               /* IRQ  4: Pin Interrupt 0 */
    PIN_INT1_IRQHandler,               /* IRQ  5: Pin Interrupt 1 */
    PIN_INT2_IRQHandler,               /* IRQ  6: Pin Interrupt 2 */
    PIN_INT3_IRQHandler,               /* IRQ  7: Pin Interrupt 3 */
    UTICK0_IRQHandler,                 /* IRQ  8: Micro-tick Timer */
    MRT0_IRQHandler,                   /* IRQ  9: Multi-Rate Timer */
    CTIMER0_IRQHandler,                /* IRQ 10: CTimer 0 */
    CTIMER1_IRQHandler,                /* IRQ 11: CTimer 1 */
    SCT0_IRQHandler,                   /* IRQ 12: SCTimer/PWM */
    CTIMER3_IRQHandler,                /* IRQ 13: CTimer 3 */
    FLEXCOMM0_IRQHandler,              /* IRQ 14: Flexcomm 0 */
    FLEXCOMM1_IRQHandler,              /* IRQ 15: Flexcomm 1 */
    FLEXCOMM2_IRQHandler,              /* IRQ 16: Flexcomm 2 */
    FLEXCOMM3_IRQHandler,              /* IRQ 17: Flexcomm 3 */
    FLEXCOMM4_IRQHandler,              /* IRQ 18: Flexcomm 4 */
    FLEXCOMM5_IRQHandler,              /* IRQ 19: Flexcomm 5 */
    FLEXCOMM6_IRQHandler,              /* IRQ 20: Flexcomm 6 */
    FLEXCOMM7_IRQHandler,              /* IRQ 21: Flexcomm 7 */
    ADC0_IRQHandler,                   /* IRQ 22: ADC0 */
    Reserved39_IRQHandler,             /* IRQ 23: Reserved */
    ACMP_IRQHandler,                   /* IRQ 24: Analog Comparator */
    Reserved41_IRQHandler,             /* IRQ 25: Reserved */
    Reserved42_IRQHandler,             /* IRQ 26: Reserved */
    USB0_NEEDCLK_IRQHandler,           /* IRQ 27: USB0 Activity */
    USB0_IRQHandler,                   /* IRQ 28: USB0 */
    RTC_IRQHandler,                    /* IRQ 29: RTC */
    Reserved46_IRQHandler,             /* IRQ 30: Reserved */
    MAILBOX_IRQHandler,                /* IRQ 31: Mailbox */
    PIN_INT4_IRQHandler,               /* IRQ 32: Pin Interrupt 4 */
    PIN_INT5_IRQHandler,               /* IRQ 33: Pin Interrupt 5 */
    PIN_INT6_IRQHandler,               /* IRQ 34: Pin Interrupt 6 */
    PIN_INT7_IRQHandler,               /* IRQ 35: Pin Interrupt 7 */
    CTIMER2_IRQHandler,                /* IRQ 36: CTimer 2 */
    CTIMER4_IRQHandler,                /* IRQ 37: CTimer 4 */
    OS_EVENT_IRQHandler,               /* IRQ 38: OS Event Timer */
    Reserved55_IRQHandler,             /* IRQ 39: Reserved */
    Reserved56_IRQHandler,             /* IRQ 40: Reserved */
    Reserved57_IRQHandler,             /* IRQ 41: Reserved */
    SDIO_IRQHandler,                   /* IRQ 42: SDIO */
    Reserved59_IRQHandler,             /* IRQ 43: Reserved */
    Reserved60_IRQHandler,             /* IRQ 44: Reserved */
    Reserved61_IRQHandler,             /* IRQ 45: Reserved */
    USB1_PHY_IRQHandler,               /* IRQ 46: USB1 PHY */
    USB1_IRQHandler,                   /* IRQ 47: USB1 */
    USB1_NEEDCLK_IRQHandler,           /* IRQ 48: USB1 Activity */
    SEC_HYPERVISOR_CALL_IRQHandler,    /* IRQ 49: Secure HV Call */
    SEC_GPIO_INT0_IRQ0_IRQHandler,     /* IRQ 50: Secure GPIO Int 0 */
    SEC_GPIO_INT0_IRQ1_IRQHandler,     /* IRQ 51: Secure GPIO Int 1 */
    PLU_IRQHandler,                    /* IRQ 52: PLU */
    SEC_VIO_IRQHandler,                /* IRQ 53: Security Violation */
    HASHCRYPT_IRQHandler,              /* IRQ 54: Hash/AES */
    CASER_IRQHandler,                  /* IRQ 55: CASPER */
    PUF_IRQHandler,                    /* IRQ 56: PUF */
    PQ_IRQHandler,                     /* IRQ 57: Power Quad */
    DMA1_IRQHandler,                   /* IRQ 58: DMA1 */
    FLEXCOMM8_IRQHandler,              /* IRQ 59: Flexcomm 8 (HS SPI) */
};

/* ==========================================================================
 * Reset_Handler
 * - Copies .data from flash to RAM
 * - Zeros .bss
 * - Calls main()
 * ========================================================================== */
void Reset_Handler(void)
{
    uint32_t *src, *dst;

    /* Copy .data section from flash to RAM */
    src = &_sidata;
    dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero-fill .bss section */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    /* Call application main */
    main();

    /* Hang if main returns */
    while (1) {
        __asm volatile ("nop");
    }
}

/* ==========================================================================
 * Default_Handler - infinite loop for unhandled interrupts
 * ========================================================================== */
void Default_Handler(void)
{
    while (1) {
        __asm volatile ("nop");
    }
}
