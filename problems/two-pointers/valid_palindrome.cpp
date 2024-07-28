class Solution {
public:
    bool isPalindrome(string s) {
        string k = "";

        for (auto& x : s) {
            if (isalnum(x)) {
                k += tolower(x);
            }
        }
        
        string p = k;

        reverse(p.begin(), p.end());

        return p == k;
    }
};