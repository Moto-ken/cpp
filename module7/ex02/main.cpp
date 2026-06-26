
#include <iostream>

#include "Array.hpp"

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); i++) arr[i] = a[i];

    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;

    try {
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[6] << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
