/*6-bit Binary Timer

  This program uses the 6 outputs of the Magnolia board to control six
  LEDs that represent the elapsed time in binary.

*/

/*The pins the LEDs are connected to--for the binary timer, the least significant bit is first.*/
const int ledPins[6] = { A0, A1, A2, A3, A4, A5 };

void setup()
{
  for(int i = 0; i < sizeof(ledPins); i++) {
    /*Initialize each pin to output*/
    pinMode(ledPins[i], OUTPUT);
  }
}

int time = 0;

void loop()
{
   for(int i = 0; i < sizeof(ledPins); i++) {
    /*If time has is 1 in the i'th bit*/
    if(time & (1 << i)) {
      /*turn the i'th LED on*/
      digitalWrite(ledPins[i], HIGH);
    } else {
      /*turn the i'th LED off*/
      digitalWrite(ledPins[i], LOW);
    }
  }
  /*Wait one second*/
  delay(1000);
  
  /*Increment time*/
  time++;
}
