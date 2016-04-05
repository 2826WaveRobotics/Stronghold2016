#ifndef AOUTONOMOUSCONSTANTS_H
#define AOUTONOMOUSCONSTANTS_H





class AutonomousConstants
{
	public:
		AutonomousConstants(){};
		int GetLocation();
		void SetLocation(int newLocation);

		double GetDistanceToTravel();
		double GetShooterAngle();
		double GetHeading();

};



#endif
