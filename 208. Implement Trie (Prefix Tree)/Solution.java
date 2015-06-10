// LeetCode #208: Implement Trie (Prefix Tree)

/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

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

public class Trie {
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

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");