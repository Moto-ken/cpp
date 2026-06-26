
#include "iter.hpp"

template <typename T>
void printConst(const T& value) {
    std::cout << value << std::endl;
}

template <typename T>
void print(T& value) {
    std::cout << value << std::endl;
}

int main(void) {
    int arr[] = {1, 2, 3};

    iter(arr, 3, printConst<int>);
    iter(arr, 3, print<int>);

    return 0;
}
