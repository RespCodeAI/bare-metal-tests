#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;
extern int main(void);

void Reset_Handler(void) {
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    /* Copy data segment from Flash to RAM */
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero out the BSS segment */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    /* Jump to main */
    main();

    /* Should never reach here */
    while(1);
}

void Default_Handler(void) {
    while (1);
}

/* Minimal Vector Table for Cortex-M33 */
__attribute__((section(".isr_vector")))
void (* const vector_table[])(void) = {
    (void (*)(void))(&_estack), // Initial Stack Pointer
    Reset_Handler,              // Reset Handler
    Default_Handler,            // NMI
    Default_Handler,            // HardFault
    Default_Handler,            // MemManage
    Default_Handler,            // BusFault
    Default_Handler,            // UsageFault
    0, 0, 0, 0,                 // Reserved
    Default_Handler,            // SVCall
    Default_Handler,            // Debug Monitor
    0,                          // Reserved
    Default_Handler,            // PendSV
    Default_Handler             // SysTick
};
