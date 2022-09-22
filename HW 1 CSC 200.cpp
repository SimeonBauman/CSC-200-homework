#include <iostream>
using namespace std;


int cost = 234;
int Paid = 500;

int main()
{
    int owed = Paid - cost;

    cout << "dollars: " << owed / 100 << endl;
    owed %= 100;

    cout << "quaters: " << owed / 25 << endl;
    owed %= 25;

    cout << "dimes: " << owed / 10 << endl;
    owed %= 10;

    cout << "nickles: " << owed / 5 << endl;
    owed %= 5;

    cout << "Pennies: " << owed << endl;
}