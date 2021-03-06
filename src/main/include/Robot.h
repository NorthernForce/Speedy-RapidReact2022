// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "RobotContainer.h"

#include "utilities/AutoCommandScheduler.h"
#include "commands/autonomous/AutoTurnToAngle.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.

  std::vector<double> leftSide;

  frc2::Command* m_autonomousCommand = nullptr;

  std::unique_ptr<AutoCommandScheduler> autoCommandScheduler;
  std::unique_ptr<AutoTurnToAngle> autoTurnToAngle;

  RobotContainer m_container;
};
