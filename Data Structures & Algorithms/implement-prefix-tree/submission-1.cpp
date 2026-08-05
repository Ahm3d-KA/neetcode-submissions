class TrieNode {
public:
    bool endOfWord = false;
    TrieNode* children[26]{};
};
class PrefixTree {
private:
    TrieNode* root = new TrieNode();


public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->endOfWord;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};
