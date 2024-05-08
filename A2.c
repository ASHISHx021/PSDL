#include<pic18f4520.h>
void main(void)
{
 int no[] ={0x02,0x03,0x04,0x05}; 
 int n = 4;
 int res = 0;
LATB=0;
TRISB=0;

for(int k=0;k <n;k++)
{
res =res + no[k];
}
PORTB=res;
}