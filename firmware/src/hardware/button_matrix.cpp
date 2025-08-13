#include "hardware/button_matrix.h"
#include "hardware/hardware_manager.h"

uint16_t ButtonMatrix::states = 0xffff, ButtonMatrix::prev_states = 0xffff;

bool ButtonMatrix::has_changed(){
  return states != prev_states;
}

bool ButtonMatrix::get_state(buttons_switches target){
  return (states >> target) & 1;
}

void ButtonMatrix::scan(){
  HC165D shift_reg =  HardwareManager::get_shift_reg();
  HC4051 mux = HardwareManager::get_mux();

  uint8_t shift_in = 0;

  mux.setChannel(2);
  shift_in = shift_reg.read();
  Serial.println(shift_in, BIN);

  // for(int mux_channel = 0; mux_channel < 4; mux_channel++){
  //   mux.setChannel(mux_channel);
  //   shift_in = shift_reg.read();
  //   Serial.print(shift_in, BIN);
  //   Serial.print(" ");
  // }
  // Serial.println(" ");
}

void ButtonMatrix::query_event(button_matrix_event *events, int &event_count){
  const int num_buttons = MAX_BUTTON_MATRIX_EVENTS;

  uint16_t mask = 1;
  int num_events = 0;

  for(int i = 0; i < num_buttons; i++){
    bool prev_bit = (prev_states & mask) != 0;
    bool curr_bit = (states & mask) != 0;
    if(prev_bit != curr_bit){
      events[num_events].target = (buttons_switches)i;
      events[num_events].trigger = curr_bit ? RISE : FALL;
      num_events++;
    }
    mask <<= 1;
  }

  event_count = num_events;
}

// make an rtos task that runs scan, query_events continuously and
// put those events inside a queue for the UI to process
