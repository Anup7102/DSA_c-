#include <iostream>
#include <cmath>
using namespace std;

double squareRoot(double number, double precision) {
    double low = 0, high = number, mid;

    while (high - low > precision) {
        mid = (low + high) / 2;
        if (mid * mid < number) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return (low + high) / 2;
}

int main() {
    double number, precision;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the precision: ";
    cin >> precision;

    double result = squareRoot(number, precision);
    cout << "Square root of " << number << " is approximately " << result << endl;

    return 0;
}