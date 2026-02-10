MEMORY {
    /* Flash: 630KB (0x00000000 - 0x0009DFFF) */
    /* Last 10KB (0x0009E000 - 0x0009FFFF) is CMPA/CFPA protected region */
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 630K
    
    /* SRAM0-3: 256KB total (0x20000000 - 0x2003FFFF) */
    /* SRAM4 (64KB at 0x20040000) requires separate clock enable */
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

/* Stack pointer at end of RAM */
_estack = ORIGIN(RAM) + LENGTH(RAM);

ENTRY(Reset_Handler)

SECTIONS {
    /* Interrupt vector table at beginning of flash */
    .isr_vector : {
        KEEP(*(.isr_vector))
    } > FLASH
    
    /* Code and read-only data */
    .text : {
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH
    
    /* Initialized data (loaded from flash to RAM at startup) */
    .data : {
        _sdata = .;
        *(.data*)
        _edata = .;
        . = ALIGN(4);
    } > RAM AT > FLASH
    
    /* Load address of .data section in flash */
    _sidata = LOADADDR(.data);
    
    /* Uninitialized data (zeroed at startup) */
    .bss : {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
        . = ALIGN(4);
    } > RAM
    
    /* Stack size checking */
    .stack (NOLOAD) : {
        . = ALIGN(8);
        . = . + 0x1000; /* 4KB stack */
        . = ALIGN(8);
    } > RAM
}
