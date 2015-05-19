class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (int i = 0, j = 0; i < version1.size() || j < version2.size(); i++, j++) {
            int data1 = 0, data2 = 0;
            while (i < version1.size() && version1[i] != '.')
                data1 = data1 * 10 + (version1[i++] - '0'); 
                
            while (j < version2.size() && version2[j] != '.')
                data2 = data2 * 10 + (version2[j++] - '0');
                
            if (data1 > data2)
                return 1;
            if (data1 < data2)
                return -1;
        }
        return 0; 
    }
};