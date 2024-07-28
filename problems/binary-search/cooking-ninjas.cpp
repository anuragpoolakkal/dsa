// https://www.naukri.com/code360/problems/cooking-ninjas_1164174

#include <bits/stdc++.h>

bool isCookingPossible(vector<int> rank, int mid, int m) {
    int dishesPrepared = 0, elapsedTime = 0;

    for (size_t i = 0; i < rank.size(); i++) {
        int dishesCooked = 0, timeTaken = 0;

        while (timeTaken + rank[i] * (dishesCooked + 1) <= mid && dishesCooked < m) {
            timeTaken += rank[i] * (dishesCooked + 1);
            dishesCooked++;            
        }

        dishesPrepared += dishesCooked;
        elapsedTime += timeTaken;

        if (dishesPrepared >= m) {
            return true;
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    int start = 0;
    int end = rank[rank.size() - 1] * m * (m+1) / 2;
    int mid = start + (end - start) / 2;

    int time = -1;

    while (start <= end) {
        if (isCookingPossible(rank, mid, m)) {
            time = mid;
            end = end - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return time;
}
