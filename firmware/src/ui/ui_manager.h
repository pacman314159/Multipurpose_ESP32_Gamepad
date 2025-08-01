#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "lvgl.h"
#include "hardware_config.h"

class UIManager {
public:
  static void init();
  static void show_main_screen();

private:
  static lv_obj_t* main_screen;

  static void create_main_screen();
};

#endif
