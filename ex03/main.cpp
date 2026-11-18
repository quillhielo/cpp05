#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::cout << "1.TEST_CONSTRUCTORS" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "2.TEST_SIGNING_FORMS" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    Bureaucrat low("David", 150);
    Bureaucrat high("Carmen", 1);

    low.signAForm(robotomy);
    high.signAForm(robotomy);

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "3.TEST_EXECUTION_GRADES" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    Bureaucrat medium("Maria", 50);

    medium.executeAForm(robotomy);
    high.executeAForm(robotomy);

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "4.TEST_SHRUBBERY_CREATION" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    high.signAForm(shrubbery);
    high.executeAForm(shrubbery);

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "5.TEST_PRESIDENTIAL_PARDON" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    high.signAForm(pardon);
    high.executeAForm(pardon);

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "6.TEST_EXECUTION_UNSIGNED_FORM" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    RobotomyRequestForm unsignedForm("Marvin");
    high.executeAForm(unsignedForm);

    return 0;
}