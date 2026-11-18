#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        virtual void action() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
};