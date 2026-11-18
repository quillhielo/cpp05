#include "RobotomyRequestForm.hpp"
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
char const* RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
    return ("Robotomy failed");
}
void RobotomyRequestForm::action() const
{
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else    
        throw RobotomyFailedException();
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
