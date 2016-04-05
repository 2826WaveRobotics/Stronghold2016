#ifndef LAST_DITCH_DRIVE_H
#define LAST_DITCH_DRIVE_H

#include "../WaveConstants.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class LastDitchDrive: public Command
{
public:
	LastDitchDrive(double power, float heading, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer m_timer;
	double m_power;
	float m_heading;
	double m_timeout;

	bool m_15secondSafety;

};

#endif
