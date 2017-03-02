#include <iostream>
#include <vector>

#include "solution.h"

std::vector<int> nums = {0, 1, 2, 3, 2, 4, 5, 6, 8};
// std::vector<int> nums = {1, 1};

int main() {
    Solution s;
    std::cout << "findDuplicate: " << s.findDuplicate(nums) << std::endl;
    return 0;
}
