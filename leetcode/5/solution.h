// solution: 6ms
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1;
        int max_start = 0, max_end = 0;
        int str_len = s.size();

        int mid = 0;
        while (mid <= str_len - max_len / 2 - 1) {
            // init
            int start = mid, end = mid + 1;
            while (end <= str_len - 1 && s[end] == s[start]) {
                ++end;
            }
            // increase
            mid = end--;
            // find palindrome
            while (start >= 0 && end <= str_len - 1) {
                if (s[start] == s[end]) {
                    --start;
                    ++end;
                } else {
                    break;
                }
            }
            // count length
            ++start;
            --end;
            if (max_len < end - start + 1) {
                max_len = end - start + 1;
                max_start = start;
                max_end = end;
            }
        }
        return s.substr(max_start, max_len);
    }
};