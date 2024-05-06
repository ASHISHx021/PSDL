#include<pic18f458.h>
#pragma config OSC = HS
#pragma config WDT = OFF
//#pragma config PBADE = OFF
#pragma config LVP = OFF

#define but1 PORTBbits.RB0
#define LED0  PORTDbits.RD4
#define LED1  PORTDbits.RD5
#define LED2 PORTDbits.RD6
#define LED3 PORTDbits.RD7

void LED1torseq(void);
void delayms(unsigned int);

void main (void){
    TRISBbits.RB0 =1;
    TRISD = 0;
    PORTD = 0xFF;
    while(1){
        if(but1 ==0){
            while(1){
                LED1torseq();
            
            }
        
        }
    
    
    
    }



}

void LED1torseq(void){
    LED0 = 0;
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;

    delayms(1000);
    
    LED0 = 1;
    LED1 = 0;
    LED2 = 1;
    LED3 =1;
    
    delayms(1000);
    
    LED0 = 1;
    LED1 = 1;
    LED2 = 0;
    LED3 = 1;
    
    delayms(1000);
    
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED3 = 0;
    
    delayms(1000);

}

void delayms(unsigned int val){
    unsigned int x;
    unsigned int y;
    
    for ( x = 0; x < val; x++){
        for ( y = 0; y < 165; y++){
            
        }
    
    }



}