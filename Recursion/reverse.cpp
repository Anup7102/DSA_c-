#include <iostream>
using namespace std;

int reverseNumber(int num, int rev = 0) {
    if (num == 0)
        return rev;
    rev = rev * 10 + num % 10;
    return reverseNumber(num / 10, rev);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int reversedNum = reverseNumber(num);
    cout << "Reversed number: " << reversedNum << endl;
    return 0;
}