#include <iostream>
#include <vector>
using namespace std;

// Partition function for quicksort
int partition(vector<int>& A, int low, int high) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(vector<int>& A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);

        quicksort(A, low, pi - 1);
        quicksort(A, pi + 1, high);
    }
}

int main() {
    vector<int> A = {3, 8, 6, 7, 5, 9, 10};

    quicksort(A, 0, A.size() - 1);

    cout << "Sorted array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
