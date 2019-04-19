/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/WheelModule.h"
#include "RobotMap.h"

WheelModule::WheelModule(int anglePort, int speedPort, char id[2])
    : Subsystem("WheelModule") {
    this->anglePort = anglePort;
    this->speedPort = speedPort;
    strncpy(this->id, id, 2);

    speedMotor.ConfigPeakOutputForward(1);
    speedMotor.ConfigPeakOutputReverse(1);
    // speedMotor.SetInverted(speedInverted);
    angleMotor.ConfigSelectedFeedbackSensor(
        FeedbackDevice::CTRE_MagEncoder_Relative, 0, TIMEOUT);
    angleMotor.SetSensorPhase(false);
    angleMotor.ConfigAllowableClosedloopError(0, 0, TIMEOUT);
    angleMotor.Config_kP(0, aP, TIMEOUT);
    angleMotor.Config_kI(0, aI, TIMEOUT);
    angleMotor.Config_kD(0, aD, TIMEOUT);
    angleMotor.Config_kF(0, aF, TIMEOUT);
    angleMotor.Config_IntegralZone(0, aIZONE, TIMEOUT);
    angleMotor.ConfigMotionCruiseVelocity(aV, TIMEOUT);
    angleMotor.ConfigMotionAcceleration(aA, TIMEOUT);
    // angleMotor.SetInverted(angleInverted);
}

void WheelModule::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

double WheelModule::adjustAngle(double angle) {
    double target = 0;
    double current =
        round(angleMotor.GetSelectedSensorPosition(0) / COUNTPERDEG);
    double Rcurrent = 0;
    double dir = abs(current) % 360;
    if (current >= 180) {  // OLD: > and <
        if (dir > 180) {
            Rcurrent = dir - 360;
        } else {
            Rcurrent = dir;
        }
    } else if (current <= -180) {
        if (dir > 180) {
            Rcurrent = -1 * dir + 360;
        } else {
            Rcurrent = dir * -1;
        }
    } else {
        Rcurrent = current;
    }

    if (angle - Rcurrent <= 180 && angle - Rcurrent >= -180) {
        target = angle - Rcurrent + current;
    } else if (angle - Rcurrent >= 180) {  // OLD: >
        target = angle - Rcurrent - 360 + current;
    } else {
        target = angle - Rcurrent + 360 + current;
    }

    return target;
}

void WheelModule::drive(double speed, double angle) {
    angle = adjustAngle(angle);
    if (angle > lastAngle && angle - lastAngle > 90) {
        angle = angle - 180;
        speed = -speed;
    } else if (angle < lastAngle && lastAngle - angle > 90) {
        angle = angle + 180;
        speed = -speed;
    }
    lastAngle = angle;

    angle *= COUNTPERDEG;

    speedMotor.Set(ControlMode::PercentOutput, speed);
    angleMotor.Set(ControlMode::MotionMagic, angle);
}
