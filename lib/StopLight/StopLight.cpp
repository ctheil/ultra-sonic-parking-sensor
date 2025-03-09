#include "StopLight.h"

/*StopLight::StopLight(int r, int y, int g) {*/
/*  this->r_pin = r;*/
/*  this->y_pin = y;*/
/*  this->g_pin = g;*/
/*  init();*/
/*}*/
// Define static members
int StopLight::r_pin;
int StopLight::y_pin;
int StopLight::g_pin;

void StopLight::init(int r, int y, int g) {
  r_pin = r;
  y_pin = y;
  g_pin = g;

  pinMode(r_pin, OUTPUT);
  pinMode(y_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);

  // turn on lights for debug
  delay(1000);
  digitalWrite(r_pin, HIGH);
  delay(200);
  digitalWrite(y_pin, HIGH);
  delay(200);
  digitalWrite(g_pin, HIGH);
  delay(1000);
  reset();
}
void StopLight::reset() {
  digitalWrite(r_pin, LOW);
  digitalWrite(y_pin, LOW);
  digitalWrite(g_pin, LOW);
}
void StopLight::red() {
  reset();
  digitalWrite(r_pin, HIGH);
}
void StopLight::yellow(int flash_rate_ms) {
  reset();
  digitalWrite(y_pin, HIGH);
  if (flash_rate_ms > 0) {
    digitalWrite(r_pin, HIGH);
    delay(flash_rate_ms);
    digitalWrite(r_pin, LOW);
    delay(flash_rate_ms);
  }
}
void StopLight::green() {
  reset();
  digitalWrite(g_pin, HIGH);
}
