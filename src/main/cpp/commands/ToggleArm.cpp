// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ToggleArm.h"
#include "RobotContainer.h"

// Called when the command is initially scheduled.
void ToggleArm::Initialize() {
    if (RobotContainer::intake->GetPivot() == Intake::ArmState::Up) {
        RobotContainer::intake->ArmDown();
    } 
    else if (RobotContainer::intake->GetPivot() == Intake::ArmState::Down) {
        RobotContainer::intake->ArmUp();
    }
}

// Returns true when the command should end.
bool ToggleArm::IsFinished() {
  return true;
}
