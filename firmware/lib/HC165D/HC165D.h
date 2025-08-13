#ifndef HC165D_h
#define HC165D_h

#include "Arduino.h"

class HC165D {
private:
  byte ploadPin;
  byte clockEnablePin;
  byte dataPin;
  byte clockPin;

  uint16_t dataWidth;     // number of bits
  uint8_t pulseWidth;     // in microseconds

  uint64_t lastState;
  uint64_t currentState;

public:
  HC165D();

  void begin(int pload, int clockEN, int data, int clock);

  uint8_t getPulseWidth();
  void setPulseWidth(uint8_t value);
  uint16_t getDataWidth();

  boolean hasChanged();
  boolean hasChanged(int id);

  uint64_t getLast();
  uint64_t getCurrent();

  boolean state(int id);
  boolean last(int id);

  boolean pressed(int id);
  boolean released(int id);

  uint64_t read();
  boolean update();
};

#endif
