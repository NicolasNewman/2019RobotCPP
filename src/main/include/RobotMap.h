/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

const double PI = atan(1.0)*4;
constexpr int W = 1;
constexpr int L = 1;
constexpr int TIMEOUT = 10;
constexpr int COUNTPERDEG = 0;

constexpr int FLANGLEPORT = 0, FLSPEEDPORT = 0;
constexpr int FRANGLEPORT = 0, FRSPEEDPORT = 0;
constexpr int BLANGLEPORT = 0, BLSPEEDPORT = 0;
constexpr int BRANGLEPORT = 0, BRSPEEDPORT = 0;

constexpr int aP = 0;
constexpr int aI = 0;
constexpr int aD = 0;
constexpr int aF = 0;
constexpr int aV = 0;
constexpr int aA = 0;
constexpr int aIZONE = 50;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
