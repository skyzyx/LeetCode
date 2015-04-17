class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int, int> map;
        for (int i = 0; i < num.size(); i++) {
            if (map.find(num[i]) == map.end())
                map[num[i]] = 0; // Why not map[num[i]] = 1
            else
                map[num[i]] += 1;
                
            if (map[num[i]] >= num.size() / 2)
                return num[i];
        }
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majorIndex = 0;
        int majorCount = 1;
        
        for (int i = 1; i < num.size(); i++) {
            if (num[majorIndex] == num[i])
                majorCount += 1;
            else
                majorCount -= 1;
                
            if (majorCount == 0) {
                majorCount = 1;
                majorIndex = i;
            }
        }
        
        return num[majorIndex];
    }
};
*/