
#include "AForm.hpp"

AForm::AForm()
    : name("default"), isSigned(false), signGrade(1), executeGrade(1) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : name(name),
      isSigned(false),
      signGrade(signGrade),
      executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1) throw GradeTooHighException();

    if (signGrade > 150 || executeGrade > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      signGrade(other.signGrade),
      executeGrade(other.executeGrade) {}

AForm& AForm::operator=(const AForm& other) {
    this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "sainn ga nai";
}

std::string AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getSignGrade() const { return signGrade; }

int AForm::getExecuteGrade() const { return executeGrade; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade) throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << form.getName()
        << " (signed: " << (form.getIsSigned() ? "true" : "false")
        << ", sign grade: " << form.getSignGrade()
        << ", execute grade: " << form.getExecuteGrade() << ")";
    return out;
}

void AForm::execute(Bureaucrat const& executor) const {
    if (!isSigned) throw FormNotSignedException();
    if (executor.getGrade() > executeGrade) throw GradeTooLowException();
    executeAction();
}
