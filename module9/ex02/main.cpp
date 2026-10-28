#include <iomanip>

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        if (!PmergeMe::isValidNumber(argv[i])) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    int n = argc - 1;

    std::cout << "Before:";
    for (int i = 1; i < argc; ++i) std::cout << " " << std::atoi(argv[i]);
    std::cout << std::endl;

    PmergeMe pm;
    std::vector<int> vec;
    std::deque<int> deq;
    double vecTime = pm.measure(vec, argv + 1, n);
    std::size_t vecComp = pm.getComparisons();
    double deqTime = pm.measure(deq, argv + 1, n);
    std::size_t deqComp = pm.getComparisons();

    std::cout << "After: ";
    for (std::size_t i = 0; i < vec.size(); ++i) std::cout << " " << vec[i];
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << n
              << " elements with std::vector : " << vecTime << " us"
              << std::endl;
    std::cout << "Time to process a range of " << n
              << " elements with std::deque  : " << deqTime << " us"
              << std::endl;

    std::size_t maxComp = PmergeMe::maxComparisons(n);
    std::cout << "Comparisons with std::vector : " << vecComp << " / F(" << n
              << ") = " << maxComp << std::endl;
    std::cout << "Comparisons with std::deque  : " << deqComp << " / F(" << n
              << ") = " << maxComp << std::endl;
    return 0;
}
