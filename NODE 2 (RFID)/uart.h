void UART0_CONFIGURE()
{
PINSEL0 |=0X05;  // PO.0,PO.1    TX & RX 
U0LCR=0X83;
//(60000000)/(16*9600)	=>390 
U0DLL=134;		   //134
U0DLM=1;	 //1
U0LCR=0X3;
}

void UART0_TX(unsigned char data)
{
while(((U0LSR>>5)&1)==0);
U0THR=data;
}



void uart_str(char *s)
{
while(*s)
{
UART0_TX(*s++);
}
}
