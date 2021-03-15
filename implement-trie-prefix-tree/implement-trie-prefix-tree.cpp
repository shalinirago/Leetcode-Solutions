class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        trie.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (trie.find(word) == trie.end())
            trie.insert(word);
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (trie.find(word) != trie.end())
            return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for (auto x: trie)
        {
            if (prefix == x.substr(0, prefix.size()))
                return true;
        }
        
        return false;
    }
private:
    set<string> trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */