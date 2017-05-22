// solution1: 66ms, 15 cases
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> result(num + 1, 0);
        result[0] = 0;
        result[1] = 1;

        for (int i = 2; i <= num; ++i) {
            result[i] = (i & 1) + result[i >> 1];
        }
        return result;
    }
};

// solution2: 83ms, 15 cases
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> cache(num + 1, -1);
        cache[0] = 0;
        cache[1] = 1;
        
        std::vector<int> result(num + 1);
        for (int i = 0; i <= num; ++i) {
            result[i] = DP(i, cache);
        }
        return result;
    }
private:
    int DP(int num, std::vector<int>& cache) {
        if (cache[num] == -1) {
            cache[num] = (num & 1) + DP(num >> 1, cache);
        }
        return cache[num];
    }
};