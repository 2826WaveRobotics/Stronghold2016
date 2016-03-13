// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Hood.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Hood::Hood() : Subsystem("Hood") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    shortCylinder = RobotMap::hoodShortCylinder;
    longCylinder = RobotMap::hoodLongCylinder;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    m_HoodPosition = Hood_Medium;
    lockingCylinder = RobotMap::hoodLockingCylinder;


}

void Hood::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Hood::setHoodPosition(HoodPosition newPosition){
	bool shortCylinderState;
	bool longCylinderState;

	switch(newPosition){
		case Hood_Stow: //default, all the way down
		default:
			shortCylinderState = false;
			longCylinderState = true;
			break;
		case Hood_Low:// pretty sure this is the one we NEVER want
			shortCylinderState = true;
			longCylinderState = true;
			break;
		case Hood_Medium:
			shortCylinderState = false;
		    longCylinderState = false;
		    break;
		case Hood_High:
			shortCylinderState = true;
			longCylinderState = false;
			break;
	}

	longCylinder.get()->Set(longCylinderState);
	shortCylinder.get()->Set(shortCylinderState);
	m_HoodPosition = newPosition;
}

HoodPosition Hood::GetHoodPosition()
{
	return m_HoodPosition;
}

void Hood::setLockPin() {
	lockingCylinder.get()->Set(true);
	}

void Hood::unlockPin(){
	lockingCylinder.get()->Set(false);

}
