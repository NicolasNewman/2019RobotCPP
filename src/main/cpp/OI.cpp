/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "RobotMap.h"

OI::OI() {
    // Process operator interface input here.
}

double OI::getX() {
    double x = driveStick.GetX();
    return abs(x) > DEADZONE_XY ? x : 0;
}

double OI::getY() {
    double y = driveStick.GetY();
    return abs(y) > DEADZONE_XY ? y : 0;
}

double OI::getZ() {
    double z = driveStick.GetZ();
    return abs(z) > DEADZONE_Z ? z : 0;
}
