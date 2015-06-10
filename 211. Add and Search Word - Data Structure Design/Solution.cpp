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
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
 
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->children[word[i] - 'a'] == NULL)
                curr->children[word[i] - 'a'] = new TrieNode();
            curr = curr->children[word[i] - 'a'];
        }
        curr->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, root, 0);
    }
    
private:
    TrieNode* root;
    
    bool dfs(string word, TrieNode* node, int count) {
        if (count == word.size())
            return node->isKey == true;
            
        if (word[count] == '.') {
            for (int i = 0; i < 26; i++)
                if (node->children[i] && dfs(word, node->children[i], count+1))
                    return true;
            return false;
        } else {
            return node->children[word[count] - 'a'] && dfs(word, node->children[word[count] - 'a'], count+1);
        }
    }

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");