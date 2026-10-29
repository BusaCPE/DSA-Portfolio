#include <iostream>
#include <cmath>
using namespace std;

double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}

double perimeterTriangle(double a, double b, double c) {
    return a + b + c;
}

string triangleType(double a, double b, double c) {
    double sides[3] = {a, b, c};

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (sides[i] > sides[j]) {
                double temp = sides[i];
                sides[i] = sides[j];
                sides[j] = temp;
            }
        }
    }

    double x = sides[0];
    double y = sides[1];
    double z = sides[2];

    if ((x * x + y * y) > (z * z))
        return "Acute-angled Triangle";
    else if ((x * x + y * y) < (z * z))
        return "Obtuse-angled Triangle";
    else
        return "Others";
}

int main() {
    double base, height;
    double side1, side2, side3;

    cout << "Enter base: ";
    cin >> base;

    cout << "Enter height: ";
    cin >> height;

    cout << "Enter three sides: ";
    cin >> side1 >> side2 >> side3;

    cout << "\nArea = " << areaTriangle(base, height) << endl;
    cout << "Perimeter = " << perimeterTriangle(side1, side2, side3) << endl;
    cout << "Triangle Type = " << triangleType(side1, side2, side3) << endl;

    return 0;
}


