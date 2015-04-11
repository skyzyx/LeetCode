class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> mymap;
        vector<int> res;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (mymap.find(numbers[i]) == mymap.end()) {
                mymap[target - numbers[i]] = i+1;
            } else {
                res.push_back(mymap[numbers[i]]);
                res.push_back(i+1);
                break;
            }
        }
        return res;
    }
};