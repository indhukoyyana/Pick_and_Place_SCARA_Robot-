SCARA ROBOT - ARDUINO MEGA CONTROL FILES

Important:
1. This is a starting software structure, not a plug-and-play program.
2. X and Y are Cartesian coordinates. A SCARA robot normally does NOT have separate X and Y motors.
   X/Y movement is produced by coordinated Base (Joint 1) and Joint 2 movement.
3. Z has its own motor and lead screw.
4. Change all pin numbers to match your actual wiring.
5. Change L1 and L2 to your measured arm-link lengths.
6. Change STEPS_PER_REV according to your NEMA 17 motor and driver microstepping.
7. Change Z_STEPS_PER_MM according to your lead screw pitch and microstepping.
8. Verify motor direction and limit-switch wiring before connecting the mechanical load.
9. The limit-switch homing function is intentionally left as a safe placeholder until the
   actual switch locations and motor directions are confirmed.

Recommended Arduino libraries:
- AccelStepper

Suggested Arduino IDE project:
- main.cpp
- x_axis.cpp / x_axis.h
- y_axis.cpp / y_axis.h
- z_axis.cpp / z_axis.h
- robot_kinematics.cpp / robot_kinematics.h
- limits.cpp / limits.h
