#include "HC165D.h"

HC165D:: HC165D() : dataWidth(8), pulseWidth(5), lastState(0), currentState(0) {}

void HC165D::begin(int pload, int clockEN, int data, int clock) {
  pinMode(ploadPin = pload, OUTPUT);
  pinMode(clockEnablePin = clockEN, OUTPUT);
  pinMode(dataPin = data, INPUT);
  pinMode(clockPin = clock, OUTPUT);
}

uint8_t HC165D::getPulseWidth() { return pulseWidth; }
void HC165D::setPulseWidth(uint8_t value) { pulseWidth = value; }
uint16_t HC165D::getDataWidth() { return dataWidth; }

boolean HC165D::hasChanged() { return lastState != currentState; }
boolean HC165D::hasChanged(int id) { return state(id) != last(id); }

uint64_t HC165D::getLast() { return lastState; }
uint64_t HC165D::getCurrent() { return currentState; }

boolean HC165D::state(int id) { return bitRead(currentState, id); }
boolean HC165D::last(int id) { return bitRead(lastState, id); }

boolean HC165D::pressed(int id) { return !last(id) && state(id); }
boolean HC165D::released(int id) { return last(id) && !state(id); }

uint64_t HC165D::read() {
  lastState = currentState;
  uint64_t result = 0;

  digitalWrite(clockEnablePin, HIGH);
  digitalWrite(ploadPin, LOW);
  delayMicroseconds(pulseWidth);
  digitalWrite(ploadPin, HIGH);
  digitalWrite(clockEnablePin, LOW);

  for (uint16_t i = 0; i < dataWidth; i++) {
    uint64_t value = digitalRead(dataPin);
    result |= (value << ((dataWidth - 1) - i));
    digitalWrite(clockPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(clockPin, LOW);
  }
  currentState = result;
  return result;
}

boolean HC165D::update() {
  return read() != lastState;
}
