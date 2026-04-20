#include<lpc21xx.h>
#include "bluetooth dec.h"
int main()
{
	int i=0;
	unsigned char s[20];
	unsigned char rxbyte;
CONFIGURE_();
LCD_CONFIGURE();
	while(1)
	{
		rxbyte = UART0_RX();
		if((rxbyte != '\n')&&(rxbyte != '\r'))
		{
			s[i++] = rxbyte;
			UART0_TX(rxbyte);
    while((U0LSR&1)==0);
		}
	else 
	{
      s[i] = '\0';
      LCD_CMD(0x01);
      LCD_CMD(0x80);
      LCD_STRING(s);
      i=0;		
	}
	}
LED_BLINK();
}
