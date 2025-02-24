#include <iostream>
using namespace std;

// Function to reverse the digits of a number
int reverseNumber(int num, int rev = 0) {
    if (num == 0)
        return rev;
    rev = rev * 10 + num % 10;
    return reverseNumber(num / 10, rev);
}

// Function to check if a number is a palindrome
bool isPalindrome(int num) {
    return num == reverseNumber(num);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;

    return 0;
}