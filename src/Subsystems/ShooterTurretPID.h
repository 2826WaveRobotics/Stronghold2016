// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SHOOTERTURRETPID_H
#define SHOOTERTURRETPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

enum TurretState {
	Turret_Straight,
	Turret_Angled
};
/**
 *
 *
 * @author ExampleAuthor
 */
class ShooterTurretPID: public PIDSubsystem {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ShooterTurretPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void SetTurretPosition(double position);
	void SetTurretPosition(bool position);
	void SetTurretCylinder(TurretState state);

	double GetTurretPosition();
private:
	std::shared_ptr<Solenoid> turretCylinder;
	std::shared_ptr<CANTalon> turretMotor;
	std::shared_ptr<AnalogInput> turretAngle;
	std::shared_ptr<DigitalInput> turretPosition1;
	std::shared_ptr<DigitalInput> turretPosition2;
	std::shared_ptr<DigitalInput> turretPosition3;
	double m_TurretPositionAngle;
};
#endif
