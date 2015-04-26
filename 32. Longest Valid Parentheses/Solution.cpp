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