#include <Intern.hpp>
#include <string>

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
			//
			break;
		case 1:
			//
			break;
		case 2:
			//
			break;
		default:
			throw FormNameDoesNotExist();
	}
}

const char* Intern::FormNameDoesNotExist:: what() const throw()
{
	return("FormNameDoesNotExist");
}

Intern::~Intern(void)
{

}

