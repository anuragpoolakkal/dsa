class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (string x : strs) {
            result += to_string(x.size()) + "#" + x;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length; 
        }
        return result;
    }
};
