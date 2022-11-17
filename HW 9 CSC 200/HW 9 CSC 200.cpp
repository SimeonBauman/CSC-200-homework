#include <iostream>
#include "classHolder.hpp"

using namespace std;

int main()
{
	srand(time(NULL));
	dice* diceTen = new dice(10);
	dice* diceTwn = new dice(20);
	dice* diceFour = new dice(4);

	cout << "Ten: " << diceTen->roll() << endl;
	cout << "Twenty: " << diceTwn->roll() << endl;
	cout << "Four: " << diceFour->roll() << endl;
	

}


