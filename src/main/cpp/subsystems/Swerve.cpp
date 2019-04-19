/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Swerve.h"
#include "RobotMap.h"

Swerve::Swerve(WheelModule &fl, WheelModule &fr, WheelModule &bl, WheelModule &br) : Subsystem("Swerve")
{
    this->fl = &fl;
    this->fr = &fr;
    this->bl = &bl;
    this->br = &br;
}

void Swerve::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
}

double Swerve::getGyro()
{
    return gyro.GetAngle();
}

void Swerve::calculateVectors(double x, double y, double z)
{
    double r = sqrt((L * L) + (W * W));
    y *= -1;

    double gyro = getGyro() * PI;
    double temp = y * cos(gyro) + x * sin(gyro);
    x = -y * sin(gyro) + x * cos(gyro);
    y = temp;

    double a = x - z * (L / r) + 0;
    double b = x + z * (L / r);
    double c = y - z * (W / r) + 0;
    double d = y + z * (W / r);

    double brSpeed = sqrt((a * a) + (c * c));
    double blSpeed = sqrt((a * a) + (d * d));
    double frSpeed = sqrt((b * b) + (c * c));
    double flSpeed = sqrt((b * b) + (d * d));

    double max = brSpeed;
    if (brSpeed > max)
    {
        max = brSpeed;
    }
    if (blSpeed > max)
    {
        max = blSpeed;
    }
    if (frSpeed > max)
    {
        max = frSpeed;
    }
    if (flSpeed > max)
    {
        max = flSpeed;
    }

    if (max > 1)
    {
        brSpeed /= max;
        blSpeed /= max;
        frSpeed /= max;
        flSpeed /= max;
    }

    double brAngle = (atan2(a, c) * 180 / PI);
    double blAngle = (atan2(a, d) * 180 / PI);
    double frAngle = (atan2(b, c) * 180 / PI);
    double flAngle = (atan2(b, d) * 180 / PI);

    br->drive(brSpeed, brAngle);
    bl->drive(blSpeed, blAngle);
    fr->drive(frSpeed, frAngle);
    fl->drive(flSpeed, flAngle);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
