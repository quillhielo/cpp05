#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        virtual void action() const;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        class OpenFileException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        ~ShrubberyCreationForm();
};  