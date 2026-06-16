
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low";
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::UpGrade() {
    if (grade <= 1) throw GradeTooHighException();
    grade--;
}

void Bureaucrat::DownGrade() {
    if (grade >= 150) throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& value) {
    out << value.getName() << ", bureaucrat grade " << value.getGrade() << ".";
    return out;
}
