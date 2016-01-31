#include "AutoDrivePower.h"
#include "../Robot.h"

AutoDrivePower::AutoDrivePower(double power, float heading){
	Requires(Robot::drivePID.get());
	std::cout << "AutoDrivePower: Construct" << std::endl;
	m_power = power;
	m_heading = heading;
}

void AutoDrivePower::Initialize()
{
	Robot::drivePID->ResetEncoders();
	//Robot::drivePID->SetPIDs(.055, 0, .08); // .035 //comp = .055
	Robot::drivePID->SetDirection(m_heading); //sets up the PID for moving straight
}

void AutoDrivePower::Execute()
{
	//double m_maxPower = Robot::drivePID->CheckPower(m_power, m_distance); // get the max power allowed to move (basically P)
	Robot::drivePID->DriveStraight(m_power); //sets the correction based on degrees off the angle
}

bool AutoDrivePower::IsFinished()
{
	if(m_power == 0){
		return true;
	}
	else{
		return false; // return false will allow the robot to drive at the given power until a new AutoDrivePower is called.
	}
}

void AutoDrivePower::End()
{
	Robot::drivePID->SetSidePower(0,0); // stop moving
}

void AutoDrivePower::Interrupted()
{
	End();
}
