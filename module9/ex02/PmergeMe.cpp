
#include "PmergeMe.hpp"

std::size_t PmergeMe::_comparisons = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& s) {
    if (s.empty() || s.size() > 10) return false;
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    }
    long n = std::strtol(s.c_str(), NULL, 10);
    return n >= 1 && n <= INT_MAX;
}

bool PmergeMe::less(int a, int b) {
    ++_comparisons;
    return a < b;
}

std::size_t PmergeMe::getComparisons() const { return _comparisons; }

std::size_t PmergeMe::maxComparisons(std::size_t n) {
    std::size_t sum = 0;
    for (std::size_t k = 1; k <= n; ++k) {
        std::size_t j = 0;
        while ((static_cast<std::size_t>(4) << j) < 3 * k) ++j;
        sum += j;
    }
    return sum;
}

std::size_t PmergeMe::jacobsthal(std::size_t k) {
    std::size_t prev = 0;
    std::size_t cur = 1;

    for (std::size_t i = 1; i < k; ++i) {
        std::size_t next = cur + 2 * prev;
        prev = cur;
        cur = next;
    }
    return cur;
}

void PmergeMe::sort(std::vector<int>& v) {
    if (v.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> chain;
    makePairs(v, pairs, chain);

    sort(chain);

    std::vector<int> pend;
    buildPend(chain, pairs, pend);
    if (v.size() % 2 != 0) pend.push_back(v.back());

    insertPend(chain, pend, pairs.size());
    v = chain;
}

void PmergeMe::makePairs(const std::vector<int>& v,
                         std::vector<std::pair<int, int> >& pairs,
                         std::vector<int>& chain) {
    for (std::size_t i = 0; i + 1 < v.size(); i += 2) {
        int a = v[i];
        int b = v[i + 1];
        if (less(a, b)) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
        chain.push_back(a);
    }
}

void PmergeMe::buildPend(const std::vector<int>& chain,
                         const std::vector<std::pair<int, int> >& pairs,
                         std::vector<int>& pend) {
    std::vector<bool> used(pairs.size(), false);
    for (std::size_t i = 0; i < chain.size(); ++i) {
        for (std::size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == chain[i]) {
                used[j] = true;
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
}

void PmergeMe::insertPend(std::vector<int>& chain, const std::vector<int>& pend,
                          std::size_t m) {
    chain.insert(chain.begin(), pend[0]);

    std::size_t prev = 1;
    for (std::size_t k = 3; prev < pend.size(); ++k) {
        std::size_t cur = jacobsthal(k);
        if (cur > pend.size()) cur = pend.size();

        std::vector<std::size_t> partnerPos;
        for (std::size_t j = prev; j < cur; ++j) partnerPos.push_back(j + prev);

        for (std::size_t i = cur; i > prev; --i) {
            std::size_t idx = i - 1;
            std::size_t end;
            if (idx < m)
                end = partnerPos[idx - prev];
            else
                end = chain.size();
            std::size_t pos = binarySearch(chain, pend[idx], end);
            chain.insert(chain.begin() + pos, pend[idx]);

            for (std::size_t j = prev; j < idx; ++j) {
                if (partnerPos[j - prev] >= pos) ++partnerPos[j - prev];
            }
        }
        prev = cur;
    }
}

std::size_t PmergeMe::binarySearch(const std::vector<int>& chain, int value,
                                   std::size_t end) {
    std::size_t lo = 0;
    std::size_t hi = end;
    while (lo < hi) {
        std::size_t mid = lo + (hi - lo) / 2;
        if (less(chain[mid], value))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

void PmergeMe::sort(std::deque<int>& d) {
    if (d.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> chain;
    makePairs(d, pairs, chain);

    sort(chain);

    std::deque<int> pend;
    buildPend(chain, pairs, pend);
    if (d.size() % 2 != 0) pend.push_back(d.back());

    insertPend(chain, pend, pairs.size());
    d = chain;
}

void PmergeMe::makePairs(const std::deque<int>& d,
                         std::deque<std::pair<int, int> >& pairs,
                         std::deque<int>& chain) {
    for (std::size_t i = 0; i + 1 < d.size(); i += 2) {
        int a = d[i];
        int b = d[i + 1];
        if (less(a, b)) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
        chain.push_back(a);
    }
}

void PmergeMe::buildPend(const std::deque<int>& chain,
                         const std::deque<std::pair<int, int> >& pairs,
                         std::deque<int>& pend) {
    std::deque<bool> used(pairs.size(), false);
    for (std::size_t i = 0; i < chain.size(); ++i) {
        for (std::size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == chain[i]) {
                used[j] = true;
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
}

void PmergeMe::insertPend(std::deque<int>& chain, const std::deque<int>& pend,
                          std::size_t m) {
    chain.push_front(pend[0]);

    std::size_t prev = 1;
    for (std::size_t k = 3; prev < pend.size(); ++k) {
        std::size_t cur = jacobsthal(k);
        if (cur > pend.size()) cur = pend.size();

        std::deque<std::size_t> partnerPos;
        for (std::size_t j = prev; j < cur; ++j) partnerPos.push_back(j + prev);

        for (std::size_t i = cur; i > prev; --i) {
            std::size_t idx = i - 1;
            std::size_t end;
            if (idx < m)
                end = partnerPos[idx - prev];
            else
                end = chain.size();
            std::size_t pos = binarySearch(chain, pend[idx], end);
            chain.insert(chain.begin() + pos, pend[idx]);

            for (std::size_t j = prev; j < idx; ++j) {
                if (partnerPos[j - prev] >= pos) ++partnerPos[j - prev];
            }
        }
        prev = cur;
    }
}

std::size_t PmergeMe::binarySearch(const std::deque<int>& chain, int value,
                                   std::size_t end) {
    std::size_t lo = 0;
    std::size_t hi = end;
    while (lo < hi) {
        std::size_t mid = lo + (hi - lo) / 2;
        if (less(chain[mid], value))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}
