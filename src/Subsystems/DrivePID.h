// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVEPID_H
#define DRIVEPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../AHRS.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DrivePID: public PIDSubsystem {
 public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Encoder> driveEncoder;
	std::shared_ptr<CANTalon> leftBack;
	std::shared_ptr<CANTalon> rightBack;
	std::shared_ptr<CANTalon> leftFront;
	std::shared_ptr<CANTalon> rightFront;
	std::shared_ptr<RobotDrive> robotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	std::shared_ptr<AHRS> gyro;

	DrivePID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();


	void ResetEncoders();
	double GetDistanceTraveled(); //Returns the distance traveled from the last encoder reset, based on wheel circumference
	void DriveStraight(double power); //Will drive at the given power at the current heading forever
	void SetSidePower(double left,double right); //Sets left drive motors to "left" and right drive motors to "right"
	double GetPIDOutput(); //Returns the motor correction needed to maintain the current heading
	void SetDirection(double heading); //Sets the PID to maintain the given heading
	double GetYaw();
	double GetPitch();
	double GetRoll();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
