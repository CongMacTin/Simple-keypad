#include "Arduino.h"
#include "HC165HC595.h"

keypad::keypad(int D_IN_Pin,int CLKO_Pin,int LATCH_Pin)
{
  _D_IN_Pin = D_IN_Pin;
  _CLKO_Pin = CLKO_Pin;
  _LATCH_Pin  = LATCH_Pin;
  
  pinMode(_D_IN_Pin,INPUT);
  pinMode(_CLKO_Pin,OUTPUT);
  pinMode(_LATCH_Pin,OUTPUT);

  byte getkey();
} 

byte keypad::getkey()
{
  _key  = 0;
  for(int i;i<8;i++)
  {
    digitalWrite(_CLKO_Pin,HIGH);
    _key  = _key|digitalRead(_D_IN_Pin)<<i;
    digitalWrite(_CLKO_Pin,LOW);
  }
   return _key;
 }

