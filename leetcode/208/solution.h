// solution: 75ms, 14 cases
struct TrieNode {
    char cur;
    bool is_end = false;
    std::vector<TrieNode*> next = std::vector<TrieNode*>(26, nullptr);
    TrieNode(char c = 0) : cur(c) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) {
            return;
        }

        TrieNode* node = &root;
        for (auto c : word) {
            int cur = c - 'a';
            if (node->next[cur] == nullptr) {
                node->next[cur] = new TrieNode(c);
            }
            node = node->next[cur];
        }
        node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = &root;
        for (auto c : word) {
            int cur = c - 'a';
            if (!node->next[cur]) {
                return false;
            }
            node = node->next[cur];
        }
        return node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = &root;
        for (auto c : prefix) {
            int cur = c - 'a';
            if (!node->next[cur]) {
                return false;
            }
            node = node->next[cur];
        }
        return true;
    }

private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */