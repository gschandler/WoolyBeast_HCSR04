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
#include "Arduino.h"

WoolyBeast_HCSR04::WoolyBeast_HCSR04( int triggerPin, int echoPin ) : _triggerPin(triggerPin), _echoPin(echoPin), _soundVelocity(34300)
{
}

void  WoolyBeast_HCSR04::begin( int temperatureInCM )
{
    _soundVelocity = long(331.4 + 0.6*float(temperatureInCM)) * 100;
    pinMode(_triggerPin,OUTPUT);
    pinMode(_echoPin,INPUT);
}

unsigned long  WoolyBeast_HCSR04::sample(void) const
{
  digitalWrite(_triggerPin,LOW);    // not sure the next couple of lines are necessary
  delayMicroseconds(2); 
  
  digitalWrite(_triggerPin,HIGH);
  delayMicroseconds(10);           // HC-SR04 requires a 10 microsecond high trigger
  digitalWrite(_triggerPin,LOW);

  unsigned long duration = pulseIn(_echoPin,HIGH);  // echo pin goes low when the signal returns
  
  return duration >> 1;
}

static double convertToSeconds( unsigned long microseconds )
{
  return double(microseconds) / 1000000.0;
}

double  WoolyBeast_HCSR04::distance( unsigned long duration, WoolyBeast_HCSR04::Scale scale ) const
{
    double distance = double(_soundVelocity) * convertToSeconds(duration);
    if ( scale == WoolyBeast_HCSR04::IN ) {
      distance /= 2.54;
    }

    return distance;

}

