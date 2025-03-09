#include "USSensor.h"
#include "Arduino.h"

/*USSensor::USSensor(int epin, int tpin) {*/
/*  this->echo_pin = epin;*/
/*  this->trig_pin = tpin;*/
/*  init();*/
/*}*/
int USSensor::echo_pin;
int USSensor::trig_pin;
float USSensor::duration;

void USSensor::init(int epin, int tpin) {
  echo_pin = epin;
  trig_pin = tpin;

  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
}

void USSensor::begin() {

  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
}

int USSensor::getDistance() { return (duration * .0343) / 2; }
