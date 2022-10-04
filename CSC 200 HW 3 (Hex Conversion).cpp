#include <iostream>
#include <string>
using namespace std;

void convertToHex(int num);
void convertToHexNoIf(int num);

int main()
{
    int num;
    cout << "please enter your value: ";
    cin >> num;
    convertToHexNoIf(num);
}

void convertToHex(int num) 
{
    string answer ="";
    string key = "ABCDEF";
    while (num > 0) 
    {
        int remainder = num % 16;
        num /= 16;
        if (remainder > 9) {
            answer = key[remainder - 10] + answer;
        }
        else {
            answer = to_string(remainder) + answer;
        }
    }

    cout << "\n" << "the answer is: " << answer;

}


void convertToHexNoIf(int num) 
{
    string answer = "";
    string key = "0123456789ABCDEF";

    while (num > 0)
    {
        answer = key[num % 16] + answer;
        num /= 16;
    }

    cout << "\n" << "the answer is: " << answer;
}


