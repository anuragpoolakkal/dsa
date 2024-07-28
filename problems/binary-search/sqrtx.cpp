#include<iostream>
using namespace std;

int mySqrt(int x) {
    long long int start = 0, end = x;
    long long int mid = start + (end - start) / 2;

    long long int ans = -1;

    while (start <= end) {
        long long int square = mid*mid;

        if (square == x) {
            return mid;
        }

        if (square < x) {
            ans = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

double morePrecision(int x, int precision, int tempSol) {
    int factor = 1;
    double ans = tempSol;

    for (int i = 1; i < precision; i++) {
        factor = factor/10;
        for (double j = ans; j*j<x; j=j+factor) {
            ans = j;
        }
    }
    return ans;
}

int main() {
    int x;
    cout << "Enter the number: ";
    cin >> x;

    int tempSol = mySqrt(x);
    cout << "Square root is " << morePrecision(x, 3, tempSol) << endl;
    return 0;
}