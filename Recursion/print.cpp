#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printNumbers(n);
    return 0;
}