// solution: 6ms, 22 cases
class Solution {
public:
    vector<vector<string>> partition(string s) {
        Partition(s, 0, s.size() - 1);
        return result_;
    }
private:
    std::vector<std::vector<std::string>> result_;
    std::vector<std::string> cur_;

    bool IsPalindrome(const std::string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void Partition(const std::string& s, int begin, int end) {
        if (begin > end) {
            result_.push_back(cur_);
            return;
        }
        for (int i = end; i >= begin; --i) {
            if (IsPalindrome(s, begin, i)) {
                cur_.push_back(s.substr(begin, i - begin + 1));
                Partition(s, i + 1, end);
                cur_.pop_back();
            }
        }
    }
};