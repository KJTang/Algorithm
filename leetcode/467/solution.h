// solution:    https://discuss.leetcode.com/topic/70654/c-concise-solution/2
//              http://blog.csdn.net/mebiuw/article/details/53469963
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        std::vector<int> letters(26, 0);
        int res = 0, len = 0;
        for (int i = 0; i != p.size(); i++) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') {
                len = 0;
            }
            if (++len > letters[cur]) {     // if string end by (cur + 'a') whose length bigger than record
                res += len - letters[cur];
                letters[cur] = len;
            }
        }
        return res;
    }
};