#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string word = "";
	cout << "Please type in the word you would like reversed: ";
	cin >> word;
    string reversedWord;
	for(int i = word.length() - 1; i >= 0; i--)
	{
		reversedWord += word[i];
	}
	cout << reversedWord << endl;

	cout << "the reversed word is '" << reversedWord << "'";
}

