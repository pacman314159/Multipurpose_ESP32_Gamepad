#include "ui_manager.h"
#include "hardware_config.h"
#include "hardware/hardware_manager.h" 

// Define the static member
lv_obj_t* UIManager::main_screen = nullptr;

static lv_draw_buf_t draw_buf;
static lv_color_t buf1[TFT_HOR_RES * TFT_VER_RES];  // Buffer size: TFT_VER_RES lines

static void disp_flush_cb(lv_display_t* disp, const lv_area_t* area, uint8_t* px_map) {
  TFT_eSPI& lcd = HardwareManager::get_lcd();

  lcd.startWrite();
  lcd.setAddrWindow(area->x1, area->y1,
                    area->x2 - area->x1 + 1,
                    area->y2 - area->y1 + 1);
  lcd.pushColors((uint16_t*)px_map,
    (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1),
    true);
  lcd.endWrite();

  lv_display_flush_ready(disp);  // correct for 9.3
}

void UIManager::init() {
  lv_init();

  // Initialize draw buffer
  lv_draw_buf_init(&draw_buf, TFT_HOR_RES, TFT_VER_RES, LV_COLOR_FORMAT_RGB565, 0, buf1, sizeof(buf1));

  // Create and configure display
  lv_display_t* disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_draw_buffers(disp, &draw_buf, nullptr);
  lv_display_set_flush_cb(disp, disp_flush_cb);

  create_main_screen();
  lv_scr_load(main_screen);
}

void UIManager::create_main_screen() {
  main_screen = lv_obj_create(nullptr);  // Create a blank screen

  lv_obj_t* label = lv_label_create(main_screen);
  lv_label_set_text(label, "Welcome!");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

void UIManager::show_main_screen() {
  lv_scr_load(main_screen);
}
