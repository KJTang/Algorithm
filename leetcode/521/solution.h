class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() == b.size()) {
            return (a == b ? -1 : a.size());
        } else {
            return std::max(a.size(), b.size());
        }
    }
};