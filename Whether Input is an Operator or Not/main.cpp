#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    cout << "Operators found in the input: " << endl;
    int count = 1;
    for (char c : input)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c=='=')
        {
            cout << "operator" << count << ":  " << c << endl;
            count++;
        }
    }

    return 0;
}
