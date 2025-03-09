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

void loop() {
  USSensor::begin();
  delay(1);

  int distance = USSensor::getDistance();

  if (distance > 100) {
    StopLight::green();
  } else if (distance > 70) {
    StopLight::yellow(0);
  } else if (distance > 10) {
    StopLight::yellow(distance * 2);
  } else if (distance > 0) {
    StopLight::red();
  } else {
    StopLight::reset();
  }
}
