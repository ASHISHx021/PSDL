#include<pic18f458.h>

#pragma config OSC= HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define buzzer PORTAbits.RA3
#define relay PORTDbits.RD4
#define button1 PORTBbits.RB0
#define button2 PORTBbits.RB1
#define LED0 PORTDbits.RD0
#define LED1 PORTDbits.RD1
#define LED2 PORTDbits.RD2
#define LED3 PORTDbits.RD3

void Led_ltorseq(void);
void Led_rtolseq(void);
void delay(unsigned int);

void main(void) {
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISAbits.TRISA3 = 0;
    TRISD = 0x00;
    PORTD = 0xFF;
    relay = 0;
    buzzer = 0;

    while (1) {
        if (button1 == 0) {
            relay = 1;
            buzzer = 1;
            Led_ltorseq();
            while (button2 != 0);
        }
        else if (button2 == 0) {
            buzzer = 0;
            relay = 0;
            Led_rtolseq();
            while (button1 != 0);
        }
    }
}

void Led_ltorseq(void) {
    LED0 = 0;
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;
    delay(1000);
    LED0 = 1;
    LED1 = 0;
    LED2 = 1;
    LED3 = 1;
    delay(1000);
    LED0 = 1;
    LED1 = 1;
    LED2 = 0;
    LED3 = 1;
    delay(1000);
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED3 = 0;
    delay(1000);
}

void Led_rtolseq(void) {
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED3 = 0;
    delay(1000);
    LED0 = 1;
    LED1 = 1;
    LED2 = 0;
    LED3 = 1;
    delay(1000);
    LED0 = 1;
    LED1 = 0;
    LED2 = 1;
    LED3 = 1;
    delay(1000);
    LED0 = 0;
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;
    delay(1000);
}

void delay(unsigned int x) {
    unsigned int i;
    unsigned char j;
    for (i = 0; i < x; i++)
        for (j = 0; j < 165; j++);
}
