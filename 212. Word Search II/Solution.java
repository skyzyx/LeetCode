// LeetCode #212: Word Search II

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not be 
used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.

You would need to optimize your backtracking to pass the larger test. Could you stop 
backtracking earlier?

If the current candidate does not exist in all words' prefix, 
you could stop backtracking immediately. What kind of data structure 
could answer such query efficiently? Does a hash table work? Why or why not? 
How about a Trie? If you would like to learn how to implement a basic trie, 
please work on this problem: Implement Trie (Prefix Tree) first.
*/

public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<String>();
        
        Trie myTrie = new Trie();
        for (String word: words)
            myTrie.insert(word);
            
        int m = board.length;
        int n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, visited, res, i, j, "", myTrie);
                 
        return res;
    }
    
    private void dfs(char[][] board, boolean[][] visited, List<String> res, int i, int j, String s, Trie myTrie) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || visited[i][j] == true)
            return;
            
        s += board[i][j];
        if (!myTrie.startsWith(s)) 
            return;
        
        if (myTrie.search(s))
            if (!res.contains(s))
                res.add(s);
        
        visited[i][j] = true;
        dfs(board, visited, res, i-1, j, s, myTrie);
        dfs(board, visited, res, i+1, j, s, myTrie);
        dfs(board, visited, res, i, j-1, s, myTrie);
        dfs(board, visited, res, i, j+1, s, myTrie);
        visited[i][j] = false;
    }
}

class TrieNode {
    // Initialize your data structure here.
    boolean isKey;
    TrieNode[] children;
    public TrieNode() {
        isKey = false;
        children = new TrieNode[26];
        for (int i = 0; i < 26; i++)
            children[i] = null;
    }
}

class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr.children[word.charAt(i) - 'a'] == null)
                curr.children[word.charAt(i) - 'a'] = new TrieNode();
            curr = curr.children[word.charAt(i) - 'a'];
        }
        curr.isKey = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr != null)
                curr = curr.children[word.charAt(i) - 'a'];
            else
                break;
        }
        
        if (curr == null)
            return false;
        return curr.isKey == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (curr != null)
                curr = curr.children[prefix.charAt(i) - 'a'];
            else
                break;
        }
        
        if (curr == null)
            return false;
        return true;
    }
}
