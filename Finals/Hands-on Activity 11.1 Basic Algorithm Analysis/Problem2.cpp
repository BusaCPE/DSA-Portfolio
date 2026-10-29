#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// Recursive Power
long long rpower(long long x, int n) {
    if (n == 0)
        return 1;
    else
        return x * rpower(x, n - 1);
}

// Binary Recursive Power
long long brpower(long long x, int n) {
    if (n == 0)
        return 1;

    if (n % 2 == 1) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    if (n % 2 == 0) {
        long long y = brpower(x, n / 2);
        return y * y;
    }

    return 1;
}

int main() {

    // Use small n because rpower has linear recursion depth.
    int sizes[] = {10, 20, 30, 40, 50};

    long long x = 2;

    cout << "PROBLEM 2: POWER ALGORITHMS\n";
    cout << "----------------------------------------------------------------\n";
    cout << setw(10) << "n"
         << setw(25) << "rpower (seconds)"
         << setw(25) << "brpower (seconds)" << endl;

    for (int n : sizes) {

        // Measure rpower
        auto start1 = high_resolution_clock::now();

        long long result1 = rpower(x, n);

        auto end1 = high_resolution_clock::now();

        duration<double> elapsed1 = end1 - start1;


        // Measure brpower
        auto start2 = high_resolution_clock::now();

        long long result2 = brpower(x, n);

        auto end2 = high_resolution_clock::now();

        duration<double> elapsed2 = end2 - start2;


        // Verify both algorithms produce the same result
        if (result1 != result2) {
            cout << "Error: Results do not match!" << endl;
            return 1;
        }

        cout << setw(10) << n
             << setw(25) << fixed << setprecision(10) << elapsed1.count()
             << setw(25) << fixed << setprecision(10) << elapsed2.count()
             << endl;
    }

    return 0;
}
