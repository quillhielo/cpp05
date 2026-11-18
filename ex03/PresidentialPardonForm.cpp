#include "PresidentialPardonForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidental Pardon Form", 25, 5), _target("default")
{

}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidental Pardon Form", 25, 5), _target(target)
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::action() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}