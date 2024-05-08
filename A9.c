#include <pic18f4520.h>
#include<stdio.h>

#pragma config OSC = HS
// High-speed oscillator
#pragma config WDT = OFF
// Watchdog Timer disabled
#pragma config LVP = OFF
// Low-voltage Programming disabled
void InitUSART (void)
{
TRISCbits.RC6 =0;//make Tx Pin of UART
TRISCbits.RC7 = 1; //make Rx Pin of UART SPBRG 32;
//9600 baud @20MHz (HS MODE) //Transmitter Enable TXSTA = 0x20;
RCSTAbits.SPEN = 1; //Serial Port Enable
RCSTAbits.CREN = 1; //Continues Receive Enable bit
}
void main(void)
{
unsigned char ch;
InitUSART();
printf("WELCOME, I am PIC microcontroller\r\n");
printf("I am Ready, Please Enter Character from Computer\r\n");
while (1)
{ while (PIR1bits.RCIF == 0);
ch = RCREG;

while(PIR1bits.TXIF == 0);
TXREG = ch;
//wait until there's a character to be read ch = RCREG; //then read from the Receiver Buffer Register & store in ch vari while (PIR1bits. TXIF == 0); //wait until Transmitter Buffer Register Empty TXREG = ch; //then write to the Transmitter Buffer Register
}
}
