#include<pic18f4520.h>
void main(void)
{
unsigned int i,j,k;
TRISB=0;
LATB=0;
i=0x04;
j=0x02;
k=i+j;
PORTC=i;
PORTD=j;
PORTB=k;
}