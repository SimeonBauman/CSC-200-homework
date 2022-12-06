#include <iostream>
#include"ClassDef.hpp"

using namespace std;

int main()
{ 
    player* p = new player;
    int size = 10;
    p->mapSize = size;
    bool playing = true;
    room* rooms = new room[size * size];
    fillRooms(rooms, size);
    placePlayer(size, p, rooms);
    
    string command;
    //displayMap(rooms, size, p);
    cout << "please enter a command" << endl;
    while (playing) 
    {
       
        cin >> command;

        if (findCommand(command,p,rooms)) {
            //move(command, p, rooms);
            command = "";
            
        }
        else {
            cout << "Invalid" << endl;
            command = "";
        }

    }
    
}

