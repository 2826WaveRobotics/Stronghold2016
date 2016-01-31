#include "AutoCurve.h"
#include "../Robot.h"

AutoCurve::AutoCurve(double angle)
{
	Requires(Robot::drivePID.get());
	m_angle = angle;
}

void AutoCurve::Initialize()
{
	Robot::drivePID->ResetEncoders();
	SetTimeout(5);
	Robot::drivePID->SetDirection(m_angle);
}

void AutoCurve::Execute()
{
//	std::cout << "Distance Left: " << fabs(Robot::drivePID->GetLeftDistanceTraveled()) << "\tRight: "
//			<< fabs(Robot::drivePID->GetRightDistanceTraveled()) << std::endl;

	//Robot::drivePID->Turn(0);
	double correction = Robot::drivePID->GetPIDOutput();
	double correctedLeftPower =  0 + correction;
	double correctedRightPower = 0 - correction;
	double limit = .6; // [swapping wheels] = 1;
	if(correctedLeftPower > limit){
		correctedLeftPower = limit;
	}
	else if(correctedRightPower < -limit){
		correctedLeftPower = -limit;
	}
	if(correctedRightPower > limit){
		correctedRightPower = limit;
	}
	else if(correctedRightPower < -limit){
		correctedRightPower = -limit;
	}
	Robot::drivePID->SetSidePower(correctedLeftPower, correctedRightPower);
	double degreesOff = fabs(Robot::drivePID->GetSetpoint() - Robot::drivePID->GetYaw());
	std::cout << "Correction: " << correction << "\tLeft: " <<
			correctedLeftPower << "\tRight: " << correctedRightPower << "\tYaw: "
			<< Robot::drivePID->GetYaw() << "\tSetpoint: " << Robot::drivePID->GetSetpoint() <<
			"\tOff By: " << degreesOff << std::endl;

}

bool AutoCurve::IsFinished()
{
	double facing = Robot::drivePID->GetYaw();
	std::cout << "We are finished turning with Yaw: " << facing << std::endl;
	if(facing > m_angle - 15 && facing < m_angle + 15){
		Robot::drivePID->SetSidePower(-1,1); // full brake for a fraction of a second
		return true;
	}
	else{
		return false;
	}
}

void AutoCurve::End()
{
//	Robot::drivePID->EnableAutoDrive(true);
	Robot::drivePID->SetSidePower(0,0); // stop the wheels
}

void AutoCurve::Interrupted()
{
	End();
}
