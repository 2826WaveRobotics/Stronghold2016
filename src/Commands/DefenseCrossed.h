// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DEFENSECROSSED_H
#define DEFENSECROSSED_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "time.h"


/**
 *
 *
 * @author ExampleAuthor
 */
class DefenseCrossed: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	DefenseCrossed(double TimeDelay);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	Timer m_timer;
	double m_lastTime;
	double m_initialTimeDelay;

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

    double m_TimeDelay;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	float ZeroPitch;
	float ZeroRoll;



};

#endif