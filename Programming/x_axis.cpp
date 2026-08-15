#include <Arduino.h>
#include <AccelStepper.h>
#include "x_axis.h"
#include "y_axis.h"
#include "robot_kinematics.h"

#define JOINT1_STEP_PIN 2
#define JOINT1_DIR_PIN  5

AccelStepper joint1(AccelStepper::DRIVER,
                    JOINT1_STEP_PIN,
                    JOINT1_DIR_PIN);

void xAxisBegin() {
  joint1.setMaxSpeed(1000);
  joint1.setAcceleration(500);
}

void serviceXAxis() {
  joint1.run();
}

void moveX(float x_mm) {
  float currentX, currentY;
  getCurrentCartesian(currentX, currentY);
  moveCartesian(x_mm, currentY);
}

void moveCartesian(float x_mm, float y_mm) {
  float theta1, theta2;

  if (!inverseKinematics(x_mm, y_mm, theta1, theta2)) {
    Serial.println("X/Y position is outside SCARA workspace.");
    return;
  }

  joint1.moveTo(angleToSteps(theta1));
  setJoint2Target(angleToSteps(theta2));

  while (joint1.distanceToGo() != 0 || joint2DistanceToGo() != 0) {
    joint1.run();
    serviceJoint2();
  }

  Serial.println("Cartesian X/Y position reached.");
}

long angleToSteps(float angleDeg) {
  const float STEPS_PER_REV = 3200.0; // 200 full steps x 16 microsteps
  return (long)((angleDeg / 360.0) * STEPS_PER_REV);
}

long getJoint1CurrentSteps() {
  return joint1.currentPosition();
}
