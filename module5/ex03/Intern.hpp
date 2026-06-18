
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef AForm* (*func)(std::string);

class AForm;

class Intern {
   public:
    Intern();
    Intern(const Intern&);
    ~Intern();
    Intern& operator=(const Intern&);

    AForm* makeForm(std::string form, std::string target);
    class UnknownFormException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
};

#endif
