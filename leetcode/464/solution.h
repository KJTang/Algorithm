// solution: 119ms, 54 cases
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // boarder check
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int max_sum = (maxChoosableInteger * (maxChoosableInteger + 1)) >> 1;
        if (max_sum < desiredTotal) {
            return false;
        }

        length = maxChoosableInteger + 1;
        return DFS(desiredTotal, ~0 >> (31 - maxChoosableInteger), true);
    }
private:
    int length = 1;
    std::unordered_map<int, bool> cache_1st_;
    std::unordered_map<int, bool> cache_2nd_;

    bool DFS(int total, int flag, bool is_first) {
        if (total <= 0) {
            return !is_first;
        }

        if (is_first) {     // first player
            // cache
            auto it = cache_1st_.find(flag);
            if (it != cache_1st_.end()) {
                return it->second;
            }
            // compute
            bool result = false;
            for (int i = 1, bit = 1; i != length && !result; ++i, bit <<= 1) {
                if (flag & bit) {
                    flag -= bit;
                    result = DFS(total - i, flag, false);
                    flag += bit;
                }
            }

            cache_1st_.insert(std::make_pair(flag, result));
            return result;
        } else {            // second player
            // cache
            auto it = cache_2nd_.find(flag);
            if (it != cache_2nd_.end()) {
                return it->second;
            }
            // compute
            bool result = true;
            for (int i = 1, bit = 1; i != length && result; ++i, bit <<= 1) {
                if (flag & bit) {
                    flag -= bit;
                    result = DFS(total - i, flag, true);
                    flag += bit;
                }
            }

            cache_2nd_.insert(std::make_pair(flag, result));
            return result;
        }
    }
};

// solution: 252ms, 54 cases
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // boarder check
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int max_sum = (maxChoosableInteger * (maxChoosableInteger + 1)) >> 1;
        if (max_sum < desiredTotal) {
            return false;
        }

        length = maxChoosableInteger + 1;
        return DFS(desiredTotal, ~0 >> (31 - maxChoosableInteger), true);
    }
private:
    int length = 1;
    std::map<int, bool> cache_1st_;
    std::map<int, bool> cache_2nd_;

    bool DFS(int total, int flag, bool is_first) {
        if (total <= 0) {
            return !is_first;
        }

        if (is_first) {     // first player
            // cache
            auto it = cache_1st_.find(flag);
            if (it != cache_1st_.end()) {
                return it->second;
            }
            // compute
            bool result = false;
            for (int i = 1, bit = 1; i != length && !result; ++i, bit <<= 1) {
                if (flag & bit) {
                    flag -= bit;
                    result = DFS(total - i, flag, false);
                    flag += bit;
                }
            }

            cache_1st_.insert(std::make_pair(flag, result));
            return result;
        } else {            // second player
            // cache
            auto it = cache_2nd_.find(flag);
            if (it != cache_2nd_.end()) {
                return it->second;
            }
            // compute
            bool result = true;
            for (int i = 1, bit = 1; i != length && result; ++i, bit <<= 1) {
                if (flag & bit) {
                    flag -= bit;
                    result = DFS(total - i, flag, true);
                    flag += bit;
                }
            }

            cache_2nd_.insert(std::make_pair(flag, result));
            return result;
        }
    }
};

// solution: 412ms, 54 cases
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // boarder check
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int max_sum = (maxChoosableInteger * (maxChoosableInteger + 1)) >> 1;
        if (max_sum < desiredTotal) {
            return false;
        }

        std::vector<bool> flag(maxChoosableInteger + 1, true);
        return DFS(desiredTotal, flag, true);
    }
private:
    std::map<int, bool> cache_1st_;
    std::map<int, bool> cache_2nd_;

    int TransBoolArrayToInt(const std::vector<bool>& flag) {
        int result = 0;
        for (int i = 0; i != flag.size(); ++i) {
            result |= flag[i];
            result <<= 1;
        }
        return result;
    }

    bool DFS(int total, std::vector<bool>& flag, bool is_first) {
        if (total <= 0) {
            return !is_first;
        }

        if (is_first) {     // first player
            // cache
            auto it = cache_1st_.find(TransBoolArrayToInt(flag));
            if (it != cache_1st_.end()) {
                return it->second;
            }
            // compute
            bool result = false;
            for (int i = 1; i != flag.size() && !result; ++i) {
                if (flag[i]) {
                    flag[i] = false;
                    result = DFS(total - i, flag, false);
                    flag[i] = true;
                }
            }

            cache_1st_.insert(std::make_pair(TransBoolArrayToInt(flag), result));
            return result;
        } else {            // second player
            // cache
            auto it = cache_2nd_.find(TransBoolArrayToInt(flag));
            if (it != cache_2nd_.end()) {
                return it->second;
            }
            // compute
            bool result = true;
            for (int i = 1; i != flag.size() && result; ++i) {
                if (flag[i]) {
                    flag[i] = false;
                    result = DFS(total - i, flag, true);
                    flag[i] = true;
                }
            }

            cache_2nd_.insert(std::make_pair(TransBoolArrayToInt(flag), result));
            return result;
        }
    }
};