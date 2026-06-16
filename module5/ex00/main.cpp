
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat first("first", 1);

        std::cout << first << std::endl;
        first.DownGrade();
        std::cout << first << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
