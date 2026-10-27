
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class PmergeMe {
   public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static bool isValidNumber(const std::string& s);

    template <typename Container>
    double measure(Container& c, char** argv, int n);

   private:
    void sort(std::vector<int>& v);
    static void makePairs(const std::vector<int>& v,
                          std::vector<std::pair<int, int> >& pairs,
                          std::vector<int>& chain);
    static void buildPend(const std::vector<int>& chain,
                          const std::vector<std::pair<int, int> >& pairs,
                          std::vector<int>& pend);
    static void insertPend(std::vector<int>& chain,
                           const std::vector<int>& pend, std::size_t m);
    static std::size_t binarySearch(const std::vector<int>& chain, int value,
                                    std::size_t end);

    void sort(std::deque<int>& d);
    static void makePairs(const std::deque<int>& d,
                          std::deque<std::pair<int, int> >& pairs,
                          std::deque<int>& chain);
    static void buildPend(const std::deque<int>& chain,
                          const std::deque<std::pair<int, int> >& pairs,
                          std::deque<int>& pend);
    static void insertPend(std::deque<int>& chain, const std::deque<int>& pend,
                           std::size_t m);
    static std::size_t binarySearch(const std::deque<int>& chain, int value,
                                    std::size_t end);

    static std::size_t jacobsthal(std::size_t k);
};

template <typename Container>
double PmergeMe::measure(Container& c, char** argv, int n) {
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < n; ++i) c.push_back(std::atoi(argv[i]));

    sort(c);
    gettimeofday(&end, NULL);
    return (end.tv_sec - start.tv_sec) * 1000000.0 +
           (end.tv_usec - start.tv_usec);
}

#endif
