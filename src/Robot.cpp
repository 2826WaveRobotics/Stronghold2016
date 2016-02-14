// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<ArmPID> Robot::armPID;
std::shared_ptr<CompressorSubsystem> Robot::compressorSubsystem;
std::shared_ptr<DrivePID> Robot::drivePID;
std::shared_ptr<Hood> Robot::hood;
std::shared_ptr<GrappleClimb> Robot::grappleClimb;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<ShooterTurretPID> Robot::shooterTurretPID;
std::shared_ptr<ShooterWheelPID> Robot::shooterWheelPID;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    armPID.reset(new ArmPID());
    compressorSubsystem.reset(new CompressorSubsystem());
    drivePID.reset(new DrivePID());
    hood.reset(new Hood());
    grappleClimb.reset(new GrappleClimb());
    intake.reset(new Intake());
    shooterTurretPID.reset(new ShooterTurretPID());
    shooterWheelPID.reset(new ShooterWheelPID());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	m_defenseSelector = new SendableChooser;
	m_locationSelector = new SendableChooser;

	m_defenseSelector->AddObject("Low Bar", new AutoLowBar());
	m_defenseSelector->AddObject("Portcullis", new AutoPortcullis());
	m_defenseSelector->AddObject("Cheval De Frise", new AutoChevalDeFrise());
	m_defenseSelector->AddObject("Ramparts", new AutoRamparts());
	m_defenseSelector->AddObject("Moat", new AutoMoat());
	m_defenseSelector->AddObject("Sally Port", new AutoSallyPort());
	m_defenseSelector->AddObject("Drawbridge", new AutoDrawbridge());
	m_defenseSelector->AddObject("Rock Wall", new AutoRockWall());
	m_defenseSelector->AddObject("Rough Terrain", new AutoRoughTerrain());

	m_locationSelector->AddObject("1", new StartingLocation(1));
	m_locationSelector->AddObject("2", new StartingLocation(2));
	m_locationSelector->AddObject("3", new StartingLocation(3));
	m_locationSelector->AddObject("4", new StartingLocation(4));
	m_locationSelector->AddObject("5", new StartingLocation(5));
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){
	compressorSubsystem->StopCompressor();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	compressorSubsystem->StartCompressor();

	Command* locationCommand = (Command *) m_locationSelector->GetSelected();
	locationCommand->Start();

	autonomousCommand.reset((Command*)m_defenseSelector->GetSelected());

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	compressorSubsystem->StartCompressor();


	m_lastButtonY = false;
	m_lastButtonX = false;
	m_lastButtonA = false;
	m_lastButtonB = false;

	std::cout << "Teleop Init" << std::endl;

}


void Robot::TeleopPeriodic() {

	Scheduler::GetInstance()->Run();

	//Drive

	float leftDrive = oi.get()->getDriverJoystick()->GetRawAxis(1);
	float rightDrive = oi.get()->getDriverJoystick()->GetRawAxis(5);
	drivePID.get()->robotDrive41.get()->TankDrive(leftDrive, rightDrive);

//	std::cout<<"Robot Left Drive "<<leftDrive;
//	std::cout<<" Robot Right Drive "<<rightDrive;
//
//	std::cout<< " Right Encoder " << RobotMap::drivePIDDriveEncoderRight->Get();
//	std::cout<< " Left Encoder  " << RobotMap::drivePIDDriveEncoderLeft->Get();
//
//	std::cout<< " PID output  " << drivePID.get()->GetPIDOutput();
//	std::cout<< " Yaw  " << drivePID.get()->GetYaw();
//	std::cout<< " Pitch " << drivePID.get()->GetPitch();
//	std::cout<< " Roll " << drivePID.get()->GetRoll();

	//Arm

	//bool rightButton = oi->getDriverJoystick()->GetRawButton(6);
	float armMotorPower = oi.get()->getOperatorJoystick()->GetRawAxis(1);
	RobotMap::armPIDArmMotorRight->Set(armMotorPower/2);
	RobotMap::armPIDArmMotorLeft->Set(armMotorPower/2);

//	std::cout<<" Arm Position " << RobotMap::armPIDArmPosition->Get();
//	std::cout<<" Low Bar Prox 1 " << RobotMap::armPIDLowBarProx1->Get();
//	std::cout<<" Low Bar Prox 2 " << RobotMap::armPIDLowBarProx2->Get();
//
//	std::cout<<" Arm Motor Value "<< armMotorPower/2;
//
//	std::cout<<" Arm Angle  " << armPID.get()->GetArmAngle();

	//std::cout<<" PID encoder"<<;

	//Shooter Wheels -- I'm 95% sure there's a much better way to do this -- when pressed??? but I don't remember how
//	bool buttonY = oi->getDriverJoystick()->GetRawButton(4);
//	bool buttonX = oi->getDriverJoystick()->GetRawButton(3);
//	bool buttonB = oi->getDriverJoystick()->GetRawButton(2);
//	bool buttonA = oi->getDriverJoystick()->GetRawButton(1);
	float killButton = oi->getDriverJoystick()->GetRawAxis(3);
//
//	if((buttonY != m_lastButtonY) && buttonY) // for raising left motor value by 5%
//	{
//		shooterWheelValL = shooterWheelValL + .05;
//	}
//
//	m_lastButtonY = buttonY;
//
//	if((buttonX != m_lastButtonX) && buttonX) { //for lowering left motor value by 5%
//		shooterWheelValL = shooterWheelValL - .05;
//	}
//
//	m_lastButtonX = buttonX;
//
//	if ((buttonB != m_lastButtonB) && buttonB){
//		shooterWheelValL = shooterWheelValL + .001;
//	}
//
//	m_lastButtonB = buttonB;
//
//	if ((buttonA != m_lastButtonA) && buttonA){
//		shooterWheelValL = shooterWheelValL -.001;
//	}
//
//	m_lastButtonA = buttonA;
//
	if(killButton > .5){
		Robot::shooterWheelPID.get()->KillWheels();
	}
//
//	shooterWheelValL = shooterWheelValR;
//	RobotMap::shooterWheelPIDShooter1->Set(shooterWheelValL);
//	RobotMap::shooterWheelPIDShooter2->Set(shooterWheelValR);


	std::cout<<" Shooter Wheel Value "<<shooterWheelValL << std::endl;

//	float counterPID = RobotMap::shooterWheelPIDSpeedCounter ->Get();
//	std::cout<<"  Shooter Wheel Speed Counter  " << counterPID;
//	std::cout<<"  Shooter Wheel PID 2" << RobotMap::shooterWheelPIDShooter2->Get();	//???????? what is shooterwheelpid2 anyway
//
//	std::cout<<" Shooter Wheel PID " << shooterWheelPID.get()->GetSpeed();

	//Turret -- operator

	double turretPosition = oi.get()->getOperatorJoystick()->GetRawAxis(4);
	//shooterTurretPID.get()->SetTurretPosition(turretPosition/2);
	RobotMap::shooterTurretPIDTurretMotor.get()->Set(turretPosition/2);

	float turretMotor =  RobotMap::shooterTurretPIDTurretMotor->Get();
//	std::cout<<" Turret Motor"<<turretMotor/2;

//	RobotMap::shooterTurretPIDTurretPosition1; // again. what do these do
//	RobotMap::shooterTurretPIDTurretPosition2;
//	RobotMap::shooterTurretPIDTurretPosition3;

//	std::cout << " Turret Position " << shooterTurretPID.get() -> GetTurretPosition();

	//Intake Rollers

	bool mainIntakeVal = oi.get()->getOperatorJoystick()->GetRawButton(4);
	bool secondIntakeVal = oi.get()->getOperatorJoystick()->GetRawButton(1);

	if (mainIntakeVal == true){
		RobotMap::intakeMainIntake->Set(.9);
	}
	else{
		RobotMap::intakeMainIntake->Set(0);
	}

	if (secondIntakeVal == true){
		RobotMap::intakeSecondIntake->Set(.9);
	}
	else{
		RobotMap::intakeSecondIntake->Set(0);
	}

//	std::cout<<" Main Intake Value "<<RobotMap::intakeMainIntake->Get();
//	std::cout<<" Second Motor Intake Value"<<RobotMap::intakeSecondIntake->Get();
	std::cout << std::endl;

	//Pnumatic functions


	// RobotMap::hoodShortCylinder; //??
	 //RobotMap::hoodLongCylinder;//what does this do

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

