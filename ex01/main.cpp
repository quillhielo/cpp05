#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "1.TEST_GRADES_HIGH_LOW" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Form A("Paseo puerto", 200, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Form B("Paseo canino", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "2.TEST_SIGNING_FORMS" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	Bureaucrat Carmen("Carmen", 1);
	Form Paseo("Paseo puerto", 2, 12);
	try
	{
		Paseo.beSigned(Carmen);	
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	Bureaucrat David("David", 150);
	try
	{
		Paseo.beSigned(David);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	Bureaucrat Maria("Maria", 10);
	try
	{
		Maria.signForm(Paseo);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Carmen.signForm(Paseo);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "3.TEST_CONSTRUCTORS" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	Bureaucrat Default;
	std::cout << Default << std::endl;
	Bureaucrat Copia(Default);
	std::cout << Copia << std::endl;
	Bureaucrat Igual;
	Igual = Carmen;
	std::cout << Igual << std::endl;
}