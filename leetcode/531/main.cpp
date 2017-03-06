#include <iostream>
#include <vector>

#include "solution.h"

std::vector<std::vector<char>> input = {{'W','W','B'},{'W','B','W'},{'B','W','W'},{'B','W','W'}};

int main() {
    Solution s;
    int output = s.findLonelyPixel(input);
    std::cout << "output: " << output << std::endl;
    return 0;
}

// w w b
// w b w
// b w w
// b w w