// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  void SetFollowers();
  void SetInvert();
  void ConfigureAllControllers();
  void ConfigureController(WPI_TalonFX& controller, bool isFollower=false);
  void Drive(double speed, double rotation);
  void DriveUsingSpeeds(double leftSpeed, double rightSpeed);
  bool DriveToDistance(double desiredDistance, double speed);
  std::pair<double, double> GetEncoderRotations();
  std::pair<units::inch_t, units::inch_t> GetInchesTravelled();
  double GetAvgEncoderRotations(std::pair<double, double>);
  void SetEncoderPositions(double lt, double rt);
  void PrintEncoderValues();
  void RecordMotorPos();
  void WriteLeftMotorPos(std::string fileName);
  void WriteRightMotorPos(std::string fileName);
  double GetLeftRPM();
  double GetRightRPM();
  bool IsTipping();
  void Periodic() override;

  std::vector<double> leftMotorPos;
  std::vector<double> rightMotorPos;

  static std::shared_ptr<WPI_TalonFX> leftPrimary;
  static std::shared_ptr<WPI_TalonFX> rightPrimary;
  static std::shared_ptr<frc::DifferentialDrive> robotDrive;
  
 private:
  std::shared_ptr<WPI_TalonFX> leftFollower;
  std::shared_ptr<WPI_TalonFX> rightFollower;
  const int rampRate = 0.2;
  units::degree_t armUpTipAngle = 12_deg;
  units::degree_t armDownTipAngle = 15_deg;
};
