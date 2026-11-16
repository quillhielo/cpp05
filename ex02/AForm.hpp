#pragma once
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class AForm
{
    private:
        const std::string  _name;
        bool    _signed;
        const int _sign_grade;
        const int _execute_grade;
        virtual void action() const = 0;
    public:
        AForm();
        AForm(std::string name, int sign_grade, int execute_grade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        bool getSigned() const;
        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
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
        ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& other);
        
