// https://www.naukri.com/code360/problems/aggressive-cows_1082559

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cowCount = 1, lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int start = 0, ans = -1, maxi = -1;

    for (int i = 0; i < stalls.size(); i++) {
        maxi = max(stalls[i], maxi);
    }
    int end = maxi;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (isPossible(stalls, k, mid)) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}