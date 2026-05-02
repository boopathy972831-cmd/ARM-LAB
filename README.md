#include <lpc21xx.h>

// Control pins
#define RS (1<<8)
#define EN (1<<9)

// Data pins P0.4 to P0.7
#define DATA_MASK (0xF << 4)

// Delay
void delay(unsigned int time) {
    unsigned int i, j;
    for(i=0;i<time;i++)
        for(j=0;j<1000;j++);
}

// Send command
void lcd_cmd(unsigned char cmd) {
    IO0CLR = DATA_MASK;
    IO0SET = (cmd & 0xF0) >> 4;  // upper nibble → P0.4–P0.7
    IO0CLR = RS;
    IO0SET = EN;
    delay(2);
    IO0CLR = EN;

    IO0CLR = DATA_MASK;
    IO0SET = (cmd & 0x0F) << 4;  // lower nibble
    IO0SET = EN;
    delay(2);
    IO0CLR = EN;
}

// Send data
void lcd_data(unsigned char data) {
    IO0CLR = DATA_MASK;
    IO0SET = (data & 0xF0) >> 4;
    IO0SET = RS;
    IO0SET = EN;
    delay(2);
    IO0CLR = EN;

    IO0CLR = DATA_MASK;
    IO0SET = (data & 0x0F) << 4;
    IO0SET = EN;
    delay(2);
    IO0CLR = EN;
}

// Init LCD
void lcd_init() {
    IO0DIR |= DATA_MASK | RS | EN;

    delay(20);

    lcd_cmd(0x02); // 4-bit mode
    lcd_cmd(0x28); // 2-line
    lcd_cmd(0x0C); // display ON
    lcd_cmd(0x06); // cursor increment
    lcd_cmd(0x01); // clear
}

// Print string
void lcd_string(char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

int main() {
    lcd_init();
    lcd_string("4-bit LCD");

    while(1);
}
