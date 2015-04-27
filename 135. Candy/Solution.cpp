class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0)
            return 0;
            
        vector<int> res;
        for (int i = 0; i < ratings.size(); i++)
            res.push_back(1);
            
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1])
                res[i] = res[i-1] + 1;
        }
        
        int candyNums = 0;
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && res[i] <= res[i+1])
                res[i] = res[i+1] + 1;
                
            candyNums += res[i];
        }
        candyNums += res[res.size() - 1];
        return candyNums;
    }
};