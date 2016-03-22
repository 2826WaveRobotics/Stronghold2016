#include "AutoDrivePower.h"
#include "../Robot.h"
#include <iostream>

AutoDrivePower::AutoDrivePower(double power, float heading, bool lookForDefenseCrossed, bool lookForLowBar, bool timeout){
	Requires(Robot::drivePID.get());
	std::cout << "AutoDrivePower construct - start" << std::endl;
	m_power = power;
	m_heading = heading;
	m_lookForDefenseCrossed = lookForDefenseCrossed;
	m_lookForLowBar = lookForLowBar;
	m_timeout = timeout;
	std::cout << "   AutoDrivePower construct - end" << std::endl;
}

void AutoDrivePower::Initialize()
{
	m_timer.Reset();
	m_timer.Start();
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

	else if(m_timeout){
		if(m_timer.Get() > .25){
			return true;
		}
	}
	else if(Robot::armPID.get()->AreLowBarSensorsTripped() && m_lookForLowBar){
		return true;
	}
	else {
		return false;
	}
} // don't know when we started getting this weird error

void AutoDrivePower::End()
{
	Robot::drivePID->SetSidePower(0,0); // stop moving
}

void AutoDrivePower::Interrupted()
{
	End();
}
