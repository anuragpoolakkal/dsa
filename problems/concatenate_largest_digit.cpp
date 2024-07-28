// https://www.naukri.com/code360/problems/concatenate-the-largest-digit_1263688

#include <bits/stdc++.h>

int largestDigit(int n) {
    int largest = 0;
    
    while (n) {
        int r = n % 10;
        largest = max(largest, r);
        n = n / 10;
    }
    return largest;
}

int concatLargestDigit(int a, int b, int c) {
    int number = 0;

    number = largestDigit(a) * 100;
    number += largestDigit(b) * 10;
    number += largestDigit(c);

    return number;
}