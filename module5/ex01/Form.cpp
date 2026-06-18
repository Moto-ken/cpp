
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

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

std::string Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getSignGrade() const { return signGrade; }

int Form::getExecuteGrade() const { return executeGrade; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade) throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << form.getName()
        << " (signed: " << (form.getIsSigned() ? "true" : "false")
        << ", sign grade: " << form.getSignGrade()
        << ", execute grade: " << form.getExecuteGrade() << ")";
    return out;
}