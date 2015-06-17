// LeetCode #38: Count and Say

/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
            
        string res = "1";
        for (int i = 1; i < n; i++) {
            string tmp = "";
            int count = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == res[j-1])
                    count++;
                else {
                    tmp += to_string(count) + res[j-1];
                    count = 1;
                }
            }
            tmp += to_string(count) + res[res.size() - 1];
            res = tmp;
        }
        return res;
    }
};