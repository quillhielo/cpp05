#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("default"), _sign_grade(150), _execute_grade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}
AForm::AForm(std::string name,  int sign_grade, int execute_grade): _name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    std::cout << "AForm parameter constructor called" << std::endl;
    if (_sign_grade > 150)
        throw GradeTooLowException();
    else if (_sign_grade < 1)
        throw GradeTooHighException();
    if (_execute_grade > 150)
        throw GradeTooLowException();
    else if (_execute_grade < 1)
        throw GradeTooHighException();
}
AForm::AForm(const AForm& other):_name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}
AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if(this != &other)
        this->_signed = other._signed;
    return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

bool AForm::getSigned() const
{
    return (this->_signed);
}

std::string AForm::getName() const
{
    return (this->_name);
}
int AForm::getSignGrade() const
{
    return (this->_sign_grade);
}
int AForm::getExecuteGrade() const
{
    return (this->_execute_grade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
    os << other.getName() << ", AForm signed: " << other.getSigned() << ", AForm sign grade " << other.getSignGrade() << ", AForm execute grade " << other.getExecuteGrade() << std::endl;
    return(os);
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}
void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->_execute_grade)
        throw GradeTooLowException();
    else if (!this->_signed)
        throw FormNotSignedException();
    action();
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}