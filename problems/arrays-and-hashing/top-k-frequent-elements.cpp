class Solution {
public:
    static bool compare(pair<int, int>&p1, pair<int, int>&p2) {
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> collection;

        for (int x : nums) {
            collection[x]++;
        }

        vector<pair<int, int>> temp;

        for (auto x : collection) {
            temp.push_back({x.first, x.second});
        }

        sort(temp.begin(), temp.end(), compare);

        for (int i = 0; i < k; i++) {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};