// https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, int m, vector<int> time, int mid) {
    int chapterCount = 1, timeSum = 0;

    for (int i = 0; i < n; i++) {
        if (timeSum + time[i] <= mid) {
            timeSum += time[i];
        } else {
            chapterCount++;
            if (chapterCount > m || time[i] > mid) {
                return false;
            }
            timeSum = time[i];
        }
        if (chapterCount > m) {
            return false;
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {	
    int start = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += time[i];
    }

    int end = sum, ans = -1;
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (isPossible(n, m, time, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }	
    return ans;
}

int main() {
    int n = 3; // number of chapters
    int m = 5; // number of students
    vector<int> time = {1, 2, 2, 3, 1}; // time to read each chapter

    cout << "Minimum possible maximum time: " << ayushGivesNinjatest(n, m, time) << endl;
    return 0;
}
