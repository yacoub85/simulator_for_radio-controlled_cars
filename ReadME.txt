
# SimulatorForRadioControlledCars

-General Info:
This Project is about creating a simulator for radio-controlled cars which to be used to test cars. 

The simulator is a console application which will test various commands and see if the radio-controlled cars can execute them without hitting the wall.

The simulated environment would be a room and the size of it shall be what the user would request in meters.

The simulator will output the results of the simulation which either can be successful or unsuccessful. If the simulation was successful, it would print the end position and heading of the car and if it’s not successful it would print an error describing, what went wrong and which position did it crash.


-When started the simulator, the user is asked about:
1. Tthe size of the room.
This is inputted with two integers separated with a space.
2. Starting position and heading of the car.
This is inputted with two integers and one letter separated with spaces. The letter can be N, S, W or E.
3. The commands to execute.
This is inputted with all commands in series. Available commands are F, B, L or R.

-Sample input:
8 6
2 3 N
FFFRFFLBB

-Technologies
Project is created with:
C++
Tolls
visual studio 2019

