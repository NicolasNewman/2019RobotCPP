/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "subsystems/WheelModule.h"
#include "AHRS.h"

class Swerve : public frc::Subsystem {
 private:
    AHRS gyro{SPI::Port::kMXP};
    WheelModule *fl, *fr, *bl, *br;
 public:
  Swerve(WheelModule &fl, WheelModule &fr, WheelModule &bl, WheelModule &br);
  void InitDefaultCommand() override;
  double getGyro();
  void calculateVectors(double x, double y, double z);
};
