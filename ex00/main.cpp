#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "1.TEST_GRADES_HIGH_LOW" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat A("Alba", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat B("Alberto", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "2.TEST_INCREMENT_DECREMENT" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	Bureaucrat C("Carmen", 1);
	try
	{
		C.incrementGrade();	
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << C << std::endl;
	try
	{
		C.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << C << std::endl;
	Bureaucrat D("David", 150);
	try
	{
		D.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << D << std::endl;
	try
	{
		D.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << D << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "3.TEST_CONSTRUCTORS" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	Bureaucrat E;
	std::cout << E << std::endl;
	Bureaucrat F(D);
	std::cout << F << std::endl;
	Bureaucrat G;
	G = E;
	std::cout << G << std::endl;
	
}