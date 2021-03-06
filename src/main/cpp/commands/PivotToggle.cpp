// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/PivotToggle.h"
#include "RobotContainer.h"

// Called when the command is initially scheduled.
void PivotToggle::Initialize() {
    if(RobotContainer::climber->GetPivot() == PivotState::Up) {
        RobotContainer::climber->PivotDown();
    } 
    else if (RobotContainer::climber->GetPivot() == PivotState::Down) {
        RobotContainer::climber->PivotUp();
    }
}

// Returns true when the command should end.
bool PivotToggle::IsFinished() {
  return true;
}
