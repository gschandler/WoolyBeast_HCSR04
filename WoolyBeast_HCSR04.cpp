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

