#include<lpc21xx.h>


void can_init(void);

void can_tx(can_msg);




void can_init(void)

{

  PINSEL1|=0X00014000;

	VPBDIV=1; //60 MHz

	

	C2MOD = 0X01; //Reset mode

	AFMR = 0X02;
	C2BTR= 0X001C001D; //125 kbs @ 60 mhz


	C2MOD=0X00; //normal mode

}


void can_tx(can_msg m1)
{
	C2TID1 = m1.msgid;
	C2TFI1 = (m1.dlc<<16);

	if(m1.rtr==0)
	{
	  C2TFI1 &= ~(m1.rtr<<30);

	  C2TDA1 = m1.byteA;

	  C2TDB1 = m1.byteB;
	}
	else
	{
		C2TFI1 |= (m1.rtr<<30);

	  C2TDA1 = m1.byteA;

	  C2TDB1 = m1.byteB;
	}

	C2CMR = (1<<0) | (1<<5); //TX Request

	
	while((C2GSR&(1<<3))==0); //wait for txmission

}
