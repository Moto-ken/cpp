
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
   private:
    const std::string name;
    int grade;

   public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };
    std::string getName() const;
    int getGrade() const;
    void UpGrade();
    void DownGrade();
    void signForm(AForm& form);
    void executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& value);

#endif
