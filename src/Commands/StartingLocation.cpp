// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "StartingLocation.h"
#include "../WaveConstants.h"
#include "../AutonomousConstants.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

StartingLocation::StartingLocation(int Location): Command() {
    m_Location = Location;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void StartingLocation::Initialize() {
	AutonomousConstants autoConst;
	autoConst.SetLocation(m_Location);

//	double shootAngle;
//	double distanceToTravel;
//	switch(g_startingLocation)
//	{
//		case 1:
//		default:
//			distanceToTravel = c_courtyard1;
//			shootAngle = c_shootAngle1;
//			break;
//
//		case 2:
//			distanceToTravel = c_courtyard2;
//			shootAngle = c_shootAngle2;
//			break;
//
//		case 3:
//			distanceToTravel = c_courtyard3;
//			shootAngle = c_shootAngle3;
//			break;
//
//		case 4:
//			distanceToTravel = c_courtyard4;
//			shootAngle = c_shootAngle4;
//			break;
//
//		case 5:
//			distanceToTravel = c_courtyard5;
//			shootAngle = c_shootAngle5;
//			break;
//	}
//
//	g_courtyardDistance = distanceToTravel;
//	g_shootAngle = shootAngle;
}

// Called repeatedly when this Command is scheduled to run
void StartingLocation::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool StartingLocation::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void StartingLocation::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartingLocation::Interrupted() {

}
