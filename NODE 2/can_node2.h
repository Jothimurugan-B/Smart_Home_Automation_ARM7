#include <lpc21xx.h>

void can_init(void);
void can_tx(can_msg);

void can_init(void)
{
    PINSEL1 |= 0X00014000;
    VPBDIV = 1; //60 MHz

    C2MOD = 0X01; //Reset mode
    AFMR = 0X02;
    C2BTR = 0X001C001D; //125 kbs @ 60 MHz

    C2MOD = 0X00; //Normal mode
}

void can_tx(can_msg m2)
{
    C2TID1 = m2.msgid;
    C2TFI1 = (m2.dlc << 16);

    if (m2.rtr == 0)
    {
        C2TFI1 &= ~(m2.rtr << 30);
        C2TDA1 = m2.byteA;
        C2TDB1 = m2.byteB;
    }
    else
    {
        C2TFI1 |= (m2.rtr << 30);
        C2TDA1 = m2.byteA;
        C2TDB1 = m2.byteB;
    }

    C2CMR = (1 << 0) | (1 << 5); //TX Request

    while ((C2GSR & (1 << 3)) == 0); //Wait for transmission
}
