
#include <iostream>
using namespace std;

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    bool validateTriangle() const;
};

int main() {
    Triangle set1(40, 30, 110);

    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle." << endl;
    } else {
        cout << "The shape is NOT a valid triangle." << endl;
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

bool Triangle::validateTriangle() const {
    return totalAngle == 180;
}

