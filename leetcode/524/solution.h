// solution: 109ms, 31 cases
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        for (int i = 0; i != d.size(); ++i) {
            int len = GetLength(s, d[i]);
            if (len > max_len_) {
                cur_str_ = i;
                max_len_ = len;
            } else if (len == max_len_) {
                cur_str_ = d[cur_str_] < d[i] ? cur_str_ : i;
            }
        }
        return cur_str_ == -1 ? "" : d[cur_str_];
    }
private:
    int max_len_ = 0;
    int cur_str_ = -1;

    int GetLength(const std::string& s1, const std::string& s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len2 < max_len_ || len1 < len2) {
            return -1;
        }
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 != len1 && ptr2 != len2) {
            if (s1[ptr1] == s2[ptr2]) {
                ++ptr2;
            }
            ++ptr1;
        }
        return ptr2 == len2 ? len2 : -1;
    }
};