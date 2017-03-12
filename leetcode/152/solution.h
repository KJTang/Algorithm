class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int last_max_product = 1;
        int last_min_product = 1;
        int max_product = 1;
        int min_product = 1;
        int result = nums[0];

        for (int i = 0; i != nums.size(); ++i) {
            // compute max & min
            max_product = last_max_product * nums[i];
            min_product = last_min_product * nums[i];
            if (min_product > max_product) {
                int temp = max_product;
                max_product = min_product;
                min_product = temp;
            }
            // update 
            if (result < max_product) {
                result = max_product;
            }
            last_max_product = max_product <= 0 ? 1 : max_product;
            last_min_product = min_product >= 0 ? 1 : min_product;
        }

        return result;
    }
};