class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size(); i++) {
            int l = i+1;
            int r = num.size() - 1;
            int remain = 0 - num[i];
            
            while (l < r) {
                if (remain = num[l] + num[r]) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[l]);
                    tmp.push_back(num[r]);
                    res.push_back(tmp);
                    l++;
                    r--;
                    
                    while (l < r && num[l] == num[l-1])
                        l++;
                        
                    while (l < r && num[r] == num[r+1])
                        r--;
                    
                    if (find(res.begin(), res.end(), tmp) != res.end())
                        res.push_back(tmp);
                } else if (remain > num[l] + num[r]) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};