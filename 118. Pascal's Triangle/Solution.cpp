// https://helloacm.com/c-coding-exercise-pascals-triangle/

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