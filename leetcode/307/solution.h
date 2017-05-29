/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

// solution: 116ms, 10 cases, segment tree
class SegmentTree {
public:
    SegmentTree(const std::vector<int>& nums) : nums_count(nums.size()) {
        if (nums.empty()) {
            return;
        }
        // malloc
        int size = 1;
        while (size < nums.size()) {
            size <<= 1;
        }
        size <<= 1;
        nodes_.resize(size, 0);
        // build
        Build(0, nums, 0, nums.size() - 1);
    }

    ~SegmentTree() {}

    void Update(int update_id, int value) {
        Update(0, update_id, value, 0, nums_count - 1);
    }

    int GetSum(int i, int j) {
        return GetSum(i, j, 0, nums_count - 1);
    }

    int GetValue(int i) {
        return GetValue(0, i, 0, nums_count - 1);
    }
    
private:
    std::vector<int> nodes_;
    int nums_count = 1;

    void Build(int cur, const std::vector<int>& nums, int begin, int end) {
        if (begin == end) {
            nodes_[cur] = nums[begin];
            return;
        }

        int left = (cur << 1) + 1;
        int right = (cur << 1) + 2;

        Build(left, nums, begin, (begin + end) / 2);
        Build(right, nums, (begin + end) / 2 + 1, end);

        nodes_[cur] = nodes_[left] + nodes_[right];
    }

    int Update(int cur, int update_id, int value, int begin, int end) {
        if (begin == end) {
            int increment = value - nodes_[cur];
            nodes_[cur] = value;
            return increment;
        }

        int increment = 0;
        int mid = (begin + end) / 2;
        if (update_id <= mid) {
            increment = Update((cur << 1) + 1, update_id, value, begin, mid);
        } else {
            increment = Update((cur << 1) + 2, update_id, value, mid + 1, end);
        }

        nodes_[cur] += increment;
        return increment;
    }

    int GetSum(int i, int j, int begin, int end) {
        return i == 0 ? GetValue(j) : GetValue(j) - GetValue(i - 1);
    }

    int GetValue(int cur, int value_id, int begin, int end) {
        if (begin == end) {
            return nodes_[cur];
        }

        int mid = (begin + end) / 2;
        if (value_id <= mid) {
            return GetValue((cur << 1) + 1, value_id, begin, mid);
        } else {
            return nodes_[(cur << 1) + 1] + GetValue((cur << 1) + 2, value_id, mid + 1, end);
        }
    }
};

class NumArray {
public:
    NumArray(vector<int> nums) : seg_tree_(SegmentTree(nums)) {}
    
    void update(int i, int val) {
        seg_tree_.Update(i, val);
    }
    
    int sumRange(int i, int j) {
        return seg_tree_.GetSum(i, j);
    }
private:
    SegmentTree seg_tree_;
};


// solution: 752ms, 10 cases
class NumArray {
public:
    NumArray(vector<int> nums) : nums_(nums) {
        
    }
    
    void update(int i, int val) {
        nums_[i] = val;
    }
    
    int sumRange(int i, int j) {
        int result = 0;
        while (i <= j) {
            result += nums_[i];
            ++i;
        }
        return result;
    }
private:
    std::vector<int> nums_;
};


// solution: tle
class NumArray {
public:
    NumArray(vector<int> nums) {
        sums_.resize(nums.size() + 1);
        sums_[0] = 0;
        for (int i = 0; i != nums.size(); ++i) {
            sums_[i + 1] = sums_[i] + nums[i];
        }
    }
    
    void update(int i, int val) {
        int offset = val - (sums_[i + 1] - sums_[i]);
        sums_[++i] += offset;
        while (i != sums_.size()) {
            sums_[i] += offset;
            ++i;
        }
    }
    
    int sumRange(int i, int j) {
        return sums_[j + 1] - sums_[i];
    }
private:
    std::vector<int> sums_;
};