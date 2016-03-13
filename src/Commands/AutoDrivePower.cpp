#include "AutoDrivePower.h"
#include "../Robot.h"
#include <iostream>

AutoDrivePower::AutoDrivePower(double power, float heading, bool lookForDefenseCrossed, bool lookForLowBar){
	Requires(Robot::drivePID.get());
	std::cout << "AutoDrivePower construct - start" << std::endl;
	m_power = power;
	m_heading = heading;
	m_lookForDefenseCrossed = lookForDefenseCrossed;
	m_lookForLowBar = lookForLowBar;
	std::cout << "   AutoDrivePower construct - end" << std::endl;
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
	bool defenseCrossed = true;

	if(m_lookForDefenseCrossed)
	{
		defenseCrossed = Robot::drivePID.get()->GetDefenseCrossed();
	}

	if((m_power == 0) || (defenseCrossed && m_lookForDefenseCrossed)){
		std::cout<<"AutoDrivePower is finished!!!!"<<std::endl;
		return true;
	}

	else if(Robot::armPID.get()->AreLowBarSensorsTripped() && m_lookForLowBar){
		return true;
	}
	else {
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
