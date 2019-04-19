/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"

class WheelModule : public frc::Subsystem {
 private:
 int anglePort;
 int speedPort;
 int lastAngle;
 char id[2];
  TalonSRX speedMotor{speedPort};
  TalonSRX angleMotor{anglePort};
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  WheelModule(int anglePort, int speedPort, char id[]);
  void InitDefaultCommand() override;

  void drive(double speed, double angle);
  double adjustAngle(double angle);
};
