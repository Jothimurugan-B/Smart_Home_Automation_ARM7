/************ LDR NODE ************/

#include<lpc21xx.h>
#include"delay.h"
//#include"lcd.h"

#define LDR 10

typedef unsigned int u32;

typedef struct can_frame
{
	u32 msgid;
	u32 rtr;
	u32 dlc;
	u32 byteA;
	u32 byteB;
}can_msg;
#include"can_node4.h"

int main()
{
	can_msg m2;
	
	can_init();
//	lcd_init();
	

	m2.msgid=0x102;
	m2.rtr=0;
	m2.dlc=4;
   
   while(1)
   {
	
	if(((IOPIN0>>LDR)&1)==0)
	{
	 delay_ms(200);
	 m2.byteA=0;
	 }

	else
	m2.byteA=1;	
	
	can_tx(m2);
	delay_sec(2);


	}
}
