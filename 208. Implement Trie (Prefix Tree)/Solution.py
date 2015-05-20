class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.isKey = False
        self.children = [None] * 26

class Trie:

    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Inserts a word into the trie.
    def insert(self, word):
        curr = self.root
        for i in xrange(len(word)):
            index = ord(word[i]) - ord('a')
            if curr.children[index] == None:
                curr.children[index] = TrieNode()
            curr = curr.children[index]
        curr.isKey = True
        
    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the trie.
    def search(self, word):
        curr = self.root # NameError: global name 'root' is not defined
        for i in xrange(len(word)):
            if curr != None:
                curr = curr.children[ord(word[i]) - ord('a')]
            else:
                break
            
        if curr == None:
            return False
        return curr.isKey == True

    # @param {string} prefix
    # @return {boolean}
    # Returns if there is any word in the trie
    # that starts with the given prefix.
    def startsWith(self, prefix):
        curr = self.root
        for i in xrange(len(prefix)):
            if curr != None:
                curr = curr.children[ord(prefix[i]) - ord('a')]
            else:
                break
            
        if curr == None:
            return False
        return True

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")