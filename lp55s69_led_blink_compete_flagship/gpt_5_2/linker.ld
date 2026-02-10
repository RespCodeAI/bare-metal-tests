ENTRY(Reset_Handler)

/* LPC55S69JBD100
   Flash: 630KB at 0x00000000 (exclude last ~10KB protected CMPA/CFPA region)
   SRAM0-3: 256KB at 0x20000000-0x2003FFFF (SRAM4 not used)
*/

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 630K
  RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 256K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.isr_vector))
    . = ALIGN(4);
  } > FLASH

  .text :
  {
    . = ALIGN(4);
    *(.text*)
    *(.rodata*)
    *(.glue_7*)
    *(.glue_7t*)
    *(.eh_frame*)
    . = ALIGN(4);
  } > FLASH

  _sidata = LOADADDR(.data);

  .data : AT (ADDR(.text) + SIZEOF(.text))
  {
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > RAM

  .bss (NOLOAD) :
  {
    . = ALIGN(4);
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > RAM

  /* Optional: reserve a minimal heap/stack if desired (not used) */
  . = ALIGN(8);
}
