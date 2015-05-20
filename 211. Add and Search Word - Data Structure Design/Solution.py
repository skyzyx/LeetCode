class TrieNode:
    def __init__(self):
        self.isKey = False
        self.children = [None] * 26

class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    # @param {string} word
    # @return {void}
    # Adds a word into the data structure.
    def addWord(self, word):
        curr = self.root
        for i in xrange(len(word)):
            index = ord(word[i]) - ord('a')
            if curr.children[index] == None:
                curr.children[index] = TrieNode()
            curr = curr.children[index]
        curr.isKey = True
        

    # @param {string} word
    # @return {boolean}
    # Returns if the word is in the data structure. A word could
    # contain the dot character '.' to represent any one letter.
    def search(self, word):
        curr = self.root
        return self.dfs(curr, word, 0)
        
    def dfs(self, node, word, count):
        if count == len(word):
            return node.isKey == True
            
        if word[count] == '.':
            for i in xrange(26):
                if node.children[i] != None and self.dfs(node.children[i], word, count+1):
                    return True
            return False
        else:
            index = ord(word[count]) - ord('a')
            return node.children[index] != None and self.dfs(node.children[index], word, count+1)
        

# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")