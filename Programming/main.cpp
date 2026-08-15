#include <Arduino.h>
#include "x_axis.h"
#include "y_axis.h"
#include "z_axis.h"
#include "limits.h"

void setup() {
  Serial.begin(115200);

  xAxisBegin();
  yAxisBegin();
  zAxisBegin();
  limitsBegin();

  Serial.println("SCARA Arduino Mega Controller");
  Serial.println("Commands:");
  Serial.println("X100   -> move Cartesian X to 100 mm");
  Serial.println("Y100   -> move Cartesian Y to 100 mm");
  Serial.println("Z20    -> move Z to 20 mm");
  Serial.println("HOME   -> home all axes");
  Serial.println("PICK   -> move to example pick position");
  Serial.println("PLACE  -> move to example place position");
}

void loop() {
  serviceXAxis();
  serviceYAxis();
  serviceZAxis();

  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();

    if (cmd == "HOME") {
      homeAllAxes();
    } 
    else if (cmd == "PICK") {
      moveCartesian(120.0, 50.0);
      moveZ(20.0);
    }
    else if (cmd == "PLACE") {
      moveCartesian(180.0, 100.0);
      moveZ(20.0);
    }
    else if (cmd.startsWith("X")) {
      float x = cmd.substring(1).toFloat();
      moveX(x);
    }
    else if (cmd.startsWith("Y")) {
      float y = cmd.substring(1).toFloat();
      moveY(y);
    }
    else if (cmd.startsWith("Z")) {
      float z = cmd.substring(1).toFloat();
      moveZ(z);
    }
  }
}
