// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ARM_SENSORS_TRIPPED_H
#define ARM_SENSORS_TRIPPED_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "../Subsystems/ArmPID.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ArmSensorsTripped: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	ArmSensorsTripped();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	bool AreArmSensorsTripped();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
};

#endif