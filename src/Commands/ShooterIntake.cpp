// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ShooterIntake.h"
#include <iostream>


ShooterIntake::ShooterIntake(bool on): Command() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::intake.get());
	m_Secondaryintake = on;
}



// Called just before this Command runs the first time
void ShooterIntake::Initialize() {
	if(m_Secondaryintake){
		Robot::intake.get()->SetSecondaryOn();
	}
	else{
		Robot::intake.get()->SetSecondaryOff();
	}
}
// Called repeatedly when this Command is scheduled to run
void ShooterIntake::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterIntake::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShooterIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterIntake::Interrupted() {

}