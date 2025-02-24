#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

/*
Dry Run:
Given array: [12, 11, 13, 5, 6, 7]

Step 1: Divide the array into two halves
[12, 11, 13] and [5, 6, 7]

Step 2: Recursively divide the first half
[12, 11] and [13]
[12] and [11]

Step 3: Merge [12] and [11] to form [11, 12]
Merge [11, 12] and [13] to form [11, 12, 13]

Step 4: Recursively divide the second half
[5, 6] and [7]
[5] and [6]

Step 5: Merge [5] and [6] to form [5, 6]
Merge [5, 6] and [7] to form [5, 6, 7]

Step 6: Merge the two halves
Merge [11, 12, 13] and [5, 6, 7] to form [5, 6, 7, 11, 12, 13]

Sorted array: [5, 6, 7, 11, 12, 13]
*/