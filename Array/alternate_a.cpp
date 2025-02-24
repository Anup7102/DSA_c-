#include <iostream>
using namespace std;

int maxAlternatingSubarray(int arr[], int n) {
    int maxLength = 1;
    int currentLength = 1; 

    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 1;
        }
    }

    return maxLength;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxAlternatingSubarray(arr, n);
    cout << "Maximum length of alternating even-odd subarray: " << result << endl;

    return 0;
}
