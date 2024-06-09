class TrieNode {
    public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() {
        isEnd = false;
        children.resize(26);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch-'a'] == NULL) {
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch-'a'] == NULL) {
                return false;
            }
            node = node->children[ch-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children[ch-'a'] == NULL) {
                return false;
            }
            node = node->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */