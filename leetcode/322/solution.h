// solution: DP, 29ms, 182 cases
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX_COUNT = amount + 1;
        std::vector<int> cache(amount + 1, MAX_COUNT);
        cache[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (i >= coin) {
                    cache[i] = std::min(cache[i], cache[i - coin] + 1);
                }
            }
        }

        return cache[amount] >= MAX_COUNT ? -1 : cache[amount];
    }
};


// solution: DP, tle
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> cache(amount + 1, INT_MAX);
        cache[0] = 0;
        DP(coins, amount, cache);
        return cache[amount] == INT_MAX ? -1 : cache[amount];
    }
private:
    int DP(const std::vector<int>& coins, int amount, std::vector<int>& cache) {
        if (amount == 0) {
            return 0;
        }

        // hit cache
        if (cache[amount] != INT_MAX) {
            return cache[amount];
        }
        // miss
        int min = INT_MAX;
        int cur = 0;
        for (auto coin : coins) {
            if (coin <= amount) {
                cur = DP(coins, amount - coin, cache);
                if (cur < min) {
                    min = cur;
                }
            }
        }

        if (min != INT_MAX) {
            return cache[amount] = min + 1;
        } else {
            return INT_MAX;
        }
    }
};