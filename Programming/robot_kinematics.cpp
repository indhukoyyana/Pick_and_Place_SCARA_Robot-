#include <Arduino.h>
#include <math.h>
#include "robot_kinematics.h"
#include "y_axis.h"

const float L1 = 150.0; // CHANGE to actual first arm-link length (mm)
const float L2 = 150.0; // CHANGE to actual second arm-link length (mm)

bool inverseKinematics(float x, float y, float &theta1, float &theta2) {
  float r2 = x*x + y*y;
  float c2 = (r2 - L1*L1 - L2*L2) / (2.0 * L1 * L2);

  if (c2 < -1.0 || c2 > 1.0) {
    return false;
  }

  float s2 = sqrt(1.0 - c2*c2);

  // Elbow-down solution.
  theta2 = atan2(s2, c2) * 180.0 / PI;

  float k1 = L1 + L2 * c2;
  float k2 = L2 * s2;

  theta1 = atan2(y, x) * 180.0 / PI
         - atan2(k2, k1) * 180.0 / PI;

  return true;
}

void getCurrentCartesian(float &x, float &y) {
  const float STEPS_PER_REV = 3200.0;

  float theta1 = (getJoint1CurrentSteps() / STEPS_PER_REV) * 360.0;
  float theta2 = (getJoint2CurrentSteps() / STEPS_PER_REV) * 360.0;

  float a = radians(theta1);
  float b = radians(theta1 + theta2);

  x = L1 * cos(a) + L2 * cos(b);
  y = L1 * sin(a) + L2 * sin(b);
}
