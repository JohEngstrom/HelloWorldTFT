// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

ui_ZEIT = lv_label_create(lv_scr_act());  // Create label on active screen
    lv_obj_set_width(ui_ZEIT, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ZEIT, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ZEIT, 0);
    lv_obj_set_y(ui_ZEIT, 0);
    lv_obj_set_align(ui_ZEIT, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ZEIT, "13:02:30");
    lv_obj_set_style_text_font(ui_ZEIT, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
}
