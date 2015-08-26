/*
 * main.c
 * Sets up a Window and BitmapLayer, then loads and displays a PNG as a GBitmap
 */

#include <pebble.h>

static Window *s_main_window;
static GBitmap *s_bitmap;
// static GBitmap *s_batt_000;
// static GBitmap *s_batt_010;
// static GBitmap *s_batt_020;
// static GBitmap *s_batt_030;
// static GBitmap *s_batt_040;
// static GBitmap *s_batt_050;
// static GBitmap *s_batt_060;
// static GBitmap *s_batt_070;
// static GBitmap *s_batt_080;
// static GBitmap *s_batt_090;
// static GBitmap *s_batt_100;
static BitmapLayer *s_bitmap_layer;
// // static BitmapLayer *s_battery_layer;
// static TextLayer *s_time_layer;
// static TextLayer *s_shadow_layer_l;
// static TextLayer *s_shadow_layer_d;
// static TextLayer *s_shadow_layer_u;
// static TextLayer *s_shadow_layer_r;
// // static TextLayer *s_date_layer;
// static GFont s_stencil;
// static GFont s_silkscreen;

// Tick handler, to update every minute
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  static char s_time_buffer[16];
//   static char s_date_buffer[16];
  if (clock_is_24h_style()) {
    strftime(s_time_buffer, sizeof(s_time_buffer), "00%H%M", tick_time);
  } else {
    strftime(s_time_buffer, sizeof(s_time_buffer), "00%I%M", tick_time);
  }
  //TODO: support alternate date formats
//   strftime(s_date_buffer, sizeof(s_date_buffer), "%m.%d", tick_time);
  
//   text_layer_set_text(s_shadow_layer_l, s_time_buffer);
//   text_layer_set_text(s_shadow_layer_d, s_time_buffer);
//   text_layer_set_text(s_shadow_layer_u, s_time_buffer);
//   text_layer_set_text(s_shadow_layer_r, s_time_buffer);
  
//   text_layer_set_text(s_time_layer, s_time_buffer);
//   text_layer_set_text(s_date_layer, s_date_buffer);
}

// static void battery_handler(BatteryChargeState new_state) {
//   // Write to buffer and display
//   //static char s_battery_buffer[32];
//   //snprintf(s_battery_buffer, sizeof(s_battery_buffer), "Current battery level: %d/100", new_state.charge_percent);
//   //text_layer_set_text(s_output_layer, s_battery_buffer);
//   if (new_state.charge_percent == 100) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_100);
//   } else if (new_state.charge_percent == 90) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_090);
//   } else if (new_state.charge_percent == 80) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_080);
//   } else if (new_state.charge_percent == 70) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_070);
//   } else if (new_state.charge_percent == 60) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_060);
//   } else if (new_state.charge_percent == 50) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_050);
//   } else if (new_state.charge_percent == 40) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_040);
//   } else if (new_state.charge_percent == 30) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_030);
//   } else if (new_state.charge_percent == 20) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_020);
//   } else if (new_state.charge_percent == 10) {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_010);
//   } else {
//     bitmap_layer_set_bitmap(s_battery_layer, s_batt_000);
//   }
// }

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);

  s_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_XWING_BG);

  s_bitmap_layer = bitmap_layer_create(window_bounds);
  bitmap_layer_set_bitmap(s_bitmap_layer, s_bitmap);
  bitmap_layer_set_compositing_mode(s_bitmap_layer, GCompOpSet);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_bitmap_layer));
    
    // Battery layer
//   s_batt_000 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_000);
//   s_batt_010 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_010);
//   s_batt_020 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_020);
//   s_batt_030 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_030);
//   s_batt_040 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_040);
//   s_batt_050 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_050);
//   s_batt_060 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_060);
//   s_batt_070 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_070);
//   s_batt_080 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_080);
//   s_batt_090 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_090);
//   s_batt_100 = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BATT_100);
  
//   s_battery_layer = bitmap_layer_create(GRect(43, 156, 56, 5));
//   bitmap_layer_set_bitmap(s_battery_layer, s_batt_100);
//   bitmap_layer_set_compositing_mode(s_battery_layer, GCompOpSet);
//   layer_add_child(window_layer, bitmap_layer_get_layer(s_battery_layer));
    
  // Time shadow layers
//   s_shadow_layer_l = text_layer_create(GRect(0, 55, window_bounds.size.w, window_bounds.size.h));
//   text_layer_set_text_alignment(s_shadow_layer_l, GTextAlignmentCenter);
//   text_layer_set_background_color(s_shadow_layer_l, GColorClear);
//   layer_add_child(window_layer, text_layer_get_layer(s_shadow_layer_l));
    
//   s_shadow_layer_d = text_layer_create(GRect(1, 56, window_bounds.size.w, window_bounds.size.h));
//   text_layer_set_text_alignment(s_shadow_layer_d, GTextAlignmentCenter);
//   text_layer_set_background_color(s_shadow_layer_d, GColorClear);
//   layer_add_child(window_layer, text_layer_get_layer(s_shadow_layer_d));
    
//   s_shadow_layer_u = text_layer_create(GRect(1, 54, window_bounds.size.w, window_bounds.size.h));
//   text_layer_set_text_alignment(s_shadow_layer_u, GTextAlignmentCenter);
//   text_layer_set_background_color(s_shadow_layer_u, GColorClear);
//   layer_add_child(window_layer, text_layer_get_layer(s_shadow_layer_u));
    
//   s_shadow_layer_r = text_layer_create(GRect(2, 55, window_bounds.size.w, window_bounds.size.h));
//   text_layer_set_text_alignment(s_shadow_layer_r, GTextAlignmentCenter);
//   text_layer_set_background_color(s_shadow_layer_r, GColorClear);
//   layer_add_child(window_layer, text_layer_get_layer(s_shadow_layer_r));

//   // Time layer
//   s_time_layer = text_layer_create(GRect(1, 55, window_bounds.size.w, window_bounds.size.h));
//   text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
//   text_layer_set_background_color(s_time_layer, GColorClear);
//   layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
    
  // Date layer
//   s_date_layer = text_layer_create(GRect(121, 158, 23, 10));
//   text_layer_set_text_alignment(s_date_layer, GTextAlignmentLeft);
//   text_layer_set_background_color(s_date_layer, GColorBlack);
  //layer_add_child(window_layer, text_layer_get_layer(s_date_layer));

  // Load and set custom fonts
//   s_stencil = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_BEON_32));
//   s_silkscreen = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SILKSCREEN_8));
//   text_layer_set_font(s_time_layer, s_stencil);
//   text_layer_set_font(s_shadow_layer_l, s_stencil);
//   text_layer_set_font(s_shadow_layer_d, s_stencil);
//   text_layer_set_font(s_shadow_layer_u, s_stencil);
//   text_layer_set_font(s_shadow_layer_r, s_stencil);
//   text_layer_set_text_color(s_time_layer, GColorRajah);
//   text_layer_set_text_color(s_shadow_layer_l, GColorRed);
//   text_layer_set_text_color(s_shadow_layer_d, GColorRed);
//   text_layer_set_text_color(s_shadow_layer_u, GColorRed);
//   text_layer_set_text_color(s_shadow_layer_r, GColorRed);
    
//   text_layer_set_font(s_date_layer, s_silkscreen);
//   text_layer_set_text_color(s_date_layer, GColorWhite);
  
  // Get the current battery level
//   battery_handler(battery_state_service_peek());
}

static void main_window_unload(Window *window) {
  bitmap_layer_destroy(s_bitmap_layer);
//   text_layer_destroy(s_shadow_layer_l);
//   text_layer_destroy(s_shadow_layer_d);
//   text_layer_destroy(s_shadow_layer_u);
//   text_layer_destroy(s_shadow_layer_r);
//   text_layer_destroy(s_time_layer);
  //text_layer_destroy(s_date_layer);
  gbitmap_destroy(s_bitmap);
  // Unload custom fonts
//   fonts_unload_custom_font(s_stencil);
//   fonts_unload_custom_font(s_silkscreen);
}

static void init() {
  s_main_window = window_create();
#ifdef PBL_SDK_2
  window_set_fullscreen(s_main_window, true);
#endif
  window_set_background_color(s_main_window, COLOR_FALLBACK(GColorBlue, GColorBlack));
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  window_stack_push(s_main_window, true);
    
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  // Subscribe to the Battery State Service
//   battery_state_service_subscribe(battery_handler);
}

static void deinit() {
  window_destroy(s_main_window);
}

int main() {
  init();
  app_event_loop();
  deinit();
}