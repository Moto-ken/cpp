
#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    std::list<int> list;

    // std::cout << "empty mstack: " << mstack.empty() << std::endl;
    // std::cout << "size mstack: " << mstack.size() << std::endl;
    // std::cout << "empty list: " << list.empty() << std::endl;
    // std::cout << "size list: " << list.size() << std::endl;

    mstack.push(5);
    mstack.push(17);
    list.push_back(5);
    list.push_back(17);

    std::cout << "top mstack: " << mstack.top() << std::endl;
    std::cout << "top list: " << list.back() << std::endl;

    mstack.pop();
    list.pop_back();

    std::cout << "top mstack: " << mstack.top() << std::endl;
    std::cout << "top list: " << list.back() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(13);
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(13);

    std::cout << "begin mstack: " << *mstack.begin() << std::endl;
    std::cout << "begin list: " << *list.begin() << std::endl;
    std::cout << "end mstack: " << mstack.top() << std::endl;
    std::cout << "end list: " << list.back() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "mutant stack list" << std::endl;
    // it == ite になった状態で *it すると危険。undefined behavior
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::list<int>::iterator it_list = list.begin();
    std::list<int>::iterator ite_list = list.end();

    std::cout << "list list" << std::endl;
    while (it_list != ite_list) {
        std::cout << *it_list << std::endl;
        ++it_list;
    }

    return 0;
}
