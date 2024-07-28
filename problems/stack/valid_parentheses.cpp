class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                stack.push(x);
            } else {
               if (stack.empty() || 
               (x == ')' && stack.top() != '(') || 
               (x == ']' && stack.top() != '[') || 
               (x == '}' && stack.top() != '{')) {
                return false;
               }
               stack.pop();
            }
        }
        return stack.empty();
    }
};