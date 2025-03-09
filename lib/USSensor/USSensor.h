#ifndef USSENSOR_H
#define USSENSOR_H

#include <Arduino.h>

class USSensor {
public:
  static float duration, distance;

  static void init(int epin, int tpin);
  static void begin();
  static int getDistance();

private:
  static int echo_pin, trig_pin;
};

#endif // !USSENSOR_H
