#ifndef STOPLIGHT_H
#define STOPLIGHT_H

#include <Arduino.h>

class StopLight {
public:
  static void init(int r, int y, int g);
  static void reset();
  static void red();
  static void yellow(int flash_rate_ms);
  static void green();

private:
  static int r_pin, y_pin, g_pin;
};

#endif // !STOPLIGHT_H
