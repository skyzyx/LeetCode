// LeetCode #119: Pascal's Triangle II

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex < 0)
            return res;
            
        res.push_back(1);
        for(int i = 0; i < rowIndex; i++) {
            for (int j = res.size() - 1; j > 0; j--)
                res[j] += res[j-1];
            res.push_back(1);
        }
        return res;
    }
};