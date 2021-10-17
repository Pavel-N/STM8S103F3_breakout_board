#ifndef STM8S103F3
#define STM8S103F3

#include <stdint.h>

// Pins
#define A1 0xA1
#define A2 0xA2
#define A3 0xA3

#define B4 0xB4
#define B5 0xB5

#define C3 0xC3
#define C4 0xC4
#define C5 0xC5
#define C6 0xC6
#define C7 0xC7

#define D1 0xD1
#define D2 0xD2
#define D3 0xD3
#define D4 0xD4
#define D5 0xD5
#define D6 0xD6


// Clock
#define CLK_CKDIVR   *(volatile uint8_t *)0x50C6   // Clock divider register
#define DELAY_MUL_16 635                           // Delay mutliplier for 16Mhz

// Port A
#define PA_ODR       *(volatile uint8_t *)0x5000   // Port A Output Data Register
#define PA_IDR       *(volatile uint8_t *)0x5001   // Port A Input Data Register
#define PA_DDR       *(volatile uint8_t *)0x5002   // Port A Data Direction Rrgister
#define PA_CR1       *(volatile uint8_t *)0x5003   // Port A Control Register 1
#define PA_CR2       *(volatile uint8_t *)0x5004   // Port A Control Register 2

// Port B
#define PB_ODR       *(volatile uint8_t *)0x5005   // Port B Output Data Register
#define PB_IDR       *(volatile uint8_t *)0x5006   // Port B Input Data Register
#define PB_DDR       *(volatile uint8_t *)0x5007   // Port B Data Direction Rrgister
#define PB_CR1       *(volatile uint8_t *)0x5008   // Port B Control Register 1
#define PB_CR2       *(volatile uint8_t *)0x5009   // Port B Control Register 2

// Port C
#define PC_ODR       *(volatile uint8_t *)0x500A   // Port C Output Data Register
#define PC_IDR       *(volatile uint8_t *)0x500B   // Port C Input Data Register
#define PC_DDR       *(volatile uint8_t *)0x500C   // Port C Data Direction Rrgister
#define PC_CR1       *(volatile uint8_t *)0x500D   // Port C Control Register 1
#define PC_CR2       *(volatile uint8_t *)0x500E   // Port C Control Register 2

// Port D
#define PD_ODR       *(volatile uint8_t *)0x500F   // Port D Output Data Register
#define PD_IDR       *(volatile uint8_t *)0x5010   // Port D Input Data Register
#define PD_DDR       *(volatile uint8_t *)0x5011   // Port D Data Direction Rrgister
#define PD_CR1       *(volatile uint8_t *)0x5012   // Port D Control Register 1
#define PD_CR2       *(volatile uint8_t *)0x5013   // Port D Control Register 2

// State
#define HIGH 1
#define LOW 0

// Pin Mode
// Input
#define FLOATING_INPUT_NO_INT  0b000 // Floating Input without Interupt
#define FLOATING_INPUT_INT     0b001 // Floating Input with Interupt
#define PULLUP_INPUT_NO_INT    0b010 // Pull-up Input without Interupt
#define PULLUP_INPUT_INT       0b011 // Pull-up Input with Interupt
// Output
#define OPEN_DRAIN_OUTPUT      0b100 // Open Drain Output
#define OPEN_DRAIN_OUTPUT_FAST 0b101 // Open Drain Output Fast mode
#define PUSHPULL_OUTPUT        0b110 // Push-pull output
#define PUSHPULL_OUTPUT_FAST   0b111 // Push-pull Output Fast mode


// FUNCTIONS

void init();

void Delay_ms(const uint32_t value, const uint16_t delay_multiplier);

static void _setReg(uint8_t *reg, const uint8_t pos, const _Bool val);

void setPinMode(const uint8_t port_pin, const uint8_t pin_mode);

void setPinState(const uint8_t pin, const uint8_t state);

_Bool getPinState(const uint8_t port_pin);

#endif