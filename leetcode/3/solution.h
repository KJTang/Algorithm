// solution1: 9ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> flag(256, -1);
        int max_length = 0;
        for (int head = -1, tail = 0; tail != s.size(); ++tail) {
            int cur = s[tail];
            if (flag[cur] > head) {
                head = flag[cur];
            }
            flag[cur] = tail;
            max_length = std::max(max_length, tail - head);
        }
        return max_length;
    }
};

// solution2: 29ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        flag.fill(-1);
        int head = 0, tail = 0;
        for (; tail != s.size(); ++tail) {
            int cur = s[tail];
            if (flag[cur] != -1) {
                int new_head = flag[cur] + 1;
                for (; head != new_head; ++head) {
                    flag[s[head]] = -1;
                    --cur_length;
                }
            }
            flag[cur] = tail;
            ++cur_length;
            if (cur_length > max_length) {
                max_length = cur_length;
            }
        }
        return max_length;
    }
private:
    int max_length = 0;
    int cur_length = 0;
    std::array<int, 256> flag;
};