#include<lpc21xx.h>
#include "bluetooth dec.h"
int main()
{
	int i=0;
	unsigned char s[20];
	unsigned char rxbyte;
CONFIGURE_();
LCD_CONFIGURE();	
	title();
		
	while(1)
	{
		rxbyte = UART0_RX();
		if((rxbyte != '\n')&&(rxbyte != '\r'))
		{
			s[i++] = rxbyte;
			UART0_TX(rxbyte);
    while((U0LSR&1)==0);
		}
		
		if(rxbyte=='r')
	{		
		LCD_CMD(0x01);
	LCD_CMD(0x02);
		LCD_CMD(0x80);
		LCD_STRING("ROLL NO:V25CE5B2");
		delay_ms(1500);
}
	if(rxbyte=='n')
	{
			LCD_CMD(0x01);
	LCD_CMD(0x02);
		LCD_CMD(0x80);
		LCD_STRING("NAME:BOOPATHY.A");
		delay_ms(1500);
	}
		if(rxbyte=='g')
	{		
		LCD_CMD(0x01);
	LCD_CMD(0x02);
		LCD_CMD(0x80);
		LCD_STRING("GRADE:98%");
		delay_ms(1500);
}
	else  
	{
      s[i] = '\0';
      LCD_CMD(0x01);
      LCD_CMD(0xC0);
      LCD_STRING(s);
      i=0;	
	
	}
}
	}
