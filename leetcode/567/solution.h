// solution1: 9ms, 102 cases, https://discuss.leetcode.com/topic/87861/c-java-clean-code-with-explanation
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        // make table
        std::vector<int> table(128, 0);
        for (int i = 0; i != s1.size(); ++i) {
            ++table[s1[i]];
        }
        // check
        int head = 0, tail = 0;
        int count = s1.size();
        while (head < s2.size()) {
            if (table[s2[head]] > 0) {          // if s2[head] belongs to s1
                --count;
            }
            --table[s2[head]];

            while (count == 0) {
                if (head - tail + 1 == s1.size()) {
                    return true;
                }

                ++table[s2[tail]];
                if (table[s2[tail]] > 0) {      // if s2[tail] belongs to s1
                    ++count;
                }
                ++tail;
            }
            ++head;
        }
        return false;
    }
};

// solution2: 92ms, 102 cases
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        // make table
        count = s1.size();
        std::vector<int> table(26, 0);
        for (int i = 0; i < count; ++i) {
            ++table[s1[i] - 'a'];
        }
        // check
        for (int i = 0; i <= s2.size() - count; ++i) {
            if (IsIncluded(s2, i, table)) {
                return true;
            }
        }
        return false;
    }
private:
    int count = 0;

    bool IsIncluded(const std::string& s2, int pos, std::vector<int> table) {
        int cnt = 0;
        for (int i = pos; i != pos + count; ++i) {
            int cur = s2[i] - 'a';
            if (table[cur] == 0) {
                return false;
            } else {
                ++cnt;
                --table[cur];
            }
        }
        return cnt == count;
    }
};