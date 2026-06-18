
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        RobotomyRequestForm robot("kemotoha");
        PresidentialPardonForm pardon("kemo");
        ShrubberyCreationForm shrub("home");

        bob.signForm(robot);
        bob.executeForm(robot);
        std::cout << std::endl;

        bob.signForm(pardon);
        bob.executeForm(pardon);
        std::cout << std::endl;

        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}