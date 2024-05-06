#include<pic18f4520.h> // Assuming you're using a PIC microcontroller and XC8 compiler

void main() {
    int result = 0;
    int num1= 3;
    int num2= 10;
    int i;

    // Step 3: Make PORTB as output port
    TRISB = 0;

    // Step 2: Perform the multiplication
    for(i= 1; i <= num2; i++) {
        result = result + num1;
    }

    // Step 4: Store the result in PORTB
    PORTB = result;

   
}
