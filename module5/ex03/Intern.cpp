
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form, std::string target) {
    std::string names[] = {"shrubbery creation", "robotomy request",
                           "presidential pardon"};
    func creators[] = {createShrubbery, createRobotomy, createPardon};
    for (int i = 0; i < 3; i++) {
        if (names[i] == form) {
            std::cout << "Intern creates " << form << std::endl;
            return creators[i](target);
        }
    }
    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Error: unknown form";
}
