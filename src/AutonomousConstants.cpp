
#include "AutonomousConstants.h"
#include "WaveConstants.h"


namespace
{
	static int g_startingLocation;
}



int AutonomousConstants::GetLocation()
{
	return g_startingLocation;
}

void AutonomousConstants::SetLocation(int newLocation)
{
	g_startingLocation = newLocation;
}

double AutonomousConstants::GetDistanceToTravel()
{
	switch(g_startingLocation)
	{
		case 1:
		default:
			return  c_courtyard1;
			break;

		case 2:
			return  c_courtyard2;
			break;

		case 3:
			return  c_courtyard3;
			break;

		case 4:
			return  c_courtyard4;
			break;

		case 5:
			return  c_courtyard5;
			break;
	}
}

double AutonomousConstants::GetShooterAngle()
{
	switch(g_startingLocation)
	{
		case 1:
		default:
			return c_shootAngle1;
			break;


		case 2:
			return c_shootAngle2;
			break;

		case 3:
			return c_shootAngle3;
			break;

		case 4:
			return c_shootAngle4;
			break;

		case 5:
			return c_shootAngle5;
			break;
	}
}

double AutonomousConstants::GetHeading(){
	switch(g_startingLocation){
		case 1:
		default:
			return c_location1;
			break;
		case 2:
			return c_location2;
			break;
		case 3:
			return c_location3;
			break;
		case 4:
			return c_location4;
			break;
		case 5:
			return c_location5;
			break;
	}
}
