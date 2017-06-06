// solution: 116ms, 44 cases, (time: O(n), space: O(1)), http://blog.csdn.net/qq508618087/article/details/51337187
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        length_ = nums.size();
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());  

        int low = 0, high = length_ - 1;
        int mid = nums[length_ / 2];

        int i = 0;
        while (i <= high) { 
            if (nums[GetIndex(i)] > mid) {
                std::swap(nums[GetIndex(i++)], nums[GetIndex(low++)]);
            } else if (nums[GetIndex(i)] < mid) {
                std::swap(nums[GetIndex(i)], nums[GetIndex(high--)]);  
            } else {
                i++;  
            }
        }
    }
private:
    int length_ = 0;

    // get virtual index
    inline int GetIndex(int pos) {
        return ((pos << 1) + 1) % (length_ | 1);
    }
};

// solution: 92ms, 44 cases, (time: O(n), space: O(n)), http://blog.csdn.net/qq508618087/article/details/51337187
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        length_ = nums.size();
        std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());  

        int low = 0, high = length_ - 1;
        int mid = nums[length_ / 2];

        std::vector<int> index(length_);
        int boundry = length_ | 1;
        for (int i = 0; i != length_; ++i) {
            int j = (i << 1) + 1;
            if (j >= boundry) {
                j -= boundry;
            }
            index[i] = j;
        }

        std::cout << "index:";
        for (int i = 0; i != length_; ++i) {
            std::cout << " " << index[i];
        }
        std::cout << std::endl;

        for (int i = 0; i <= high; ) {
            if (nums[index[i]] > mid) {
                std::swap(nums[index[i++]], nums[index[low++]]);
            } else if (nums[index[i]] < mid) {
                std::swap(nums[index[i]], nums[index[high--]]);  
            } else {
                i++;  
            }
        }
    }
private:
    int length_ = 0;
};
