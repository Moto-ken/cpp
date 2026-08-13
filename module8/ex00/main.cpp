
#include <iostream>
#include <vector>

#include "Easyfind.hpp"

int main(void) {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) vec.push_back(i);

    try {
        std::vector<int>::iterator it = easyfind(vec, 11);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}