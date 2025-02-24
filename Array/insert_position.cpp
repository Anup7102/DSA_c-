#include <iostream>
using namespace std;

void insertElement(int arr[], int& n, int element, 
int position) {
    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    n++;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;
    int element = 10;
    int position = 2;

    cout << "Original array: ";
    printArray(arr, n);

    insertElement(arr, n, element, position);

    cout << "Array after insertion: ";
    printArray(arr, n);

    return 0;
}