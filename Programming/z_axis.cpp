#include <Arduino.h>
#include <AccelStepper.h>
#include "z_axis.h"

#define Z_STEP_PIN 4
#define Z_DIR_PIN  7

AccelStepper zMotor(AccelStepper::DRIVER,
                    Z_STEP_PIN,
                    Z_DIR_PIN);

// Example values. CHANGE after measuring your lead screw.
const float Z_STEPS_PER_MM = 80.0;

void zAxisBegin() {
  zMotor.setMaxSpeed(800);
  zMotor.setAcceleration(400);
}

void serviceZAxis() {
  zMotor.run();
}

void moveZ(float z_mm) {
  if (z_mm < 0) z_mm = 0;

  long target = (long)(z_mm * Z_STEPS_PER_MM);
  zMotor.moveTo(target);

  while (zMotor.distanceToGo() != 0) {
    zMotor.run();
  }

  Serial.print("Z position: ");
  Serial.print(z_mm);
  Serial.println(" mm");
}
