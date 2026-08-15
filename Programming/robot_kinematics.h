#ifndef ROBOT_KINEMATICS_H
#define ROBOT_KINEMATICS_H

bool inverseKinematics(float x, float y, float &theta1, float &theta2);
long angleToSteps(float angleDeg);
void getCurrentCartesian(float &x, float &y);

#endif
