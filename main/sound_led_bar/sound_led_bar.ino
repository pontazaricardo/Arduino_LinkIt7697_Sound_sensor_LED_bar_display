#include <Grove_LED_Bar.h>

const int pinAdc = A0;
Grove_LED_Bar bar(9, 8, 0);  // Clock pin, Data pin, Orientation

void setup()
{
  // nothing to initialize
  Serial.begin(9600);
  bar.begin();
}

void loop()
{
  // 0 = 0x0 = all 10 LEDs turned off
  // 1023 = 0x3FF = all 10 LEDs lit up.

    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pinAdc);
    }

    sum >>= 5;

    sum = sum-180;
  
    bar.setBits(sum);
    Serial.println(sum);
    delay(100);
}
