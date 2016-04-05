#include "LastDitchDrive.h"
#include "../Robot.h"
#include <iostream>

LastDitchDrive::LastDitchDrive(double power, float heading, double timeout){
	std::cout << "LastDitchDrive construct - start" << std::endl;
	m_power = power;
	m_heading = heading;
	m_timeout = timeout;

	m_15secondSafety = false;
	std::cout << "   LastDitchDrive construct - end" << std::endl;
}

void LastDitchDrive::Initialize()
{
	m_timer.Reset();
	m_timer.Start();
	Robot::drivePID->SetDirection(m_heading); //sets up the PID for moving straight
}

void LastDitchDrive::Execute()
{
}

bool LastDitchDrive::IsFinished()
{
	if(!m_15secondSafety && m_timer.HasPeriodPassed(m_timeout))
	{
		Robot::drivePID->DriveStraight(m_power); //sets the correction based on degrees off the angle
		m_15secondSafety = true;
		m_timer.Reset();
		m_timer.Start();
	}
	else if(m_15secondSafety && m_timer.HasPeriodPassed(15 - m_timeout- .25))
	{
		return true;
	}


	return false;
} // don't know when we started getting this weird error

void LastDitchDrive::End()
{
	Robot::drivePID->SetSidePower(0,0); // stop moving
}

void LastDitchDrive::Interrupted()
{
	End();
}
