#pragma once
//This class represents the simulated environment which is a room of size in whole meters.
class Room
{
protected:
	unsigned int length;
	unsigned int width;
	int position[2];
	    
public:
	//Determine the area of the test environment
	void set_RoomSize(unsigned int l, unsigned int w) {
		length = l;
		width = w;
	}

	void set_position(int positionCoordinates1, int positionCoordinates2) {
		position[0] = positionCoordinates1;
		position[1] = positionCoordinates2;		
	}
	//Returns the current vehicle location
	int  *get_position() {
		return position;
	}
	
	unsigned int get_roomLength() { return length; }
	unsigned int get_roomWidth() { return width; }
	//Calculating the room area.
	int get_roomeArea() { return length * width; }

	~Room() {};
};

