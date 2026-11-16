#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form
{
    private:
        const std::string  _name;
        bool    _signed;
        const int _sign_grade;
        const int _execute_grade;
    public:

        Form();
        Form(std::string name, int sign_grade, int execute_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);

        bool getSigned() const;
        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        ~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& other);
        
