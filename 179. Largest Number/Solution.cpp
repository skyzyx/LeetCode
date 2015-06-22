// LeetCode #179: Largest Number

/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> s;
        for (int i = 0; i < num.size(); i++) 
            s.push_back(to_string(num[i]));
        sort(s.begin(), s.end(), compare);
        
        string res;
        for (int i = 0; i < num.size(); i++)
            res += s[i];
        
        int i = 0;
        while (i < res.size() - 1) {
            if (res[i] != '0')
                break;
            i++;
        }
        
        return res.substr(i);
        
        
    }
    
    static bool compare(string &s1, string &s2) {
        return s1 + s2 > s2 + s1;
    }
};