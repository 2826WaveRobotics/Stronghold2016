#ifndef AUTO_DRIVE_POWER_H
#define AUTO_DRIVE_POWER_H

#include "../WaveConstants.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class AutoDrivePower: public Command
{
public:
	AutoDrivePower(double power, float heading);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_power;
	float m_heading;
};

#endif
