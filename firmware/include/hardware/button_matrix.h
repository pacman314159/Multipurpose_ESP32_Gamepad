#ifndef BUTTON_MATRIX_H
#define BUTTON_MATRIX_H

#include <Arduino.h>
#include "hardware/hardware_manager.h"

#define MAX_BUTTON_MATRIX_EVENTS 16

enum buttons_switches{
  CONTROL_BUTTON_UP,
  CONTROL_BUTTON_DOWN,
  CONTROL_BUTTON_LEFT,
  CONTROL_BUTTON_RIGHT,

  ADJUSTMENT_BUTTON_A,
  ADJUSTMENT_BUTTON_B,
  ADJUSTMENT_BUTTON_C,
  ADJUSTMENT_BUTTON_D,

  CORNER_BUTTON_LEFT,
  CORNER_BUTTON_RIGHT,
  CORNER_SWITCH_LEFT,
  CORNER_SWITCH_RIGHT,

  CONFIG_SWITCH_A,
  CONFIG_SWITCH_B,
  CONFIG_SWITCH_C,
  CONFIG_SWITCH_D
};

enum trigger_event{
  RISE,
  FALL
};

struct button_matrix_event{
  buttons_switches target;
  trigger_event trigger; 
};

class ButtonMatrix{
public:
  static uint16_t states, prev_states;
  static void scan();
  static bool has_changed();
  static bool get_state(buttons_switches target);
  static void query_event(button_matrix_event *events, int &event_count);
};

#endif
