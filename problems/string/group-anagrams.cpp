class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> collection;
        vector<vector<string>> result;

        for (const string& s : strs) {
            string key = s;
            ranges::sort(key);
            collection[key].push_back(s);
        }

        for (auto& [word, anagrams] : collection) {
            result.push_back(anagrams);
        }

        return result;
    }
};