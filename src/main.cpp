#include "../lib/StopLight/StopLight.h"
#include "../lib/USSensor/USSensor.h"
#include <Arduino.h>

int r_pin = 4;
int g_pin = 15;
int y_pin = 2;

int echo_pin = 21;
int trig_pin = 19;

void setup() {
  Serial.begin(9600);
  StopLight::init(r_pin, y_pin, g_pin);
  USSensor::init(echo_pin, trig_pin);
}

/** TODO:
 * 1. Use distance abstraction (median) to prevent jumps
 *    Cache last n distances and use the abstraction of those to get rid of any
 *    outliers and prevent the lights from jumping
 *
 ** TODO:
 * 2. Make the `r_dist` configurable via button press or something so that users
 *    can configure the red light distance at runtime.
 */

void loop() {
  USSensor::begin();
  delay(1);

  int r_dist = 30; // red light threshold
  int distance = USSensor::getDistance();

  if (distance > r_dist * 4) {
    StopLight::green();
  } else if (distance > r_dist * 3) {
    StopLight::yellow(0);
  } else if (distance > r_dist * 2) {
    StopLight::yellow(distance * 2);
  } else {
    StopLight::red();
  }
}
