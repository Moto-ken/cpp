
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    Base* p = generate();
    identify(p);
    identify(*p);

    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);

    delete p;
    delete ptr;

    return 0;
}
