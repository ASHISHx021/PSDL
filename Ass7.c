#include<pic18f458.h>
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config LVP=OFF

#define D4 LATCbits.LATC2
#define D5 LATEbits.LATE0
#define D6 LATEbits.LATE1
#define D7 LATEbits.LATE2
#define RS LATCbits.LATC0
#define EN LATCbits.LATC1

void delay(unsigned int x);
void LedData(unsigned char data);
void LedData1(unsigned char data);
void LedCmd(unsigned char cmd);
void LedCmd1(unsigned char cmd);
void main(void)
{
     TRISCbits.TRISC0=0;
    TRISCbits.TRISC1=0;
    TRISCbits.TRISC2=0;
    TRISEbits.TRISE0=0;
    TRISEbits.TRISE1=0;
    TRISEbits.TRISE2=0;
    RS=0;
    EN=0;
    D4=0;
    D5=0;
    D6=0;
    D7=0;
    LedCmd(0x28);
    LedCmd(0x0C);
    LedCmd(0x01);
    LedCmd(0x06);
    LedCmd(0x80);
    LedData('V');
    LedData('P');
    LedCmd(0xC0);
    LedData('C');
    LedData('O');
    LedData('E');
    while(1);
            
}
void delay(unsigned int x)
{
    unsigned int i;
    unsigned int j;
    for(i=0;i<x;i++)
    {
        for(j=0; j < 165; j++);
    }
    
}
void LedCmd(unsigned char cmd)
{
    RS=0;
    LedCmd1(cmd>>4);
    LedCmd1(cmd&0x0F);
    delay(200);
}
void LedCmd1(unsigned char cmd)
{
    if(cmd&0x01)
        D4=1;
    else
        D4=0;
    if(cmd&0x02)
        D5=1;
    else
        D5=0;
    if(cmd&0x04)
        D6=1;
    else
        D6=0;
    if(cmd&0x08)
        D7=1;
    else
        D7=0;
    EN=1;
    delay(1);
    EN=0;
}
void LedData(unsigned char data)
{
    RS=1;
    LedData1(data>>4);
    LedData1(data&0x0F);
    delay(200);
}
void LedData1(unsigned char data)
{
    if(data&0x01)
        D4=1;
    else
        D4=0;
    if(data&0x02)
        D5=1;
    else
        D5=0;
    if(data&0x04)
        D6=1;
    else
        D6=0;
    if(data&0x08)
        D7=1;
    else
        D7=0;
    EN=1;
    delay(1);
    EN=0;
}