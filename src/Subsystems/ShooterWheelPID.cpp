// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ShooterWheelPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ShooterWheelPID::ShooterWheelPID() : PIDSubsystem("ShooterWheelPID", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController()->SetContinuous(true);
    LiveWindow::GetInstance()->AddActuator("ShooterWheelPID", "PIDSubsystem Controller", GetPIDController());
    GetPIDController()->SetOutputRange(-1.0, 1.0);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    shooter1 = RobotMap::shooterWheelPIDShooter1;
    noUseEncoder = RobotMap::shooterWheelPIDNoUseEncoder;
    speedCounter = RobotMap::shooterWheelPIDSpeedCounter;
    shooter2 = RobotMap::shooterWheelPIDShooter2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    speedCounter->SetMaxPeriod(28262826);
    speedCounter->SetUpdateWhenEmpty(true); //??? what does this do
    speedCounter->Reset();

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
    StopWheel();
    m_buttonWheelSpeed = 0;
}

double ShooterWheelPID::ReturnPIDInput() {

	float value = speedCounter->GetPeriod();
	return 60/value;

    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return noUseEncoder->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void ShooterWheelPID::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    shooter1->PIDWrite(output);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    shooter2->PIDWrite(output);
}

void ShooterWheelPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ShooterWheelPID::StartWheel(){
	Enable();
}

void ShooterWheelPID::StopWheel(){
	Disable();
}

void ShooterWheelPID::SetSpeed(double speed){
	StopWheel();
	GetPIDController()->SetSetpoint(speed);
	StartWheel();
}

double ShooterWheelPID::GetSpeed(){
	return GetPIDController()->GetSetpoint();
}

void ShooterWheelPID::IncreaseWheelOutput_5()
{
	StopWheel();
	m_buttonWheelSpeed += 0.05;
	if(m_buttonWheelSpeed > 1.0)
	{
		m_buttonWheelSpeed = 1.0;
	}
	shooter1.get()->Set(m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::DecreaseWheelOutput_5()
{
	StopWheel();
	m_buttonWheelSpeed -= 0.05;
	if(m_buttonWheelSpeed < -1.0)
	{
		m_buttonWheelSpeed = -1.0;
	}
	shooter1.get()->Set(m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::IncreaseWheelOutput_1()
{
	StopWheel();
	m_buttonWheelSpeed += 0.01;
	if(m_buttonWheelSpeed > 1.0)
	{
		m_buttonWheelSpeed = 1.0;
	}
	shooter1.get()->Set(m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::DecreaseWheelOutput_1()
{
	StopWheel();
	m_buttonWheelSpeed += 0.05;
	if(m_buttonWheelSpeed < -1.0)
	{
		m_buttonWheelSpeed = -1.0;
	}
	shooter1.get()->Set(m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::KillWheels(){
	shooter1.get()->Set(0);
	shooter2.get()->Set(0);
}
