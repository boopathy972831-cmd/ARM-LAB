#include"delay_header.h"
#define LCD_D 0xff<<0
#define RS 1<<8
#define E 1<<9
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);

void LCD_INIT(void)
{
	IODIR0=LCD_D|RS|E;
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x02);
	LCD_COMMAND(0x0C);
	LCD_COMMAND(0x38);
	LCD_COMMAND(0x1C);
}
	
void LCD_COMMAND(unsigned char cmd)
{
	IOCLR0=LCD_D;
	IOSET0=cmd;
	IOCLR0=RS;
	IOSET0=E;
	delay_milliseconds(2);
	IOCLR0=E;
}
void LCD_DATA(unsigned char dat)
{
	IOCLR0=LCD_D;
	IOSET0=dat;
	IOSET0=RS;
	IOSET0=E;
	delay_milliseconds(2);
	IOCLR0=E;
}



	
