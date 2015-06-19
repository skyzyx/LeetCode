// LeetCode #32: Longest Valid Parentheses

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
            
        stack<int> st;
        int lastValidIndex = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    lastValidIndex = i;
                } else {
                    st.pop();
                    if (st.empty()) {
                        maxLen = max(maxLen, i - lastValidIndex);
                    } else {
                        maxLen = max(maxLen, i - st.top());
                    }
                }
            }
        }
        return maxLen;
    }
};