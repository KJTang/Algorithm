class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        max_k = k;
        max_n = n;
        RecursiveCombine(1, 0, 0);
        return result;
    }
private:
    int max_k;
    int max_n;

    std::vector<std::vector<int>> result;
    std::vector<int> arr;

    void RecursiveCombine(int k, int n, int last) {
        if (k == max_k + 1) {
            return;
        }
        for (int i = last + 1; i != 10; ++i) {
            if (n + i == max_n && k == max_k) {
                arr.push_back(i);
                result.push_back(arr);
                arr.pop_back();
                return;
            } else if (n + i >= max_n) {
                return;
            } else {
                arr.push_back(i);
                RecursiveCombine(k + 1, n + i, i);
                arr.pop_back();
            }
        }
    }
};