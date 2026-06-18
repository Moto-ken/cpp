
#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
   private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int executeGrade;

   public:
    AForm();
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
       public:
        const char* what() const throw();
    };
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat& b);
    void execute(Bureaucrat const& executor) const;

   protected:
    virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& value);

#endif
