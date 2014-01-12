WoolyBeast_HCSR04
=================

### HC-SR04 ultrasonic range finder library for Arduino

####How to use:

1. Include this library
2. Define your trigger and echo pins
3. Initialize a WoolyBeast_HCSR04 object either statically or on the heap from within setup(), passing as arguments the trigger and echo pin references
4. Call WoolyBeast_HCSR04::begin() passing current air temperature (defaults to 20 degrees Celsius, which is about room temperature).
5. Within loop(), call sample() which returns a duration in microseconds
6. Convert to distance in centimeters or inches with WoolyBeast_HCSR04::distance()

####Simple Sample:
```

#include <WoolyBeast_HCSR04.h>

#define TRIGGER_PIN 7
#define ECHO_PIN 8

WoolyBeast_HCSR04  hcsr04(TRIGGER_PIN,ECHO_PIN);

void setup()
{
  hcsr04.begin();
  Serial.begin(9600);
}

void loop()
{
  unsigned long duration = hcsr04.sample();
  double distanceCM = hcsr04.distance(duration);
  double distanceIN = hcsr04.distance(duration,WoolyBeast_HCSR04::IN);
  Serial.print(distanceCM);
  Serial.println(" cm");
  Serial.print(distanceIN);
  Serial.println(" in");
  
  delay(1000);  // delay a second or whatever you want
}
```
