// LeetCode #211: Add and Search Word - Data structure design

/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/

class TrieNode {
    boolean isKey;
    TrieNode[] children;
    public TrieNode() {
        isKey = false;
        children = new TrieNode[26];
        for (int i = 0; i < 26; i++)
            children[i] = null;
    }
}

public class WordDictionary {
    private TrieNode root;
    
    public WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    public void addWord(String word) {
        TrieNode curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr.children[word.charAt(i) - 'a'] == null)
                curr.children[word.charAt(i) - 'a'] = new TrieNode();
            curr = curr.children[word.charAt(i) - 'a'];
        }
        curr.isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        return dfs(root, word, 0);
    }
    
    private boolean dfs(TrieNode node, String word, int count) {
        if (count == word.length())
            return node.isKey == true;
            
        if (word.charAt(count) == '.') {
            for (int i = 0; i < 26; i++)
                if (node.children[i] != null && dfs(node.children[i], word, count+1))
                    return true;
            return false;
        } else {
            return node.children[word.charAt(count) - 'a'] != null && dfs(node.children[word.charAt(count) - 'a'], word, count+1);
        }
    }
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");