// https://leetcode.com/problems/largest-number/

bool compare(int a, int b) {
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); // disables synchronization between C and C++ standard streams

        sort(nums.begin(), nums.end(), compare);
        string ans = "";

        for (int i = 0; i < nums.size(); i++)
            ans += to_string(nums[i]);

        if (ans[0] == '0') return "0";
        return ans;
    }
};