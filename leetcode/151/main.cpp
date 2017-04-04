#include <iostream>
#include "solution.h"

int main() {
    Solution s;
    std::string str("  He  llo     worl d   ");
    std::cout << "|" << str << "|" << std::endl;
    s.reverseWords(str);
    std::cout << "|" << str << "|" << std::endl;
    return 0;
}