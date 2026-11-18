#include "Intern.hpp"
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{

}
Intern::Intern(const Intern& other)
{
	(void)other;
}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return(*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;
	std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	while(i < 3 && formName != formNames[i])
	{
		i++;
	}
	switch(i)
	{
		case 0:
			return(new PresidentialPardonForm(target));
		case 1:
			return(new RobotomyRequestForm(target));
		case 2:
			return(new ShrubberyCreationForm(target));
		default:
			throw FormNameDoesNotExist();
	}
}

const char* Intern::FormNameDoesNotExist:: what() const throw()
{
	return("Form type name does not exist");
}

Intern::~Intern(void)
{

}

