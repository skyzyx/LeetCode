class TrieNode {
public:
    // Initialize your data structure here.
    bool isKey;
    TrieNode* children[26];
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* curr = root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->children[s[i] - 'a'] == NULL) {
                curr->children[s[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->isKey = true;
        
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* curr = root;
        for (int i = 0; i < key.size(); i++) {
            if (curr != NULL) {
                curr = curr->children[key[i] - 'a'];
            } else {
                break;
            }
        }
        
        if (curr == NULL)
            return false;
        return curr->isKey == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr != NULL)
                curr = curr->children[prefix[i] - 'a'];
            else
                break;
        }
        
        if (curr == NULL)
            return false;
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");