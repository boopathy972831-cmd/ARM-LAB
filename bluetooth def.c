#include<lpc21xx.h>
#include "delay.h"
#define LCD_D 0xff<<4
#define En 1<<13
#define Rs 1<<14
#define led 1<<2
#define sw  1<<3
void CONFIGURE_(void)
{
PINSEL0 |= 0x05;
U0LCR = 0x83;
U0DLL = 97;
U0LCR = 0x03;
}
unsigned char UART0_RX(void)
{
while((U0LSR&1)==0);
return U0RBR;
	
}
void UART0_TX(unsigned char ch)
{
U0THR = ch;
while(((U0LSR>>5)&1)==0);
}
void LCD_CMD(unsigned char cmd)
{
	IOCLR0 = LCD_D;
	IOSET0 = cmd<<4;
	IOCLR0 = Rs;
	IOSET0 = En;
	delay_ms(2);
	IOCLR0 = En;
}


void LCD_CONFIGURE(void)
{
IODIR0 |= LCD_D|Rs|En;
LCD_CMD(0x01);
LCD_CMD(0x02);
LCD_CMD(0x38);
LCD_CMD(0x0c);
LCD_CMD(0x80);
	
}


void LCD_DATA(unsigned char d)
{
IOCLR0 = LCD_D;
IOSET0 = d<<4;
IOSET0 = Rs;
IOSET0 = En;
delay_ms(2);
IOCLR0 = En;
}
void LCD_STRING(unsigned char*s)
{
while(*s)
LCD_DATA(*s++);
}
void LED_BLINK(void)
{
	IODIR0=led;
	while(1)
	{
		if(((IOPIN0>>2)&1)==0)
		{
			IOCLR0=led;
		}
			else
			{
				IOSET0=led;
			}
		}
	}
