#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string decimalToBinary(int number)
{
    if (number == 0)
        return "0";
    vector<char> binaryDigits;

    while (number > 0)
    {
        int rem = number % 2;
        binaryDigits.push_back(rem ? '1' : '0');
        number /= 2;
    }

    reverse(binaryDigits.begin(), binaryDigits.end());

    string binaryString(binaryDigits.begin(), binaryDigits.end());

    return binaryString;
}

int binaryToDecimal(const string binaryString)
{
    int decimalNumber = 0;
    int base = 1;

    for (int i = binaryString.size() - 1; i >= 0; --i)
    {
        if (binaryString[i] == '1')
        {
            decimalNumber += base;
        }
        base *= 2;
    }

    return decimalNumber;
}

int main()
{
    int decimalNumber;

    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    if (decimalNumber < 0)
    {
        cout << "Enter a integer" << endl;
        return 1;
    }

    string binaryString = decimalToBinary(decimalNumber);

    cout << "Binary: " << binaryString << endl;

    int convertedDecimalNumber = binaryToDecimal(binaryString);

    cout << "decimal: " << convertedDecimalNumber << endl;

    return 0;
}
