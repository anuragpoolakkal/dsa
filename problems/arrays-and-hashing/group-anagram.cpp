class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<string, vector<string>> collection;

        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string

            // Add the original string to the correct group in the collection map
            collection[sortedStr].push_back(str);
        }

        // Store the result in a vector
        vector<vector<string>> result;
        for (auto& x : collection) {
            result.push_back(x.second);
        }

        return result;
    }
};
