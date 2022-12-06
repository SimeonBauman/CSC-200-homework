


class room {

	public:

		int position;
		int up;
		int down;
		int right;
		int left;
		bool enabled;
		bool discovered;
		std::string disr;
};

class player {

	public:

		int position;
		int mapSize;
};


void loadRoom(int pos, room* rooms);

void fillRooms(room* rooms, int size);

bool findCommand(std::string command,player* p, room* rooms);

//void move(std::string dir, player* p, room* rooms);
void moveUp(player* p, room* rooms);
void moveDown(player* p, room* rooms);
void moveLeft(player* p, room* rooms);
void moveRight(player* p, room* rooms);

void generateMap(int size, room* rooms);

void displayMap(player* p, room* rooms);

void placePlayer(int size, player* p, room* rooms);

void discoverRoom(room* rooms, int pos);
void clearRooms(player* p, room* rooms);
