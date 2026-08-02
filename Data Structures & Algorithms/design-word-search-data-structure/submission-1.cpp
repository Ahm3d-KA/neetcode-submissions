class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
    TrieNode* root;
private:
    bool h_search(string word, TrieNode* cur) {
        if (word.empty() && cur->endOfWord) return true;
        for (int i=0; i<word.length(); i++) {
            if (word[i] == '.') {
                bool found = false;
                for (auto [_, ch] : cur->children) {
                    found |= h_search({word.begin()+i+1, word.end()}, ch);

                }
                return found;
            }
            else if (cur->children.find(word[i]) == cur->children.end()) {
                return false;
            }
            cur = cur->children[word[i]];
        }
        return cur->endOfWord;

    }

public:
    WordDictionary() {
        root = new TrieNode();
        
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
        
    }
    
    bool search(string word) {
        return h_search(word, root);
    }

};
