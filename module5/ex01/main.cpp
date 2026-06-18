
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 30);
    Form Documents("Confidential Documents", 40, 20);

    bob.signForm(Documents);
    alice.signForm(Documents);
    std::cout << Documents << std::endl;
    return 0;
}
