#include <string>
using std::string;

class Solution {
public:
    void reverseWords(string &s) {
        // reverse string
        int space = 0;
        bool duplicate = true;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == ' ') {
                if (duplicate) {
                    ++space;
                } else {
                    duplicate = true;
                }
                continue;
            }
            duplicate = false;
            std::swap(s[i - space], s[i]);
        }
        s.resize(s.size() - space);        
        if (s.back() == ' ') {
            s.pop_back();
        }
        swap_str(s, 0, s.size() - 1);

        // reverse every word
        s.push_back(' ');
        for (int head = 0, tail = 0; tail != s.size(); ++tail) {
            if (s[tail] != ' ') {
                continue;
            }
            swap_str(s, head, tail - 1);
            head = tail + 1;
        }
        s.pop_back();
    }
private:
    void swap_str(std::string& s, int head, int tail) {
        while (head < tail) {
            std::swap(s[head], s[tail]);
            ++head;
            --tail;
        }
    }
};