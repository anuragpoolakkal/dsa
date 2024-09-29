class Solution {
public:
    int robHouses(vector<int>& houses) {
        int prev1 = 0, prev2 = 0;
        for (int house : houses) {
            int temp = prev1;
            prev1 = max(prev1, prev2 + house);
            prev2 = temp;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> houses1(nums.begin(), nums.end() - 1);
        vector<int> houses2(nums.begin() + 1, nums.end());

        return max(robHouses(houses1), robHouses(houses2));
    }
};