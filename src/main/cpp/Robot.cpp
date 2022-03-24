// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "RobotContainer.h"
#include <cameraserver/CameraServer.h>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include "subsystems/Climber.h"
#include "commands/autonomous/ShootThenCrossLine.h"
#include "commands/autonomous/DriveToDistance.h"
#include "commands/autonomous/DriveToDistanceIntake.h"
#include "commands/TurnToAngle.h"
#include "commands/autonomous/AutoTurnToAngle.h"
#include "commands/ArmDown.h"
#include "commands/ArmUp.h"

#include <frc/Timer.h>

void Robot::RobotInit() {
    //RobotContainer::climber->SetPivot(PivotState::Up);
    //RobotContainer::intake->SetArmState(ArmState::Down);
    RobotContainer::drivetrain->SetEncoderPositions(0, 0);
    RobotContainer::intake->ArmUp();
    //leftSide = RobotContainer::csvInterface->ReadTextFile("LeftTest");
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
  RobotContainer::fmsComms->DisplayMatchTime();
  //frc::SmartDashboard::PutNumber("distance: ", RobotContainer::ultrasonic->getDistance());
  //frc::SmartDashboard::PutString("Drive Speed", RobotContainer::fmsComms->GetAllianceString(RobotContainer::fmsComms->GetAlliance()));
  //RobotContainer::drivetrain->PrintEncoderValues();
  //printf("Please work %f: \n", leftSide[4]);
  
  }
/**
 * This function is called once each time the robot enters Disabled mode. You`
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {
    RobotContainer::intake->ArmUp();
    //RobotContainer::drivetrain->WriteLeftMotorPos("LeftTest");
    //RobotContainer::drivetrain->WriteRightMotorPos("RightTest");
}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
    //RobotContainer::climber->PivotDown();
    autoTurnToAngle.reset(new AutoTurnToAngle(60, true));
    autoTurnToAngle->Schedule();
    // autoCommandScheduler.reset(new AutoCommandScheduler({
    // //     //  new ShootThenCrossLine()
    // //      //new ShootThenCrossLine()
    // //     //new ArmDown(),
    // //new DriveToDistanceIntake(.2, -25, false),
    // new AutoTurnToAngle(60, true),
    // //     //new ArmUp(),
    // //     new DriveToDistanceIntake(-.3, 39, true),
    // //     new TurnToAngle(-60),
    // //     //new TurnToAngle(-300),
    // //     //*new DriveToDistanceIntake(.3, 48, true),
    // //     // new DriveToDistance(.3, -20),
    // //     //*new TurnToAngle(-105),
    // //     // //new ArmDown(),
    // //     //*new DriveToDistanceIntake(-.3, 40, true),
    // }));
}

void Robot::AutonomousPeriodic() {
    //autoCommandScheduler->RunSequential();
    //RobotContainer::drivetrain->Drive(.6, .3);
}

void Robot::TeleopInit() {
    RobotContainer::intake->ArmUp();
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
    //RobotContainer::drivetrain->RecordMotorPos();
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
