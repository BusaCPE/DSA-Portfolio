#include <iostream>
using namespace std;

// Function Prototypes
void findSum(int a, int b);
bool isGreater(int a, int b);
void logicalOperation(bool a, bool b);

int main()
{
    int x, y;
    bool p, q;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    findSum(x, y);

    if (isGreater(x, y))
        cout << x << " is greater than " << y << endl;
    else
        cout << x << " is not greater than " << y << endl;

    cout << "\nEnter first boolean value (0 or 1): ";
    cin >> p;

    cout << "Enter second boolean value (0 or 1): ";
    cin >> q;

    logicalOperation(p, q);

    return 0;
}

// Function Definitions

void findSum(int a, int b)
{
    cout << "\nSum = " << a + b << endl;
}

bool isGreater(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}

void logicalOperation(bool a, bool b)
{
    cout << "AND = " << (a && b) << endl;
    cout << "OR = " << (a || b) << endl;
    cout << "NOT A = " << !a << endl;
    cout << "NOT B = " << !b << endl;
}


