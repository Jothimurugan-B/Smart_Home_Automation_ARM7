#include <LPC21XX.H>

void delay_sec(int t);
void delay_ms(int t);
void delay_microsec(int t);

void delay_sec(int t)
{
    T0PR = 60000000 - 1;
    T0TCR = 0x1;
    while (T0TC < t);
    T0TCR = 0x3;
    T0TCR = 0x0;
}

void delay_ms(int t)
{
    T0PR = 60000 - 1;
    T0TCR = 0x1;
    while (T0TC < t);
    T0TCR = 0x3;
    T0TCR = 0x0;
}

void delay_microsec(int t)
{
    T0PR = 60 - 1;
    T0TCR = 0x1;
    while (T0TC < t);
    T0TCR = 0x3;
    T0TCR = 0x0;
}
