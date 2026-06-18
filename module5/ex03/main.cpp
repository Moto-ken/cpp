
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Intern intern;
    Bureaucrat boss("boss", 1);

    try {
        AForm* form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        AForm* form = intern.makeForm("wrong form", "test");
        delete form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
