#include <iostream>
#include <vector>

#include "solution.h"

std::vector<int> input = {1,2,2,3,2,1,1,3};
std::vector<int> output;

int main() {
    Solution s;
    output = s.majorityElement(input);
    for (int i = 0; i != output.size(); ++i) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
}