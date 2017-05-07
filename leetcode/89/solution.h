// solution1: 3ms, 12 cases, http://www.cnblogs.com/ganganloveu/p/4146821.html
class Solution {
public:
    vector<int> grayCode(int n) {
        std::vector<int> result(1, 0);
        for(int i = 0; i != n; ++i) {
            for(int j = result.size() - 1; j >= 0; --j) {
                int num = result[j];
                num += 1 << i;
                result.push_back(num);
            }
        }
        return result;
    }
};

// solution2: result is different from solution1, but it's also correct answer
class Solution {
public:
    vector<int> grayCode(int n) {
        n_ = 1 << n;    // n_ = std::pow(2, n);
        std::vector<bool> flag(n_, true);

        cur_.reserve(n_);
        cur_.push_back(0);
        flag[0] = false;

        Backtracking(0, flag);

        return result_;
    }
private:
    std::vector<int> cur_;
    std::vector<int> result_;
    int n_;

    bool IsDifferByOneBit(int a, int b) {
        int tmp = a xor b;
        return a == b ? false : (!(tmp & (tmp - 1)));
    }

    bool Backtracking(int ptr, std::vector<bool>& flag) {
        if (cur_.size() == n_) {
            result_ = cur_;
            return true;
        }

        for (int i = 1; i != n_; ++i) {
            if (flag[i] && IsDifferByOneBit(ptr, i)) {
                cur_.push_back(i);
                flag[i] = false;

                if (Backtracking(i, flag)) {
                    return true;
                }
                
                flag[i] = true;
                cur_.pop_back();
            }
        }
        return false;
    }
};