
#include <stdint.h>

// 1. Define the Hardware Addresses directly
#define GPIO_ADDR      0x400020
#define UART_TX        0x400008
#define UART_STATUS    0x400010

// 2. Minimal function to send ONE character to screen
void put_char(char c) {
    // Wait until UART is ready (Check Bit 9)
    while (*(volatile int *)UART_STATUS & (1 << 9)); 
    // Send the character
    *(volatile int *)UART_TX = c;
}

void main() {
    // A. Setup the pointer to our GPIO
    volatile int *gpio = (volatile int *)GPIO_ADDR;

    // B. WRITE: Send 5 to the GPIO (Binary 101 -> LED 0 and 2 ON)
    *gpio = 5;

    // C. READ: Read it back into a variable
    int val = *gpio;

    // D. PRINT: Show the result on screen
    // We expect 5. To print '5', we just add '0' (ASCII math)
    put_char('R');
    put_char('e');
    put_char('a');
    put_char('d');
    put_char(':');
    put_char(' ');
    put_char(val + '0'); // Simpler than the big print_hex function!
    put_char('\n');
}