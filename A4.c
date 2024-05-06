#include<pic18f4520.h>
void main(void)
{
int i,j,temp,n = 5;
int num[] = {0x04,0x03,0x06,0x02,0x01};
TRISA =0;
TRISB= 0;
TRISC =0;
TRISD =0;
TRISE =0;
for(i= 0;i<n-1;i++)
{
for(j= 0;j<n-i-1;j++)
{
if(num[j] >num[j+1])
{
temp =num[j];
num[j] = num[j+1];
num[j+1] = temp;
}
}
}
PORTA = num[4];
PORTB = num[3];
PORTC = num[2];
PORTD = num[1];
PORTE =num[0];
}