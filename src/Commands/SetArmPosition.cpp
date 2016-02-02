// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SetArmPosition.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

SetArmPosition::SetArmPosition(double Angle): Command() {
    m_Angle = Angle;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void SetArmPosition::Initialize() {
	Robot::armPID.get()->SetArmAngle(m_Angle);
}

// Called repeatedly when this Command is scheduled to run
void SetArmPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetArmPosition::IsFinished() {
	float currentAngle = Robot::armPID.get()->GetArmAngle();
	if(fabs(currentAngle - m_Angle) < 1.0) //within 1.0 degrees
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void SetArmPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmPosition::Interrupted() {

}
