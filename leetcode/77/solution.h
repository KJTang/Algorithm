// solution1: 75ms, 27 cases
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        cur_.reserve(k);

        Backtracking(0, 0);

        return result_;
    }
private:
    std::vector<int> cur_;
    int n_;
    int k_;
    std::vector<std::vector<int>> result_;

    void Backtracking(int ptr, int level) {
        if (level == k_) {
            result_.push_back(cur_);
            return;
        }

        int max = n_ - (k_ - level) + 1;    // to make it a little faster
        for (int i = ptr + 1; i <= max; ++i) {
            cur_.push_back(i);
            Backtracking(i, level + 1);
            cur_.pop_back();
        }
    }
};

// solution2: 83ms, 27 cases
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        cur_.reserve(k);

        Backtracking(0, 0);

        return result_;
    }
private:
    std::vector<int> cur_;
    int n_;
    int k_;
    std::vector<std::vector<int>> result_;

    void Backtracking(int ptr, int level) {
        if (level == k_) {
            result_.push_back(cur_);
            return;
        }

        for (int i = ptr + 1; i <= n_; ++i) {
            cur_.push_back(i);
            Backtracking(i, level + 1);
            cur_.pop_back();
        }
    }
};
