// LeetCode #151: Reverse Words in a String

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

public class Solution {
    public String reverseWords(String s) {
        StringBuilder res = new StringBuilder();
        int j = s.length();
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                j = i;
            } else if (i == 0 || s.charAt(i-1) == ' ') {
                if (res.length() != 0)
                    res.append(" ");
                res.append(s.substring(i, j));
            }
        }
        return res.toString();
    }
}

/*
public class Solution {
    public String reverseWords(String s) {
        if (s == null || s.length() == 0)
            return s;
            
        String[] words = s.trim().split(" ");
        StringBuilder res = new StringBuilder();
        
        for (int i = words.length -1; i >=0; i--) {
            if (!words[i].equals("")) {
                if (i == 0)
                    res.append(words[i]);
                else 
                    res.append(words[i] + " ");
            }
        }
        
        return res.toString();
    }
}
*/