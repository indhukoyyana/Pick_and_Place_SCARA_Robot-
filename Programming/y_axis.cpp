#include <Arduino.h>
#include <AccelStepper.h>
#include "y_axis.h"

#define JOINT2_STEP_PIN 3
#define JOINT2_DIR_PIN  6

AccelStepper joint2(AccelStepper::DRIVER,
                    JOINT2_STEP_PIN,
                    JOINT2_DIR_PIN);

void yAxisBegin() {
  joint2.setMaxSpeed(1000);
  joint2.setAcceleration(500);
}

void serviceYAxis() {
  joint2.run();
}

void setJoint2Target(long steps) {
  joint2.moveTo(steps);
}

void serviceJoint2() {
  joint2.run();
}

long joint2DistanceToGo() {
  return joint2.distanceToGo();
}

long getJoint2CurrentSteps() {
  return joint2.currentPosition();
}

void getJointAngles(float &theta1, float &theta2) {
  const float STEPS_PER_REV = 3200.0;

  theta1 = (getJoint1CurrentSteps() / STEPS_PER_REV) * 360.0;
  theta2 = (getJoint2CurrentSteps() / STEPS_PER_REV) * 360.0;
}

extern long getJoint1CurrentSteps();
