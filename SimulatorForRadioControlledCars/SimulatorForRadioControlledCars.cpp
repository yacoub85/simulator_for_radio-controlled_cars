// SimulatorForRadioControlledCars.cpp
//This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<string>
#include<array>
#include "Room.h"
#include "Car.h"
using namespace std;

int main()
{
	Room* myRoom = new Room;
	Car* myCar = new Car;

	int length;
	int width;
	unsigned int positionCoordinates1, positionCoordinates2;
	string heading;
	string driveCommand;
	

	cout << "\t\t***Simulator for radio controlled cars***\n\n";
	cout << "Please enter the room size in meters\n";
	cout << "Enter the length followed by the width separated with a space and press 'Enter'\n";
	//Handle incorrect entry
	while (true)
	{
		cin >> length >> width;
		if (cin.fail() || length < 1 || width < 1)
		{
			cout << "Invalid input try again" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else
		{
			myRoom->set_RoomSize(length, width);
			break;
		}
	}

	system("CLS");
	cout << "The room size = ";
	cout << myRoom->get_roomeArea() << " meters\n\n";
	cout << "Enter starting position and heading of the car.\n";
	cout << "Enter two integers and one letter separated with spaces.\n";
	cout << "First number from   0 to " << (myRoom->get_roomLength() - 1) << endl;
	cout << "Second  number from 0 to " << (myRoom->get_roomWidth() - 1) << endl;
	cout << "The letter: {N, S, W or E} and press Enter.\n";
	//Handle incorrect entry
	while (true)
	{
		cin >> positionCoordinates1 >> positionCoordinates2 >> heading;
		if (cin.fail() || (heading != "N" && heading != "S" && heading != "E" && heading != "W") || positionCoordinates1 >= length  || positionCoordinates2 >= width )
		{
			cout << "Invalid input try again" << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
		else
		{
			myRoom->set_position(positionCoordinates1, positionCoordinates2);
			myCar->ste_carHeading(heading);
			break;
		}
	}

	system("CLS");
	cout << "\n			*** Enjoy driving your "<< myCar->Get_TypeOfCar() <<" ***  \n\n\n";
	cout << "Enter driving commands in series and press Enter.\nAvailable commands are F, B, L or R.\n";

	bool resultOfSimulation = true;
	int* myPosition;

	myPosition = myRoom->get_position();
	cout << "Start position is {" << myPosition[0] << "," << myPosition[1] << "}\n";

	//Handle incorrect entry for driving commands
	while (true)
	{
		int cheackInput = 1;
		cin >> driveCommand;
		for (size_t i = 0; i < driveCommand.length(); i++) 
		{
			if (cin.fail() || driveCommand[i] != 'F' && driveCommand[i] != 'B' && driveCommand[i] != 'R' && driveCommand[i] != 'L')
			{
				cout << driveCommand[i] << " is invalid try again\n";
				driveCommand.clear();
				cin.clear();
				cin.ignore(256, '\n');
				cheackInput = 0;
			}
		}
		if (cheackInput)
		{
			break;
		}
	}
	
	char command;
	for (size_t i = 0; i < driveCommand.length(); i++)
	{
		command = driveCommand[i];
		myPosition = myRoom->get_position();
		myCar->drive(myRoom, (Car::DrivingCommands)command, myPosition[0], myPosition[1]);
		
		myPosition = myRoom->get_position();
		if (myPosition[0] < 0 || myPosition[0] > (myRoom->get_roomLength()-1))
		{
			if (myPosition[0] < 1)
			{
				myPosition[0] = 1;
			}
			cout << "The car drove into the wall at  ";
			cout << "position {" << myPosition[0]-1 << "," << myPosition[1] << "}\n";
			cout << "when the car execute the command '" << command << "' and its heading was "
				<< myCar->print_carHeading();
			resultOfSimulation = false;
			break;
		}
		else if (myPosition[1] < 0 || myPosition[1] > (myRoom->get_roomWidth()-1))
		{
			if (myPosition[1] < 1)
			{
				myPosition[1] = 1;
			}
			cout << "The car drove into the wall at  ";
			cout << "position {" << myPosition[0] << "," << myPosition[1]-1 << "}\n";
			cout << "when the car execute the command '" << command << "' and its heading was " << myCar->print_carHeading();
			resultOfSimulation = false;
			break;
		}
	}
	if (resultOfSimulation)
	{
		myPosition = myRoom->get_position();
		cout << "Everything went ok!\n";
		cout << "The car position is {" << myPosition[0] << "," << myPosition[1] << "}\n";
		cout << "and its heading " << myCar->print_carHeading() << endl;
	}
	
	cout << "\n\nThe simulation is done! Enter any key and press Enter to exit\n";
	int exit;
	cin >> exit;

	delete myRoom;
	delete myCar;
}