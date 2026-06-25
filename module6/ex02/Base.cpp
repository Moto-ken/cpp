
#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
    int num = std::rand() % 3;
    if (num == 0) return new A();
    if (num == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception& e) {
        // std::cout << e.what() << std::endl;
    }
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception& e) {
        // std::cout << e.what() << std::endl;
    }
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception& e) {
        // std::cout << e.what() << std::endl;
    }
}
