// LeetCode #20: Valid Parentheses

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;
            
        stack<char> stack;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
                continue;
            }
            
            if (!stack.empty()) {
                char peek = stack.top();
                if ((peek == '(' && s[i] == ')') || (peek == '{' && s[i] == '}') || (peek == '[' && s[i] == ']'))
                    stack.pop();
                else
                    return false;
            }
        }
        
        return stack.empty();
        
    }
};