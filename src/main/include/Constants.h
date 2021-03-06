// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <units/length.h>
#include <units/math.h>
#include <cmath>

namespace Constants {
    namespace MotorIDs {
        const uint8_t leftPrimary = 1;
        const uint8_t rightPrimary = 2;
        const uint8_t leftFollower = 3;
        const uint8_t rightFollower = 4;

        const uint8_t intakeTop = 5;
        const uint8_t intakeBottom = 6;

        const uint8_t rightClimber = 7;
        const uint8_t leftClimber = 8;

        const uint8_t highShooter = 9;
    }

    enum DigitalIDs {
        bottomOptical = 0,
        middleOptical = 2,
        topOptical = 1
    };

    namespace PneumaticIDs {
        const uint8_t climber = 4;
        const uint8_t arm = 9;
    }

    const uint8_t driverController_id = 0;
    const uint8_t manipulatorController_id = 1;
    const uint8_t PCMCanBusID = 15;

    const double attaError = .01; //atta = AutoTurnToAngle

    const double targetRPM = 15000; 
    const double shooterError = 50;

    const double degreesToRadians = M_PI/180.0;
    const double XResetMultiplier = 0.996194698092;

    const double gearRatio = (62.0/9.0) * (30.0/18.0);
    const int cpr = 2048;

    const units::unit_t<units::length::inch> wheelDiameter = 6_in;
    const units::unit_t<units::length::inch> wheelCircum = wheelDiameter * M_PI;

    const double encoderPerInch = cpr * gearRatio / wheelCircum.value();

    //Analog Port for the Ultrasonic Sensor
    static constexpr int kUltrasonicPort = 0;
}