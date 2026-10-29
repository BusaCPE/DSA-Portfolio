#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

//Standard merge function for Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

//Sequential Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//Parallel Merge Sort wrapper utilizing a thread for one half
void parallelMergeSort(std::vector<int>& arr, int left, int right, int depth = 0) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Limit depth to prevent excessive thread creation overhead
        if (depth < 2) {
            std::thread t(parallelMergeSort, std::ref(arr), left, mid, depth + 1);
            parallelMergeSort(arr, mid + 1, right, depth + 1);
            t.join();
        } else {
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
        }
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    
    std::cout << "Original array: ";
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;

    parallelMergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted array using Multi-threaded Merge Sort: ";
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}