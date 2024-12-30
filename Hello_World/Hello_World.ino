#include <lvgl.h> //Note this is using lvgl 8.3.11
#include "ui.h"
#include "ui_helpers.h"
#include <Arduino.h>
#include <Wire.h>
#include "gfx_conf.h"

static lv_disp_draw_buf_t draw_buf;
static lv_color_t disp_draw_buf1[screenWidth * screenHeight / 10];
static lv_color_t disp_draw_buf2[screenWidth * screenHeight / 10];
static lv_disp_drv_t disp_drv;

int hour = 0, minute = 0, second = 0;
unsigned long lastSecondUpdate = 0;

// Display flushing function for LVGL
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  tft.pushImageDMA(area->x1, area->y1, w, h, (lgfx::rgb565_t*)&color_p->full);
  lv_disp_flush_ready(disp);
}

void setup() {
  Serial.begin(115200);
  Serial.println("LVGL Hello World");

  tft.begin();
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  delay(200);
  
  lv_init();
  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf1, disp_draw_buf2, screenWidth * screenHeight / 10);
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.full_refresh = 0;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  ui_init();
  ui_Screen1_screen_init();
}

void loop() {
  lv_timer_handler();

  unsigned long currentMillis = millis();
  if (currentMillis - lastSecondUpdate >= 1000) {
    lastSecondUpdate = currentMillis;
    second++;
    if (second >= 60) {
      second = 0;
      minute++;
      if (minute >= 60) {
        minute = 0;
        hour++;
        if (hour >= 24) {
          hour = 0;
        }
      }
    }
  }

  static unsigned long lastUpdate = 0;
  if (currentMillis - lastUpdate >= 250) {
    lastUpdate = currentMillis;
    char time_str[9];
    snprintf(time_str, sizeof(time_str), "%02d:%02d:%02d", hour, minute, second);
    lv_label_set_text(ui_ZEIT, time_str);
  }
}
