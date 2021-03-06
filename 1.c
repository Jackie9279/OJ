//FIRMWARE FOR SLAVE
#include <reg52.h>
#include <intrins.h>

#define Uint16 unsigned int
#define Uint32 unsigned long
#define uchar unsigned char

sbit nodesel0 = P3 ^ 2;
sbit nodesel1 = P3 ^ 3;
sbit reving = P1 ^ 6;
sbit rw = P3 ^ 4;
sbit SCL2 = P1 ^ 1; //SCL2定义为P1口的第3位脚，连接ADC0831SCL脚
sbit SDA2 = P1 ^ 2; //SDA2定义为P1口的第4位脚，连接ADC0831SDA脚
sbit CS2 = P1 ^ 0;  //CS2定义为P1口的第4位脚，连接ADC0831CS脚

void InitUART(void);
void SendOneByte(unsigned);
void mdproc(uchar);
unsigned char ad0831read(void); //定义该函数为读取ADC0831的数据
Uint16 Crc16(Uint16 *puchMsg, Uint16 usDataLen);

uchar node;
uchar mtx[11], mrx[10];
uchar send101[9] = {0x00, 0x04, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uchar timercnt;

// modbus protocal defination below :
uchar byterev;
bit nodeok;
uchar revptr;
bit crcok;
uchar datalen;
bit procok;
Uint16 delaycnt;

/* CRC 高位字节值表 */
const Uint16 code auchCRCHi[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40};

/* CRC低位字节值表*/
const Uint16 code auchCRCLo[] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40};

void main(void)
{
    unsigned char temp8;
    Uint16 temp16;
    int i;
    reving = 0;
    crcok = 0;
    nodeok = 0;
    timercnt = 0x00;
    datalen = 0;
    for (i = 0; i < 10; i++)
    {
        mrx[i] = 0x00;
    }
    for (i = 0; i < 11; i++)
    {
        mtx[i] = 0x00;
    }

    node = !nodesel1;
    node <<= 1;
    node |= !nodesel0; //SLAVE node is determine by the jumper set
    send101[0] = node; //reply the node nummer

    InitUART();
    /*	for(i=0;i<8;i++)
	{	temp8=send101[i];
		SendOneByte(temp8);
	}*/
    //test sending...
    procok = 0; // preset the PROCCESS OK FLAG is 1,from the RX to PROCCESS OK the bit is 0.
    rw = 0;     //accroding to the MAX485 IC, /RE=1 means transfering ,and /RE=0 means receiving ,after INIT ,default state is receiving for SLAVE
    while (1)
    {
        if (crcok == 1) //plugin the time delay in the communication for monitoring easily in proteus
        {
            reving = 1;

            send101[3] = ad0831read(); //get the ADC data
            for (i = 0; i < 9; i++)
            {
                mtx[i] = send101[i];
            }
            temp16 = Crc16(send101, 9);
            mtx[9] = (temp16 >> 8) & 0x00ff;
            mtx[10] = temp16 & 0x00ff;

            delaycnt = 0x3fff;
            while (delaycnt--)
            {
            }
            rw = 1;
            delaycnt = 0x3ff;
            while (delaycnt--)
            {
            }
            for (i = 0; i < 11; i++)
            {
                temp8 = mtx[i];
                SendOneByte(temp8);
            }
            crcok = 0;
            delaycnt = 0x3ff;
            while (delaycnt--)
            {
            }
            rw = 0;
            reving = 0; // blink the led when received a currect frame and replied
        }
    }
}

Uint16 Crc16(uchar *puchMsg, Uint16 usDataLen)
{
    Uint16 uchCRCHi = 0xFF; /* 高CRC字节初始化  */
    Uint16 uchCRCLo = 0xFF; /* 低CRC 字节初始化 */
    Uint16 temp16;
    Uint32 uIndex;      /* CRC循环中的索引  */
    while (usDataLen--) /* 传输消息缓冲区   */
    {
        temp16 = *puchMsg++;
        uIndex = uchCRCHi ^ temp16; /* 计算CRC          */
        uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
        uchCRCLo = auchCRCLo[uIndex];
    }
    return (uchCRCHi << 8 | uchCRCLo);
}

void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0x0B0;
    if (++timercnt == 50)
    { //	procok=1;
        timercnt = 0;
    }
}

void UARTInterrupt(void) interrupt 4
{
    if (RI)
    {
        RI = 0;
        byterev = SBUF;
        mdproc(byterev);
    }
    else
        TI = 0;
}

void mdproc(uchar b) //the simply MODBUS 04 command processing ,if node is right , then receive the whole frame and cheak the CRC , if CRC is OK ,then reply data to the HOST
{
    Uint16 temp16_1, temp16_2;
    if (nodeok == 0)
    {
        if (b == node)
        {
            nodeok = 1;
            datalen = 7;
            mrx[0] = b;
            revptr = 1;
        }
    }
    else
    {
        mrx[revptr++] = b;
        if (revptr == 8)
        {
            nodeok = 0;
            temp16_1 = Crc16(mrx, 6);
            temp16_2 = mrx[6];
            temp16_2 <<= 8;
            temp16_2 |= mrx[7];
            if (temp16_1 == temp16_2)
            {
                crcok = 1;
                //	reving=~reving;
            }
        }
    }
}

void SendOneByte(unsigned char c)
{
    SBUF = c;
    while (!TI)
        ;
    TI = 0;
}

void InitUART(void)
{
    TMOD = 0x20;
    SCON = 0x50;
    TH1 = 0xFE;
    TL1 = TH1;
    PCON = 0x00;
    EA = 1;
    ES = 1;
    TR1 = 1;

    TMOD |= 0x01;
    TH0 = 0x3C;
    TL0 = 0x0B0; // timer sets at 20ms
    ET0 = 1;
    TR0 = 1;
}

void delay(void) //空5个指令
{
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
}
unsigned char ad0831read(void) //请先了解ADC0831模数转换器的串口协议，再来读本函数，
{                              //本函数是模拟0831的串口协议进行的，当你了解用软件去模拟一个端口的协议
                               //以后，对于一个硬件这样的端口就简单多了
    unsigned char i = 0, tmp = 0;
    SDA2 = 1;
    CS2 = 0;
    _nop_();
    _nop_();

    SCL2 = 0;
    _nop_();
    _nop_();

    SCL2 = 1;
    _nop_();
    _nop_();

    SCL2 = 0;
    _nop_();
    _nop_();

    SCL2 = 1;
    _nop_();
    _nop_();

    SCL2 = 0;
    _nop_();
    _nop_();

    for (i = 0; i < 8; i++)
    {
        tmp <<= 1;
        if (SDA2)
            tmp++;
        SCL2 = 1;
        _nop_();
        _nop_();

        SCL2 = 0;
        _nop_();
        _nop_();
    }
    CS2 = 1;
    return tmp;
}
