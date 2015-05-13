class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        //if (num.size() < 4)
            //return res;
            
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); i++) {
            for (int j = i+1; j < num.size(); j++) {
                int l = j+1;
                int r = num.size() - 1;
                int remain = target - num[i] - num[j];
                
                while (l < r) {
                    if (remain == num[l] + num[r]) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        
                        if (find(res.begin(), res.end(), tmp) == res.end())
                            res.push_back(tmp);
                        
                        l++;
                        r--;
                    } else if (remain > num[l] + num[r]) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};