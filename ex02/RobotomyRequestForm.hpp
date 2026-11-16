#pragma once
#include "AForm.hpp"
#include <exception>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        virtual void action() const;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        class RobotomyFailedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        ~RobotomyRequestForm();
};