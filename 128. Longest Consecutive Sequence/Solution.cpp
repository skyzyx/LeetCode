// LeetCode #128: Longest Consecutive Sequence

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0)
            return 0;
            
        int maxLen = 0;
        unordered_set<int> set;
        for (int i = 0; i < num.size(); i++)
            set.insert(num[i]);
            
        for (int i = 0; i < num.size(); i++) {
            if (set.find(num[i]) != set.end()) {
                int left = num[i] - 1;
                int right = num[i] + 1;
                int count = 1;
                
                while (set.find(left) != set.end()) {
                    set.erase(left);
                    left--;
                    count++;
                }
                
                while (set.find(right) != set.end()) {
                    set.erase(right);
                    right++;
                    count++;
                }
                
                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }
};


/* Memory Limit Exceeded
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0)
            return 0;
            
        unordered_map<int, bool> map;
        for (int i; i < num.size(); i++)
            map[num[i]] = false;
            
        int maxLen = 0;
        for (int i = 0; i < num.size(); i++) {
            if (map[num[i]] == false) {
                int left = num[i] - 1;
                int right = num[i] + 1;
                int count = 1;
            
                while (map[left] == false) {
                    map[left] = true;
                    left--;
                    count++;
                }
            
                while (map[right] == false) {
                    map[right] = true;
                    right++;
                    count++;
                }
            
                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }
};
*/