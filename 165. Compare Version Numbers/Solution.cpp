// LeetCode #165: Compare Version Numbers

/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

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