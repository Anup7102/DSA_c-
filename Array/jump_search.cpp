#include <iostream>
#include <cmath>

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[std::min(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }

    while (arr[prev] < target) {
        prev++;
        if (prev == std::min(step, size)) {
            return -1;
        }
    }

    if (arr[prev] == target) {
        return prev;
    }

    return -1;
}

int main() {
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 55;
    int index = jumpSearch(arr, size, target);

    if (index != -1) {
        std::cout << "Number " << target << " is at index " << index << std::endl;
    } else {
        std::cout << "Number " << target << " is not in the array" << std::endl;
    }

    return 0;
}