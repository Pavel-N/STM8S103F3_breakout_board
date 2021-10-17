#include "../include/stm8s103f3.h"

void init()
{
    CLK_CKDIVR = 0x00; // Set clock to 16MHz(maximum) - HSI / 1

    PA_ODR = 0x00; // Set all ports A low
    PB_ODR = 0x00; // Set all ports B low
    PC_ODR = 0x00; // Set all ports C low
    PD_ODR = 0x00; // Set all ports D low
}

void Delay_ms(const uint32_t value, const uint16_t delay_multiplier)
{
    uint32_t toWait = delay_multiplier * value;
    volatile uint32_t loopCounter = 0;
    for (loopCounter; loopCounter < toWait; loopCounter++)
    {
        __asm__("nop");
    }
}

static void _setReg(uint8_t *reg, const uint8_t port_number, const _Bool port_state)
{
    if (port_state)
        *reg |= (1 << port_number);
    else
        *reg &= ~(1 << port_number);
}

/* TODO _Bool getState(byte *IDR, byte pin)
{
    if (*IDR ^ (1 << pin) == (0 << pin))
        return 1;
    return 0;
} */

void setPinMode(const uint8_t port_pin, const uint8_t pin_mode)
{
    uint8_t port = (port_pin >> 4) & 0xF;
    uint8_t pin = port_pin & 0xF;

    // pinmode: 0b100 => Open Drain Output
    // ddr = 1; cr1 = 0; cr2 = 0
    uint8_t ddr = (pin_mode >> 2) & 0b111;
    uint8_t cr1 = (pin_mode >> 1) & 0b010;
    uint8_t cr2 = pin_mode & 0b001;

    switch (port)
    {
    case 0xA:
        _setReg(&PA_DDR, pin, ddr);
        _setReg(&PA_CR1, pin, cr1);
        _setReg(&PA_CR2, pin, cr2);
        break;
    case 0xB:
        _setReg(&PB_DDR, pin, ddr);
        _setReg(&PB_CR1, pin, cr1);
        _setReg(&PB_CR2, pin, cr2);
        break;
    case 0xC:
        _setReg(&PC_DDR, pin, ddr);
        _setReg(&PC_CR1, pin, cr1);
        _setReg(&PC_CR2, pin, cr2);
        break;
    case 0xD:
        _setReg(&PD_DDR, pin, ddr);
        _setReg(&PD_CR1, pin, cr1);
        _setReg(&PD_CR2, pin, cr2);
        break;

    default:
        break;
    }
}

void setPinState(const uint8_t p, const uint8_t state)
{
    uint8_t port = (p >> 4) & 0xF;
    uint8_t pin = p & 0xF;

    if (state)
        PD_ODR |= (1 << 5);
    else
        PD_ODR &= ~(1 << 5);

    switch (port)
    {
    case 0xA:
        if (state)
            PA_ODR |= (1 << pin);
        else
            PA_ODR &= ~(1 << pin);
        break;
    case 0xB:
        if (state)
            PB_ODR |= (1 << pin);
        else
            PB_ODR &= ~(1 << pin);
        break;
    case 0xC:
        PC_ODR = (state << pin);
        break;
    case 0xD:
        if (state)
            PD_ODR |= (1 << pin);
        else
            PD_ODR &= ~(1 << pin);
        break;

    default:
        break;
    }
}

_Bool getPinState(const uint8_t port_pin)
{
    uint8_t port = (port_pin >> 4) & 0xF;
    uint8_t pin = port_pin & 0xF;

    switch (port)
    {
    case 0xA:
        if (PA_IDR ^ (1 << pin) == (0 << pin))
            return 1;
        break;
    case 0xB:
        if (PB_IDR ^ (1 << pin) == (0 << pin))
            return 1;
        break;
    case 0xC:
        if (PC_IDR ^ (1 << pin) == (0 << pin))
            return 1;
        break;
    case 0xD:
        if (PD_IDR ^ (1 << pin) == (0 << pin))
            return 1;
        break;

    default:
        break;
    }

    return 0;
}
