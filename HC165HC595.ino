#include "HC165HC595.h"
#define DIN_Pin 5
#define CLKO_Pin  6
#define LATCH_Pin 3

byte key  = 0;
keypad Key(DIN_Pin,CLKO_Pin,LATCH_Pin);

byte getkey()
{
  digitalWrite(LATCH_Pin,HIGH);
  byte a_key = Key.getkey();
  digitalWrite(LATCH_Pin,LOW);
  if(a_key  !=  key)
  {
    key = a_key;
    if(key  !=  255)
    {
    Serial.println(key,DEC); 
    }
  } 
}
void setup() {
  Serial.begin(9600);
  digitalWrite(LATCH_Pin,LOW);
  digitalWrite(CLKO_Pin,LOW);
}

void loop() {
  getkey();

}
