#include <Arduino.h>
#include "limits.h"
#include <AccelStepper.h>

#define BASE_LIMIT_PIN  9
#define JOINT_LIMIT_PIN 10
#define Z_LIMIT_PIN     11

void limitsBegin() {
  pinMode(BASE_LIMIT_PIN, INPUT_PULLUP);
  pinMode(JOINT_LIMIT_PIN, INPUT_PULLUP);
  pinMode(Z_LIMIT_PIN, INPUT_PULLUP);
}

bool baseLimitActive() {
  return digitalRead(BASE_LIMIT_PIN) == LOW;
}

bool jointLimitActive() {
  return digitalRead(JOINT_LIMIT_PIN) == LOW;
}

bool zLimitActive() {
  return digitalRead(Z_LIMIT_PIN) == LOW;
}

void homeAllAxes() {
  Serial.println("Homing routine must be matched to your actual mechanical directions.");
  Serial.println("Do NOT run a homing routine until motor directions and switch positions are verified.");
}
