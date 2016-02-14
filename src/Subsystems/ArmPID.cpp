// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ArmPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

namespace
{
	const double c_sensorVoltRange = 4.0; //0.5 - 4.5
	const double c_sensorAngleRange = 180.0;
	const double c_ArmAngleDifference = 0; // positive if angle is above horizontal
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ArmPID::ArmPID() : PIDSubsystem("ArmPID", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController()->SetContinuous(false);
    LiveWindow::GetInstance()->AddActuator("ArmPID", "PIDSubsystem Controller", GetPIDController());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    armMotorRight = RobotMap::armPIDArmMotorRight;
    armMotorLeft = RobotMap::armPIDArmMotorLeft;
    lowBarProx1 = RobotMap::armPIDLowBarProx1;
    lowBarProx2 = RobotMap::armPIDLowBarProx2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    armAngle = RobotMap::armPIDArmAngle;

    // (2pi * 41.126 inch) / (256 pulse/rev * 13.0909)    Arm Radius = 41.126, Gear ratio = 13.0909:1
    //armPosition.get()->SetDistancePerPulse(.077105);

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
}

double ArmPID::ReturnPIDInput() {


    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return armAngle->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void ArmPID::SetArmAngle(float angle){
	GetPIDController()->Disable();
	GetPIDController()->SetSetpoint(convertAngleToVolts(angle));
	GetPIDController()->Enable();
}


float ArmPID::GetArmAngle(){
	return convertVoltsToAngle(armAngle.get()->GetVoltage());
}

double ArmPID::convertAngleToVolts(double angle)
{
	return (((c_sensorVoltRange/c_sensorAngleRange)*(angle + c_ArmAngleDifference))+.5);
}

double ArmPID::convertVoltsToAngle(double volts)
{
	return (((c_sensorAngleRange/c_sensorVoltRange)*(volts-.5))) - c_ArmAngleDifference;
}

void ArmPID::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    armMotorRight->PIDWrite(output);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT

    armMotorLeft->PIDWrite(-output);
}

void ArmPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
