// LeetCode #186: Reverse Words in a String II

/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
*/

class Solution {
public:
    void reverseWords(string &s) {
        reverseString(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                int j = i;
                while (j < s.size() && s[j] != ' ')
                    j++;
                    
                reverseString(s, i, j-1);
                i = j;
            }
        }
    }
    
private:
    void reverseString(string &s, int i, int j) { // NOT string s, int i, int j
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            
            i++;
            j--;
        }
    }
};