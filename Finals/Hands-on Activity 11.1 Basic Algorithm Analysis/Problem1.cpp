#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

bool Unique(const std::vector<int>& A) {
    int n = A.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Different input sizes
    int sizes[] = {1000, 2000, 4000, 8000, 16000};

    std::cout << "PROBLEM 1: UNIQUE ELEMENTS\n";
    std::cout << std::setw(10) << "n"
              << std::setw(15) << "Result"
              << std::setw(25) << "Runtime (seconds)" << std::endl;

    for (int n : sizes) {

        // Create an array containing unique elements
        std::vector<int> A(n);

        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        auto start = std::chrono::high_resolution_clock::now();

        bool result = Unique(A);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << std::setw(10) << n
                  << std::setw(15) << (result ? "true" : "false")
                  << std::setw(25) << std::fixed << std::setprecision(8)
                  << elapsed.count() << std::endl;
    }

    return 0;
}
