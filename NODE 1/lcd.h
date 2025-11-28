#include <LPC21XX.H>

#define LCD 0XFF
#define RS (1<<8)
#define E  (1<<9)

void lcd_init(void);
void lcd_command(unsigned char);
void lcd_intg(unsigned int);
void lcd_string(unsigned char*);
void lcd_data(int);

void lcd_init(void)
{
    IODIR0 = 0X3FF;
    lcd_command(0X01);
    lcd_command(0X02);
    lcd_command(0X0C);
    lcd_command(0X38);
    lcd_command(0X80);
}

void lcd_command(unsigned char cmd)
{
    IOCLR0 = LCD;
    IOSET0 = cmd;
    IOCLR0 = RS;
    IOSET0 = E;
    delay_ms(2);
    IOCLR0 = E;
}

void lcd_intg(unsigned int n)
{
    int i = 0, a[10];
    while (n != 0) {
        a[i++] = n % 10;
        n = n / 10;
    }
    for (--i; i >= 0; i--)
        lcd_data(a[i] + 48);
}

void lcd_string(unsigned char* s)
{
    int i;
    for (i = 0; s[i]; i++)
        lcd_data(s[i]);
}

void lcd_data(int d)
{
    IOCLR0 = LCD;
    IOSET0 = d;
    IOSET0 = RS;
    IOSET0 = E;
    delay_ms(2);
    IOCLR0 = E; 
}
