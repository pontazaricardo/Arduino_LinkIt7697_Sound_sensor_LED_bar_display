#include <Grove_LED_Bar.h>

const int pinAdc = A0;
Grove_LED_Bar bar(9, 8, 0);  // Clock pin, Data pin, Orientation. Modify for your input pin (in our case, pin 8 in the LinkIt 7697).

void setup()
{
  Serial.begin(9600);	//We print to serial monitor
  bar.begin();	//Initialize the LED bar.
}

void loop()
{
	//LED use binary from 0 to 1023 = 2^10-1. There are 10 slots in the LED bar.

    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pinAdc);
    }

	//We shift numbers 5 digits and substract a value of 180 to make it fit the range of 0-1023.
    sum >>= 5;
    sum = sum-180;
  
    bar.setBits(sum);	//Turns on the LED bar and sets the number.
    Serial.println(sum);
    delay(100);
}
