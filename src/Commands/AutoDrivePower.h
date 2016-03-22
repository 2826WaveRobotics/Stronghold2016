#ifndef AUTO_DRIVE_POWER_H
#define AUTO_DRIVE_POWER_H

#include "../WaveConstants.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class AutoDrivePower: public Command
{
public:
	AutoDrivePower(double power, float heading, bool lookForDefenseCrossed, bool lookForLowBar, bool timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	Timer m_timer;

private:
	double m_power;
	float m_heading;
	bool m_lookForDefenseCrossed;
	bool m_lookForLowBar;
	bool m_timeout;
	bool m_periodPassed;


};

#endif
