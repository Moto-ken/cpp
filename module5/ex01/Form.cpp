
#include "Form.hpp"

Form::Form()
    : name("default"), isSigned(false), signGrade(1), executeGrade(1) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : name(name),
      isSigned(false),
      signGrade(signGrade),
      executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException();

    if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name),
      isSigned(other.isSigned),
      signGrade(other.signGrade),
      executeGrade(other.executeGrade) {}

Form& Form::operator=(const Form& other) {
    this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}
