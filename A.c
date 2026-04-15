#include<LPC21xx.H>
void UART0_CONFIG(void);
void UART0_TX(unsigned char);
int main()
{
UART0_CONFIG();
while(1)
UART0_TX('A');
}
void UART0_CONFIG(void)
{
PINSEL0=0x5;
U0LCR=0X83;
U0DLL=97;
U0DLM=0;
U0LCR=0X03;
}
void UART0_TX(unsigned char txbyte)
{
U0THR=txbyte;
while(((U0LSR>>5)&1)==0);
}
