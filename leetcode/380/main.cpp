#include <iostream>
#include "randomized_set.h"

int main() {
    RandomizedSet obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.remove(3);
    obj.remove(3);
    obj.insert(3);
    std::cout << (int)obj.getRandom() << std::endl;
    std::cout << (int)obj.getRandom() << std::endl;
    std::cout << (int)obj.getRandom() << std::endl;
    obj.insert(4);
    std::cout << (int)obj.getRandom() << std::endl;
    std::cout << (int)obj.getRandom() << std::endl;
    obj.insert(5);
    std::cout << (int)obj.getRandom() << std::endl;
    std::cout << (int)obj.getRandom() << std::endl;
    return 0;
}