class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pos = 0, t_pos = 0;
        
        while(s_pos < s.length() && t_pos < t.length()) {
            if (s[s_pos] == t[t_pos]) {
                s_pos++;
            }
            t_pos++;
        }
        return s_pos == s.length();
    }
};