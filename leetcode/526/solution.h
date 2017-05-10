// solution1: 6ms, 15 cases
class Solution {
public:
    int countArrangement(int N) {
        cur_n_ = N;
        flag_.reserve(N);
        for (int i = 1; i <= N; ++i) {
            flag_.push_back(i);
        }

        RecursiveFunc();

        return count_;
    }
private:
    std::vector<int> flag_;
    int count_ = 0;
    int cur_n_;

    void RecursiveFunc() {
        if (cur_n_ == 0) {
            ++count_;
            return;
        }

        --cur_n_;
        int pos = cur_n_ + 1;   // we find pos from n to 1, will make it faster
        for (int i = 0; i <= cur_n_; ++i) {
            if (flag_[i] % pos == 0 || pos % flag_[i] == 0) {
                std::swap(flag_[i], flag_[cur_n_]);
                RecursiveFunc();
                std::swap(flag_[i], flag_[cur_n_]);
            }
        }
        ++cur_n_;
    }
};

// solution2: 72ms, 15 cases
class Solution {
public:
    int countArrangement(int N) {
        max_n_ = N;
        cur_n_ = N;
        flag_.reserve(N);
        for (int i = 1; i <= N; ++i) {
            flag_.push_back(i);
        }

        RecursiveFunc();

        return count_;
    }
private:
    std::vector<int> flag_;
    int count_ = 0;
    int max_n_;
    int cur_n_;

    void RecursiveFunc() {
        if (cur_n_ == 0) {
            ++count_;
            return;
        }

        --cur_n_;
        int pos = max_n_ - cur_n_;  // find pos from 1 to n
        for (int i = 0; i <= cur_n_; ++i) {
            if (flag_[i] % pos == 0 || pos % flag_[i] == 0) {
                std::swap(flag_[i], flag_[cur_n_]);
                RecursiveFunc();
                std::swap(flag_[i], flag_[cur_n_]);
            }
        }
        ++cur_n_;
    }
};

// solution3: 142ms, 15 cases
class Solution {
public:
    int countArrangement(int N) {
        std::vector<bool> flag(N, true);
        max_n_ = N;
        array_.reserve(N);

        RecursiveFunc(flag);

        return count_;
    }
private:
    std::vector<int> array_;
    int count_ = 0;
    int max_n_;

    void RecursiveFunc(std::vector<bool>& flag) {
        if (array_.size() == max_n_) {
            ++count_;
            return;
        }

        int size = array_.size() + 1;
        for (int i = 1; i <= max_n_; ++i) {
            if (flag[i] && (size % i == 0 || i % size == 0)) {
                array_.push_back(i);
                flag[i] = false;
                RecursiveFunc(flag);
                flag[i] = true;
                array_.pop_back();
            }
        }
    }
};