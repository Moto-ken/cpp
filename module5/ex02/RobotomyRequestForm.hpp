
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   private:
    std::string target;

   public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& taget);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

   protected:
    void executeAction() const;
};

#endif
