#include <iostream>
using namespace std;

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (arr[start] <= pivot && start < ub) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[lb], arr[end]);
    return end;
}

void quick(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        quick(arr, lb, loc - 1);
        quick(arr, loc + 1, ub);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
