// solution: 6ms, 34 cases
struct Node {
    char cur;
    bool is_end = false;
    std::vector<Node*> children = std::vector<Node*>(26, nullptr);
    
    Node(char c = 'a') : cur(c) {}
};

class TrieTree {
public:
    TrieTree() {}
    ~TrieTree() {
        // TODO: free memory
    }
    
    void Insert(const std::string& word) {
        if (word.empty()) {
            return;
        }
        Node* node = &root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new Node(c - 'a');
            }
            node = node->children[c - 'a'];
        }
        node->is_end = true;
    }

    // optimized for this problem
    bool Find(const std::string& word, int start, int end) {
        Node* node = &root;
        for (int i = start; i <= end; ++i) {
            char c = word[i];
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->is_end;
    }
private:
    Node root;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return false;
        }

        // create dict
        for (auto& word : wordDict) {
            dict_.Insert(word);
        }
        // create cache
        cache_.assign(s.size(), -1);
    
        return DFS(s, 0);
    }
private:
    TrieTree dict_;
    std::vector<int> cache_;

    bool DFS(const std::string& s, int cur) {
        if (cur >= s.size()) {
            return true;
        }
        // cache hit
        if (cache_[cur] != -1) {
            return cache_[cur] == 1;
        }
        // cache miss
        for (int i = cur; i != s.size(); ++i) {
            if (dict_.Find(s, cur, i) && DFS(s, i + 1)) {
                return cache_[cur] = 1;
            }
        }
        return cache_[cur] = 0;
    }
};