#ifndef Y_AXIS_H
#define Y_AXIS_H

void yAxisBegin();
void serviceYAxis();
void setJoint2Target(long steps);
void serviceJoint2();
long joint2DistanceToGo();
long getJoint2CurrentSteps();
void getJointAngles(float &theta1, float &theta2);
long getJoint1CurrentSteps();

#endif
