#include<lpc21xx.h>
#include"delay.h"
#include"lcd.h"

#define LED1 11
#define LED2 12

typedef unsigned int u32;
typedef struct can_frame

{
	u32 msgid;
	u32 rtr;
	u32 dlc;
	u32 byteA;
	u32 byteB;

}can_msg;

#include"can_node2.h"

int main()

{
    u32 n1 = 0X100;
	u32 n4 = 0X102;
	u32 rfid = 0x104;
	can_msg m1;

	IODIR0 |= 1<<LED1 | 1<<LED2;
	IOSET0 = 1<<LED1 | 1<<LED2;

     can_init();
	  lcd_init();
	
   while(1)
   {
	can_rx1(&m1);



	  if(m1.msgid==n1)
	  {

	 if(m1.byteA == 0)
	 {
	 lcd_command(0X01);
	  lcd_command(0X80);
	 lcd_string("Person detected");
	 delay_sec(2);
	 }
	 }

	  if(m1.msgid==n4)
	  {
	 	if(m1.byteA == 0)
		 {
	  	lcd_command(0X01);
	 	 lcd_command(0XC0);
		 lcd_string("Lights off");
		 IOSET0 = 1<<LED1;
	 	delay_ms(500);
	     }

		 else
	 	{
	 	 lcd_command(0X01);
	 	 lcd_command(0XC0);
	  	lcd_string("Lights on");
	  	IOCLR0 = 1<<LED1;
	  	delay_ms(500);
		 }
	 }

	 if(m1.msgid==rfid)
	  {
		 if(m1.byteA == 0)
	 	{
	 	 lcd_command(0X01);
	 	 lcd_command(0X94);
	 	lcd_string("No entry");
	   	IOSET0 = 1<<LED2;
		 delay_ms(500);
	 }

	 else if(m1.byteA == 1)
	 {
	  lcd_command(0X01);
	  lcd_command(0X94);
	  lcd_string("person1 detected");
	  IOCLR0 = 1<<LED2;
	  delay_ms(500);
	  }

	  else if(m1.byteA == 2)
	 {
	  lcd_command(0X01);
	  lcd_command(0X94);
	  lcd_string("person2 detected");
	  IOCLR0 = 1<<LED2;
	  delay_ms(500);
	  }

	  else if(m1.byteA == 3)
	 {
	  lcd_command(0X01);
	  lcd_command(0X94);
	  lcd_string("person3 detected");
	  IOCLR0 = 1<<LED2;
	  delay_ms(500);
	 }
	}
  }
}

