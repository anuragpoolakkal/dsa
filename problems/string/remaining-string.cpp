// https://www.geeksforgeeks.org/problems/remaining-string3515

class Solution {
  public:

    string printString(string s, char ch, int count) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ch) {
                count--;
                if (count == 0) return s.substr(i + 1);
            }
        }
        return "";
    }
};