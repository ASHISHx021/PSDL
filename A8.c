#include<pic18f458.h>
#pragma config OSC = HS
#pragma config WDT= OFF
#pragma config LVP= OFF
#define SW PORTBbits.RB0
#define MTR1 PORTCbits.RC1
#define MTR2 PORTCbits.RC2
void delay(unsigned int);
void main(void)
{
TRISBbits.TRISB0 = 1;
TRISCbits.TRISC1 = 0;
TRISCbits.TRISC2 = 0;
while(1)
{
MTR2 = 0;
if(SW == 0)
{
MTR1 =1;
delay(900);
MTR2 =0;
delay(100);
}
else
{
MTR1 =1;
delay(100);
MTR2 =0;
delay(900);
}
}//end of while
}//end ofmain
void delay(unsigned int x)
{
unsigned int i;
unsigned char j;
for(i= 0;i < x;i++)
{for(j= 0;j< 165;j++);
}
}