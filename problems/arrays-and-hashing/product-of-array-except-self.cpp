class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> output;

        if (nums.size() < 1)
            return output;

        int product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            output.push_back(product);
        }

        product = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            output[i] = output[i-1] * product;
            product *= nums[i];
        }
        output[0] = product;

        return output;
    }
};