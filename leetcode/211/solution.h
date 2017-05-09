/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

// solution: 105ms, 13 cases
struct Node {
    char ch;
    bool is_end;
    std::vector<Node*> children;
    Node() {
        is_end = false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root_ = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = root_;
        int ptr = 0;
        while (ptr != word.size()) {
            bool found = false;
            for (auto it = node->children.begin(); it != node->children.end(); ++it) {
                if ((*it)->ch == word[ptr]) {
                    found = true;
                    node = *it;
                    ++ptr;
                    break;
                }
            }
            if (!found) {
                Node* new_node = new Node();
                new_node->ch = word[ptr];
                node->children.push_back(new_node);
                node = new_node;
                ++ptr;
            }
        }
        node->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return BacktrackingSearch(word, 0, root_);
    }
private:
    Node* root_;

    bool BacktrackingSearch(const std::string& word, int ptr, Node* node) {
        if (ptr == word.size()) {
            return node->is_end;
        }

        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            if (word[ptr] == '.' || word[ptr] == (*it)->ch) {
                if (BacktrackingSearch(word, ptr + 1, (*it))) {
                    return true;
                }
            }
        }
        return false;
    }
};

// solution2: 85ms, 13 cases, use more space to make it faster
#include <cstring>

struct Node {
    char ch;
    bool is_end;
    bool flag[26];
    Node* children[26];
    Node() {
        std::memset(flag, false, sizeof(bool) * 26);
        is_end = false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root_ = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* node = root_;
        int ptr = 0;
        while (ptr != word.size()) {
            int id = word[ptr] - 'a';
            if (!node->flag[id]) {
                node->flag[id] = true;
                node->children[id] = new Node();
                node->children[id]->ch = word[ptr];
            }
            node = node->children[id];
            ++ptr;
        }
        node->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return BacktrackingSearch(word, 0, root_);
    }
private:
    Node* root_;

    bool BacktrackingSearch(const std::string& word, int ptr, Node* node) {
        if (ptr == word.size()) {
            return node->is_end;
        }

        if (word[ptr] == '.') {
            for (int i = 0; i != 26; ++i) {
                if (node->flag[i] && BacktrackingSearch(word, ptr + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int id = word[ptr] - 'a';
            return node->flag[id] && BacktrackingSearch(word, ptr + 1, node->children[id]);
        }
    }
};