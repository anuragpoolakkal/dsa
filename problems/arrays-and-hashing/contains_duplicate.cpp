class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // using hash set
        unordered_set<int> collection;
        
        for (int num : nums) {
            if (collection.count(num) > 0) {
                return true;
            }
            collection.insert(num);
        }

        return false;
    }

    /* using hash map
        unordererd_map<int, inti> collection;

        for (int num : nums) {
            if (collection[num] >= 0) {
                return true;
            }
            collection[nums]++;
        }
        
        return false;
    */
};