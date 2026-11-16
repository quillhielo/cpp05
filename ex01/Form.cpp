#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("default"), _sign_grade(150), _execute_grade(150)
{
    std::cout << "Form default constructor called" << std::endl;
}
Form::Form(std::string name,  int sign_grade, int execute_grade): _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    std::cout << "Form parameter constructor called" << std::endl;
    if (_sign_grade > 150)
        throw GradeTooLowException();
    else if (_sign_grade < 1)
        throw GradeTooHighException();
    if (_execute_grade > 150)
        throw GradeTooLowException();
    else if (_execute_grade < 1)
        throw GradeTooHighException();
}
Form::Form(const Form& other):_name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
    std::cout << "Form copy constructor called" << std::endl;
}
Form& Form::operator=(const Form& other)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if(this != &other)
        this->_signed = other._signed;
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

bool Form::getSigned() const
{
    return (this->_signed);
}

std::string Form::getName() const
{
    return (this->_name);
}
int Form::getSignGrade() const
{
    return (this->_sign_grade);
}
int Form::getExecuteGrade() const
{
    return (this->_execute_grade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
    os << other.getName() << ", Form signed: " << other.getSigned() << ", Form sign grade " << other.getSignGrade() << ", Form execute grade " << other.getExecuteGrade() << std::endl;
    return(os);
}


Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}