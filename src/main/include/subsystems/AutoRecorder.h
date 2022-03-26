// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "utilities/CSVInterface.h"
#include <memory>
#include <vector>

#include "utilities/RecordedTalonFX.h"
#include "utilities/RecordedSpark.h"
#include "utilities/RecordedSolenoid.h"

class AutoRecorder : public frc2::SubsystemBase {
 public:
  AutoRecorder();
    void StartRecording();
    void StopRecording();
    bool GetIsRecording();
    void Write(std::vector<std::string> data);
    void AddTalon(RecordedTalonFX** device);
    void AddSpark(RecordedSpark** device);
    void AddSolenoid(RecordedSolenoid** device);
    units::millisecond_t GetCurrentTime();
    units::millisecond_t GetStartTime();
    std::vector<size_t> GetNumberOfRecordedDevices();
    void Periodic() override;
    void StartPlayback();
    void StopPlayback();
    bool GetIsPlayingBack();

 private:
    void UpdatePlaybackData();
    void MapDevicesWithIDs();
    void RecordPeriodic();
    void ProcessReadDataChunk();
    void PlaybackPeriodic();
    bool IsPlaybackTooSlow();
    void CorrectPlaybackTooSlow();
    std::shared_ptr<CSVInterface> csvInterface;
    bool isRecording;
    bool isPlayingBack;
    units::millisecond_t startTime;
    std::string sequenceName;

    std::vector<RecordedTalonFX*> recordedTalons;
    std::vector<RecordedSpark*> recordedSparks;
    std::vector<RecordedSolenoid*> recordedSolenoids;

    //Mapping indexes of recorded devices in their respective arrays to their
    // CAN/PCM IDs gives faster runtime results when playing back a routine
    std::map<int, int> recordedTalonIDs = {};
    std::map<int, int> recordedSparkIDs = {};
    std::map<int, int> recordedSolenoidIDs = {};

    // Both used for playback to verify it is running at the correct speed
    units::millisecond_t playbackTime;
    units::millisecond_t recordTime;
};
