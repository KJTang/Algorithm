// solution: 79ms, 32 cases, http://yuanhsh.iteye.com/blog/2185976
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) {
            return {};
        }
        
        std::map<int, int>  substrs;
        std::vector<std::string> result;
        int str_mask = 0;
        // first 10 characters
        for (int i = 0; i != 10; ++i) {
            str_mask = (str_mask << 3) | (s[i] & 7);
        }
        ++substrs[str_mask];
        // other characters
        for (int i = 10; i != s.size(); ++i) {
            // get cur substr(s[i-9 to i])'s mask
            str_mask = ((str_mask << 3) | (s[i] & 7)) & 0x3fffffff;
            auto it = substrs.find(str_mask);
            if (it != substrs.end() && it->second == 1) {   // count == 1: make sure there's no duplicate
                result.push_back(s.substr(i - 9, 10));
            }
            ++substrs[str_mask];
        }
        return result;
    }
};