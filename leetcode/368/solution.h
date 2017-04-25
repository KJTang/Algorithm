// solution1: 39ms, 36 cases
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        
        std::vector<int> len_cache(nums.size(), -1);    // len_cache[i]: if add nums[i], the max size the subset can exceed
        std::vector<int> num_cache(nums.size(), -1);    // num_cache[i]: if add nums[i], which num add next can exceed max size

        std::sort(nums.begin(), nums.end());
        // DP
        int max_len = 0;
        int max_num = 0;
        for (int i = 0; i != nums.size(); ++i) {
            int temp = DP(nums, i, len_cache, num_cache);
            if (temp > max_len) {
                max_len = temp;
                max_num = i;
            }
        }
        ++max_len;
        // get result
        std::vector<int> result;
        int cur = max_num;
        while (cur != -1) {
            result.push_back(nums[cur]);
            cur = num_cache[cur];
        }
        return result;
    }
private:
    int DP(const std::vector<int>& nums, int cur, std::vector<int>& len_cache, std::vector<int>& num_cache) {
        if (len_cache[cur] == -1) {
            for (int i = cur + 1; i < nums.size(); ++i) {
                if (nums[i] % nums[cur] == 0) {
                    int temp = DP(nums, i, len_cache, num_cache);
                    if (temp > len_cache[cur]) {
                        len_cache[cur] = temp;
                        num_cache[cur] = i;
                    }
                }
            }
            ++len_cache[cur];
        }
        return len_cache[cur];
    }
};

// solution2: 59ms, 36 cases
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        
        std::vector<std::vector<int>> pointers(nums.size());
        std::vector<int> len_cache(nums.size(), -1);    // len_cache[i]: if add nums[i], the max size the subset can exceed
        std::vector<int> num_cache(nums.size(), -1);    // num_cache[i]: if add nums[i], which num add next can exceed max size

        std::sort(nums.begin(), nums.end());
        // generate pointers
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = i + 1; j != nums.size(); ++j) {
                if (nums[j] % nums[i] == 0) {
                    pointers[i].push_back(j);
                }
            }
        }
        // DP
        int max_len = 0;
        int max_num = 0;
        for (int i = 0; i != nums.size(); ++i) {
            int temp = DP(nums, pointers, i, len_cache, num_cache);
            if (temp > max_len) {
                max_len = temp;
                max_num = i;
            }
        }
        ++max_len;
        // get result
        std::vector<int> result;
        int cur = max_num;
        while (cur != -1) {
            result.push_back(nums[cur]);
            cur = num_cache[cur];
        }
        return result;
    }
private:
    int DP(const std::vector<int>& nums, const std::vector<std::vector<int>>& pointers, int cur, std::vector<int>& len_cache, std::vector<int>& num_cache) {
        if (len_cache[cur] == -1) {
            for (auto it = pointers[cur].begin(); it != pointers[cur].end(); ++it) {
                int temp = DP(nums, pointers, *it, len_cache, num_cache);
                if (temp > len_cache[cur]) {
                    len_cache[cur] = temp;
                    num_cache[cur] = *it;
                }
            }
            ++len_cache[cur];
        }
        return len_cache[cur];
    }
};