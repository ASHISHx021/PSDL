#include<pic18f4520.h>
void main(void)
{
unsigned i,j,k,res=0;
LATB=0;
TRISB=0;
i=0x05;
j=0x04;
for(k=0;k<=j;k++)
{
res =res + i;
}
PORTB=res;
}