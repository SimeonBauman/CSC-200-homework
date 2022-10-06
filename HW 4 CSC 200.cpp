#include <iostream>
#include <string>

using namespace std;


int baseToDecimal(string num, int base);
int returnIndex(char c);

int main()
{
    string num;
    int base;
    cout << "Please enter your number: ";
    cin >> num;
    cout << "Please enter your base: ";
    cin >> base;
    cout << "\n" << "the answer is: " << baseToDecimal(num, base);
}


int baseToDecimal(string num, int base) 
{
    
    int answer = 0;
    for (int i = 0; i < num.length(); i++)
    {
        answer = (answer * base) + returnIndex(num[i]);
    }
    
    return answer;

}

int returnIndex(char c) 
{
    string key = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < key.length(); i++)
    {
        if (key[i] == c) {
            return i;
        }
    }
    return -1;
}

