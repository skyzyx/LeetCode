// LeetCode #127: Word Ladder

/*
Given two words (beginWord and endWord), and a dictionary, find the length of 
shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

public class Solution {
    public int ladderLength(String beginWord, String endWord, Set<String> wordDict) {
        wordDict.add(endWord);
        
        Queue<String> words = new LinkedList<String>();
        Queue<Integer> hops = new LinkedList<Integer>();
        words.offer(beginWord);
        hops.offer(1);
        
        while (!words.isEmpty()) {
            String currWord = words.poll();
            int currHop = hops.poll();
            
            if (currWord.equals(endWord)) return currHop;
            
            for (int i = 0; i < currWord.length(); i++) {
                char[] currWordArray = currWord.toCharArray();
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == currWordArray[i]) continue;
                    currWordArray[i] = c;
                    String nextWord = String.valueOf(currWordArray);
                    if (wordDict.contains(nextWord)) {
                        words.offer(nextWord);
                        hops.offer(currHop+1);
                        wordDict.remove(nextWord);
                    }
                }
            }
        }
        return 0;
    }
}