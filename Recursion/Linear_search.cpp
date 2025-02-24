#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target) {
    if (size == 0) {
        return false;
    }
    if (arr[0] == target) {
        return true;
    }
    return linearSearch(arr + 1, size - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    if (linearSearch(arr, size, target)) {
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}