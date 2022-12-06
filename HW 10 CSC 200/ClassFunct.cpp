#include <iostream>
#include <string>
#include "ClassDef.hpp"

using namespace std;

typedef void (*FunctionWithTwoParameters)(player* p, room* rooms);

void loadRoom(int pos, room* rooms) 
{
	
	cout << rooms[pos].disr << endl;
	
}

void fillRooms(room* rooms, int size)
{
	for (int i = 0; i < size*size; i++) {
		
		rooms[i].position = i;
		rooms[i].disr = "the room position is: " + to_string(rooms[i].position);
		rooms[i].enabled = false;
		rooms[i].discovered = false;
		if (i >= size) 
		{
			rooms[i].up = i - size;
		}
		else 
		{
			rooms[i].up = -1;
		}
		if (i % size != 0) 
		{
			rooms[i].left = i - 1;
		}
		else
		{
			rooms[i].left = -1;
		}
		if ((i - (size-1)) % size != 0) 
		
		{
			rooms[i].right = i + 1;
		}
		else
		{
			rooms[i].right = -1;
		}
		if (i < size * size - size) {
			rooms[i].down = i + size;
		}
		else
		{
			rooms[i].down = -1;
		}
	}

	generateMap(size,rooms);
}


bool findCommand(std::string command, player* p, room* rooms)
{ 
	string commands[6] = {"up","down","left","right","map", "clear"};
	FunctionWithTwoParameters moveFunctions[] = { moveUp,moveDown,moveLeft,moveRight,displayMap,clearRooms };
	for (int i = 0; i < 7; i++) {
		if (command == commands[i] ) {
			
			moveFunctions[i](p, rooms);
			
			return true;
			
		}
		else {
			
		}
	}
	return false;
}

void moveUp(player* p, room* rooms) {
	if (rooms[p->position].up != -1) {
		if ((rooms[rooms[p->position].up].discovered == false)) {
			cout << "You Discovered a New Area!" << endl;
		}
		if (rooms[rooms[p->position].up].enabled == false) {
			discoverRoom(rooms, rooms[p->position].up);
			cout << "no room avaialbe" << endl;
		}
		else {
			discoverRoom(rooms, rooms[p->position].up);
			p->position = rooms[p->position].up;
		}
	}
	else {
		cout << "no room avaialbe" << endl;
	}
}
void moveDown(player* p, room* rooms) {
	if (rooms[p->position].down != -1) {
		if ((rooms[rooms[p->position].down].discovered == false)) {
			cout << "You Discovered a New Area!" << endl;
		}
		if (rooms[rooms[p->position].down].enabled == false) {
			discoverRoom(rooms, rooms[p->position].down);
			cout << "no room avaialbe" << endl;
		}
		else {
			discoverRoom(rooms, rooms[p->position].down);
			p->position = rooms[p->position].down;
		}
	}
	else {
		cout << "no room avaialbe" << endl;
	}
}
void moveRight(player* p, room* rooms) {
	if (rooms[p->position].right != -1) {
		if ((rooms[rooms[p->position].right].discovered == false)) {
			cout << "You Discovered a New Area!" << endl;
		}
		if (rooms[rooms[p->position].right].enabled == false) {
			discoverRoom(rooms, rooms[p->position].right);
			cout << "no room avaialbe" << endl;
		}
		else {
			discoverRoom(rooms, rooms[p->position].right);
			p->position = rooms[p->position].right;
		}
	}
	else {
		cout << "no room avaialbe" << endl;
	}
}
void moveLeft(player* p, room* rooms) {
	if (rooms[p->position].left != -1) {
		if ((rooms[rooms[p->position].left].discovered == false)) {
			cout << "You Discovered a New Area!" << endl;
		}
		if (rooms[rooms[p->position].left].enabled == false) {
			discoverRoom(rooms, rooms[p->position].left);
			cout << "no room avaialbe" << endl;
		}
		else {
			discoverRoom(rooms, rooms[p->position].left);
			p->position = rooms[p->position].left;
		}
	}
	else {
		cout << "no room avaialbe" << endl;
	}
}
/*
void move(string dir, player* p, room* rooms) {
	int index = p->position;
	bool moved = false;
	if (dir == "up") {
		if (rooms[p->position].up != -1 && rooms[rooms[p->position].up].enabled == true) {
			p->position = rooms[p->position].up;
			moved = true;
		}
	}
		else if (dir == "down") {
			if (rooms[p->position].down != -1 && rooms[rooms[p->position].down].enabled == true) {
				p->position = rooms[p->position].down;
				moved = true;
			}
			else {
				cout << "no room avaialbe" << endl;
			}
		}
		else if (dir == "left") {
			if (rooms[p->position].left != -1 && rooms[rooms[p->position].left].enabled == true) {
				p->position = rooms[p->position].left;
				moved = true;
			}

		}
		else if (dir == "right") {
			if (rooms[p->position].right != -1 && rooms[rooms[p->position].right].enabled == true) {
				p->position = rooms[p->position].right;
				moved = true;
			}

		}

		if (moved) {
			loadRoom(p->position,rooms);
		}
		else {
			cout << "no room avaliabe" << endl;
		}

	
}*/

void discoverRoom(room* rooms, int pos) {
	rooms[pos].discovered = true;
}

void generateMap(int size, room* rooms) 
{
	srand(time(NULL));
	
	for (int i = 0; i < size*size; i++) {
		float weight = 0.0;
		int others[4] = { rooms[i].up,rooms[i].down, rooms[i].right, rooms[i].left };
		for (int j = 0; j < 4; j++) {
			if (others[j] != -1) {
				weight += .75;
			}
		}
		if (rand() % 10 + weight > 4) {
			rooms[i].enabled = true;
		}
		

	}
	
}

void displayMap(player* p, room* rooms) {
	for (int i = 0; i < p->mapSize * p->mapSize; i++) {
		if (rooms[i].discovered) {
			if (i == p->position) {
				cout << "+ ";
			}
			else if (rooms[i].enabled) {
				cout << "0 ";
			}
			else {
				cout << "  ";
			}
			
		}
		else {
			cout << "? ";
		}
		if ((i - (p->mapSize -1)) % p->mapSize == 0) {
			cout << endl;
		}
	}
}

void placePlayer(int size, player* p, room* rooms) {
	int i = 0;
	int pos = 0;
	int place = rand() % (size * size);

	while (pos <= place) {
		if (rooms[i % (size*size)].enabled) {
			pos++;
		}
		i++;
	}
	rooms[pos].discovered = true;
	p->position = pos;
}

void clearRooms(player* p, room* rooms) {
	for (int i = 0; i < p->mapSize * p->mapSize; i++) {
		discoverRoom(rooms, i);
	}
	cout << "all rooms are now discovered" << endl;
}