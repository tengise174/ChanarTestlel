#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convertToBase(int number, int base)
{
    if (base < 2 || base > 16)
    {
        return "Wrong Base (2-16)";
    }
    if (number == 0)
    {
        return "0";
    }

    const string chars = "0123456789ABCDEF";
    vector<char> result;

    while (number > 0)
    {
        int remainder = number % base;
        result.push_back(chars[remainder]);
        number /= base;
    }

    std::string converted;
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    {
        converted += *it;
    }

    return converted;
}

int main()
{
    int number, base;
    cout << "enter number ";
    cin >> number;
    cout << "enter digit between 2 and 16 ";
    cin >> base;
    if (base < 2 || base > 16)
    {
        cout << "Base must be between 2 and 16." << endl;
        return 1;
    }

    string result = convertToBase(number, base);
    cout << "The number in base " << base << result << endl;

    return 0;
}
