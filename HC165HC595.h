#ifndef HC165HC595_h
#define HC165HC595_h

class keypad 
{
  public:
    keypad (int D_IN_Pin,int CLKO_Pin,int LATCH_Pin);
    byte getkey();
  private:
    int _D_IN_Pin;
    int _CLKO_Pin;
    int _LATCH_Pin;
    byte  _key;

  
};

#endif
