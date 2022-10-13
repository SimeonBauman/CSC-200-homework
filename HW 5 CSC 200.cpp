#include <iostream>
#include <string.h>

using namespace std;

string rot13(string source);
int indexOf(string map, char c);

int main()
{
    cout << "Please enter the word you would like encoded: ";
    string input = "";
    cin >> input;
    cout << rot13(input);
}

string rot13(string source)
{
    string answer = "";
    string map = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < source.length(); i++)
    {
        int pos = (indexOf(map, source[i]) + 13) % 26;
        answer = answer + map[pos];

    }
    return answer;
}


int indexOf(string s, char c)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            return i;
        }
    }
    return -1;
}
