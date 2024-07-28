class Solution {
public:
    bool isAnagram(string s, string t) {
        // using two hash maps and without sorting
        unordered_map<char, int> collection_t;
        unordered_map<char, int> collection_s;

        for (char letter : t)
            collection_t[letter]++;
        
        for (char letter: s)
            collection_s[letter]++;

        if (collection_t == collection_s)
            return true;

        return false;
    }
};