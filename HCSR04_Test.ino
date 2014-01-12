/*
The MIT License (MIT)

Copyright (c) 2014 Scott Chandler

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "WoolyBeast_HCSR04.h"

#define  TRIGGER_PIN  8
#define  ECHO_PIN      7
#define  LED_PIN        6

WoolyBeast_HCSR04  ranger(TRIGGER_PIN,ECHO_PIN);

void setup()
{
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(9600);
  
  ranger.begin(20);
}

void  loop()
{
  
  digitalWrite(LED_PIN,HIGH);
  unsigned long duration = ranger.sample();
  digitalWrite(LED_PIN,LOW);
  
  Serial.print(millis()); Serial.print("> "); Serial.print(ranger.distance(duration)); Serial.print(" cm"); Serial.print(" ("); Serial.print(ranger.distance(duration,WoolyBeast_HCSR04::IN)); Serial.println(" inches)");  
  delay(1000);
  
}

