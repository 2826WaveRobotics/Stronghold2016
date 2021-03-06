// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"





// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/ArmPID.h"
#include "Subsystems/CompressorSubsystem.h"
#include "Subsystems/DrivePID.h"
#include "Subsystems/GrappleClimb.h"
#include "Subsystems/Hood.h"
#include "Subsystems/Intake.h"
#include "Subsystems/ShooterTurretPID.h"
#include "Subsystems/ShooterWheelPID.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<ArmPID> armPID;
    static std::shared_ptr<CompressorSubsystem> compressorSubsystem;
    static std::shared_ptr<DrivePID> drivePID;
    static std::shared_ptr<Hood> hood;
    static std::shared_ptr<GrappleClimb> grappleClimb;
    static std::shared_ptr<Intake> intake;
    static std::shared_ptr<ShooterTurretPID> shooterTurretPID;
    static std::shared_ptr<ShooterWheelPID> shooterWheelPID;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();


private:

	Timer colorRunTimer;

	ArmLight color;

	float shooterWheelValR;
	float shooterWheelValL;

	bool m_lastButtonY;
	bool m_lastButtonX;
	bool m_lastButtonB;
	bool m_lastButtonA;

	bool m_armWasActive;

	SendableChooser *m_defenseSelector;
	SendableChooser *m_locationSelector;
	SendableChooser *m_allianceSelector;

	std::unique_ptr<Command> m_armAngleIntakeCommand;
	bool m_armAngleIntakeReset;
	std::unique_ptr<Command> m_triggerHoodStow;
	std::unique_ptr<Command> m_triggerHoodMedium;
	std::unique_ptr<Command> m_triggerHoodHigh;
	bool m_triggerHoodReset;

	std::unique_ptr<Command> m_redAlliance;
	std::unique_ptr<Command> m_blueAlliance;
};
#endif
