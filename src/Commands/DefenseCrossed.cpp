// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DefenseCrossed.h"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DefenseCrossed::DefenseCrossed(double TimeDelay): Command() {
    m_TimeDelay = TimeDelay;

        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DefenseCrossed::Initialize() {
//	ZeroPitch = RobotMap::m_gyro.get()->GetPitch();
//	ZeroRoll = RobotMap::m_gyro.get()->GetRoll();
	m_timer.Reset();
	m_timer.Start();
	m_periodPassed = false;
	Robot::drivePID.get()->ResetPitchAndRoll();
//	m_lastTime = m_timer.Get();
	std::cout << "Initialize Defense Crossed" <<std::endl;

	Robot::drivePID.get()->SetDefenseCrossed(false);
}

// Called repeatedly when this Command is scheduled to run
void DefenseCrossed::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DefenseCrossed::IsFinished() {

	//std::cout<< "Starting Defense Crossed: Is Finished" <<std::cout;

	//double elapsedTime = m_timer.Get() - m_lastTime;

	float CurrentPitch = Robot::drivePID.get()->GetPitch();
	float CurrentRoll = Robot::drivePID.get()->GetRoll();

	bool IsPitchFlat = fabs (CurrentPitch) < 3.0;
	bool IsRollFlat = fabs (CurrentRoll) < 1.0;

	if(!m_periodPassed)
	{
		m_periodPassed = m_timer.HasPeriodPassed(m_TimeDelay);
	}

	std::cout<< "Pitch: " << CurrentPitch <<" Roll: " << CurrentRoll << " IsPitchFlat: " << IsPitchFlat <<
			" IsRollFlat: " << IsRollFlat << " Has Period Passed? " << m_periodPassed <<  std::endl;


	if (/*elapsedTime>m_initialTimeDelay*/ m_periodPassed && IsPitchFlat && IsRollFlat)
	{
		std::cout<<"Defense Crossed!!"<<std::endl;
		Robot::drivePID.get()->SetDefenseCrossed(true);
		return true;
	}

	else
	{
		return false;
	}

}

// Called once after isFinished returns true
void DefenseCrossed::End() {
	m_timer.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefenseCrossed::Interrupted() {

}
