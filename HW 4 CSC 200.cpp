#include <iostream>
#include <string>

using namespace std;


int baseToDecimalNonClassWay(string num, int base);
int returnIndex(char c);
int doExponent(int num, int times);
int baseToDecimalClassWay(string num, int base);

int main()
{
    string num;
    int base;
    cout << "Please enter your number: ";
    cin >> num;
    cout << "Please enter your base: ";
    cin >> base;
    
    cout << "\n" << "the answer is: " << baseToDecimalNonClassWay(num, base) << endl;
    cout << "the second way's answer is: " << baseToDecimalClassWay(num, base);
    
}


int baseToDecimalNonClassWay(string num, int base) 
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


int baseToDecimalClassWay(string num, int base)
{
    int answer = 0;
    for (int i = num.length() - 1; i >= 0; i--)
    {
        answer += (doExponent(base, num.length() - 1 - i) * returnIndex(num[i]));
    }
    return answer;
}

int doExponent(int num, int times)
{
    int answer = 1;
    
    for (int i = 0; i < times; i++)
    {
        answer = num * answer;
        
    }
    
    return answer;

}
