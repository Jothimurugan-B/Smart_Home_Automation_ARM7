/********** IR SENSOR NODE *********/

#include<lpc21xx.h>
#include"delay.h"
#include"lcd.h"

#define IR 10
#define LED 11

typedef unsigned int u32;

typedef struct can_frame
{
	u32 msgid;
	u32 rtr;
	u32 dlc;
	u32 byteA;
	u32 byteB;
}can_msg;
#include"can_node1.h"

int main()
{
	can_msg m1;
	IODIR0|=1<<LED;
	
	can_init();
	lcd_init();
	

//	while(1)
//	{
	m1.msgid=0x100;
	m1.rtr=0;
	m1.dlc=4;
   
   while(1)
   {
	
	if(((IOPIN0>>IR)&1)==0)
	{
	 delay_ms(200);
	 IOCLR0=1<<LED;
	 m1.byteA=0;
	 }
	else
	m1.byteA=1;	
	
	can_tx(m1);
	delay_sec(1);
//	m1.byteA++;
// delay_sec(2);


	}
}
	

