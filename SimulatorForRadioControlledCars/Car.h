#pragma once

#include<string>
#include "Room.h"
using namespace std;

class Car
{
protected:
	string carType;
	int carDiameter;
	int movment;
	const int TireTurningAngle[3]= { 0,90,-90 };
	int heading;
	
public:
	enum DrivingCommands :char { F = 'F', B = 'B', R = 'R', L = 'L' };

	Car() {
		carType = "Monster Truck";
		carDiameter = 1;
		
	}
	
	string Get_TypeOfCar() { return carType; }
	int get_carDiameter() { return carDiameter; }

	 //Car steering
	 void turn_car(DrivingCommands t){
		 if (t == R && heading < 360)
		 { 
			 heading += TireTurningAngle[1] ; 
			 return;
		 }
		 if (t == R && heading == 360)
		 {
			 heading = TireTurningAngle[1];
			 return;
		 }
		 if (t == L && heading > 0)
		 { 
			 heading = heading +(TireTurningAngle[2]);
			 return;
		 }
		 if (t == L && heading == 0)
		 {
			 heading = TireTurningAngle[2] * (-3);
			 return;
		 }
	 }
	
	//Determine the direction of the car according to the four cardinal directions
	void ste_carHeading(string s) {
		int h;
		if (s=="N")	{ h = 0; } 
		if (s == "E") { h = 90; }
		if (s == "S") { h = 180; }
		if (s == "W") { h = 270; }

		if (h == 0 || h == 90 || h == 180 || h == 270 || h == 360)
		{
			heading = h;
		}
		else
		{		
			cout << h + " is Unavailable command!\n";
			heading = 0;
		}
	};

	int get_carHeading() {
		return heading;
	}

	string print_carHeading() {
		if (heading == 0 || heading == 360)
		{
			return "N";
		}
		if (heading == 90)
		{
			return "E";
		}
		if (heading == 180)
		{
			return "S";
		}
		if (heading == 270)
		{
			return "W";
		}
		else
		{
			return "unknown";
		}
	}

	void drive(Room* myRoom, Car::DrivingCommands command, int positionCoordinates1, int positionCoordinates2) {
		//command 'F' will make the car move forward 1 meter, 'B' will make the car move backwards 1 meter
		//'L' will rotate the car 90° counter clockwise and 'R* will rotate the car 90° clockwise.
		if (command == F || command == B)
		{
			if (command == F)
			{
				movment = 1;
			}
			if (command == B)
			{
				movment = -1;
			}

			if (heading == 0 || heading == 360)
			{
				positionCoordinates1 += movment;
			}
			if (heading == 180)
			{
				positionCoordinates1 -= movment;
			}
			if (heading == 90)
			{
				positionCoordinates2 += movment;
			}
			if (heading == 270)
			{
				positionCoordinates2 -= movment;
			}
		}

		if (command == R)
		{			
			turn_car(R);
		}
		if (command == L)
		{
			turn_car(L);
		}

		myRoom->set_position(positionCoordinates1, positionCoordinates2);		
	}

	~Car() {};
};


