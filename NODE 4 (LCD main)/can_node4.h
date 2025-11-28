#include <lpc21xx.h>

void can_init(void);
void can_rx1(can_msg *);
void can_rx2(can_msg *);

void can_init(void)
{
    PINSEL1 = 0X00014000;
    VPBDIV = 1;

    C2MOD = 0X01;
    C2BTR = 0X001C001D;
    AFMR = 0X02;
    C2MOD = 0X00;
}

void can_rx1(can_msg *m1)
{
    while ((C2GSR & 0x1) == 0);
    m1->msgid = C2RID;
    m1->rtr = (C2RFS >> 30) & 0X1;
    m1->dlc = (C2RFS >> 16) & 0XF;
    m1->byteA = C2RDA;
    m1->byteB = C2RDB;

    C2CMR = (1 << 2); //Release receive buffer
}

void can_rx2(can_msg *m2)
{
    while ((C2GSR & 0x1) == 0);
    m2->msgid = C2RID;
    m2->rtr = (C2RFS >> 30) & 0X1;
    m2->dlc = (C2RFS >> 16) & 0XF;
    m2->byteA = C2RDA;

    C2CMR = (1 << 2); //Release receive buffer
}
