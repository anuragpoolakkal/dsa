#include<iostream>
using namespace std;

int countZero(int n, int count) {
    if (n == 0)
        return count;

    int rem = n % 10;
    if (rem == 0)
        return countZero(n / 10, count + 1);
    
    return countZero(n / 10, count);
}

int main () {
    int n, count;
    cout << "Enter the number: ";
    cin >> n;

    count = countZero(n, 0);
    cout << count << " zeroes";
    return 0;
}