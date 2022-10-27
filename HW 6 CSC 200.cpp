#include <iostream>
#include <time.h>

using namespace std;

int roll(int min, int max);

int main()
{
	srand(time(NULL));
	int turn = roll(0,1);
	int Hp1 = roll(15, 25);
	int Hp2 = roll(15, 25);
	int A1 = roll(8, 16);
	int A2 = roll(8, 16);

	cout << "Player 1 stats: " << Hp1 << " Hp, " << A1 << " Armor" << endl;
	cout << "Player 2 stats: " << Hp2 << " Hp, " << A2 << " Armor" << endl;
	cout << "Press enter to start the match" << endl;
	cin.ignore();

	while (Hp1 > 0 && Hp2 > 0) 
	{
		if (turn == 0) {
			cout << "Player 1's turn" << endl;

			if (roll(1, 20) >= A2) 
			{
				int damage = roll(2, 6);
				Hp2 -= damage;
				cout << "Player 1 did " << damage << " damage" << endl;
			}
			else
			{
				cout << "Player 1 missed" << endl;
			}
			turn = 1;
		}
		else 
		{

			cout << "Player 2's turn" << endl;

			if (roll(1, 20) >= A1)
			{
				int damage = roll(2, 6);
				Hp1 -= damage;
				cout << "Player 2 did " << damage << " damage" << endl;
			}
			else 
			{
				cout << "Player 2 missed" << endl;
			}
			turn = 0;
		}
		
	}

	if (Hp1 > 0) 
	{
		cout << "Player 1 Won!" << endl;
		cout << "Player 2 lost";
	}
	else
	{
		cout << "Player 2 Won!" << endl;
		cout << "Player 1 lost";
	}
    
}


int roll(int min, int max)
{
	return( rand() % (max - min +1) + min );
}


