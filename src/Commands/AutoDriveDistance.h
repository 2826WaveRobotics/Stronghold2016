#ifndef AUTO_DRIVE_DISTANCE_H
#define AUTO_DRIVE_DISTANCE_H

#include "../WaveConstants.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class AutoDriveDistance: public Command
{
public:
	AutoDriveDistance(double maxDistance, double power, float heading, bool useGlobalDistance = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_distance;
	double m_power;
	float m_heading;
	double m_distanceTraveled;
	double m_maxPower;
	bool m_useGlobalDistance;
};

#endif
