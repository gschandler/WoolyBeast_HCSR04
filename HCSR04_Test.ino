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

