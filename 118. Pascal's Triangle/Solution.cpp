// LeetCode #118: Pascal's Triangle

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0)
            return res;
            
        vector<int> cur;
        cur.push_back(1);
        res.push_back(cur);
        
        for(int i = 0; i < numRows - 1; i++) {
            for (int j = cur.size() - 1; j > 0; j--) {
                cur[j] += cur[j-1];
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};