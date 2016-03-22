// THis file is where we can store values that any file can read

#ifndef WAVECONSTANTS_H
#define WAVECONSTANTS_H

// StartingLocation command writes to this variable so that the Auto Mode sequence knows how far to drive and how much to turn
 //static int g_startingLocation;
 //static double g_courtyardDistance;
 //static double g_shootAngle;


 // Distance is in inches for how far we need to drive before stopping to shoot.
 const double c_courtyard1 = 50;
 const double c_courtyard2 = 50;
 const double c_courtyard3 = 50;
 const double c_courtyard4 = 50;
 const double c_courtyard5 = 50;

 const double c_shootAngle1 = 45;
 const double c_shootAngle2 = 30;
 const double c_shootAngle3 = 0;
 const double c_shootAngle4 = -30;
 const double c_shootAngle5 = -45;


 // available intake arm positions
 const double c_armIntakePosition = 10;
 const double c_armLowPosition = 5;
 const double c_armTravelPosition = 40;
 const double c_armHighPosition = 60;


const double wheelCircumference = 3.14159 * 6; // 6 = wheel diameter
const double ticksPerWheel = 1/(256*3*2.5); // 256 ticks per encoder * (3:1) * (5:2)




#endif
