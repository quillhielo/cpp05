#pragma once
#include "AForm.hpp"
#include <exception>

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(std::string formName, std::string target);
        class FormNameDoesNotExist : public std::exception
        {
            public:
                const char* what() const throw();
        };
        virtual ~Intern(void);
};


