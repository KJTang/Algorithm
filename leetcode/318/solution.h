// solution: 39ms, 174 cases
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int total_size = words.size();
        // trans string into int
        std::vector<int> word_mask(total_size);
        for (int i = 0; i != total_size; ++i) {
            int mask = 0;
            for (int j = 0; j != words[i].size(); ++j) {
                mask |= mask_list[words[i][j] - 'a'];
            }
            word_mask[i] = mask;
        }
        // use int bit manipulation to compare strings
        int max_product = 0;
        for (int i = 0; i != total_size - 1; ++i) {
            int temp = 0;
            for (int j = i + 1; j != total_size; ++j) {
                if (!(word_mask[i] & word_mask[j])) {
                    temp = std::max(temp, (int)(words[i].size() * words[j].size()));
                }
            }
            max_product = std::max(max_product, temp);
        }
        return max_product;
    }
private:
    std::vector<int> mask_list = {
        1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 
        1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 
        1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23, 
        1 << 24, 1 << 25 
    };
};