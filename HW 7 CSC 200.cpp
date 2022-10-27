#include <iostream>
#include <time.h>


using namespace std;

int roll(int min, int max);

struct player 
{
	int hp = roll(15,25);
	int amour = roll(8,16);
};




int main()
{
	
	srand(time(NULL));

	struct player player1;
	struct player player2;
	
	int turn = roll(0, 1);
	

	cout << "Player 1 stats: " << player1.hp << " Hp, " << player1.amour << " Armor" << endl;
	cout << "Player 2 stats: " << player2.hp << " Hp, " << player2.amour << " Armor" << endl;
	cout << "Press enter to start the match" << endl;
	cin.ignore();

	while (player1.hp > 0 && player2.hp > 0)
	{
		if (turn == 0) {
			cout << "Player 1's turn" << endl;

			if (roll(1, 20) >= player2.amour)
			{
				int damage = roll(2, 6);
				player2.hp -= damage;
				cout << "Player 1 did " << damage << " damage" << endl;
				cout << "Player 2 has " << player2.hp << " health" << endl;
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

			if (roll(1, 20) >= player1.amour)
			{
				int damage = roll(2, 6);
				player1.hp -= damage;
				cout << "Player 2 did " << damage << " damage" << endl;
				cout << "Player 1 has " << player1.hp << " health" << endl;
			}
			else
			{
				cout << "Player 2 missed" << endl;
			}
			turn = 0;
		}

	}

	if (player1.hp > 0)
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
	return(rand() % (max - min + 1) + min);
}


