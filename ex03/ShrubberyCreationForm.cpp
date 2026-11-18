#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 137, 145), _target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 137, 145), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
    return ("Failed to open file");
}
void ShrubberyCreationForm::action() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (file)
    { 
		file << "    /\\             \n";
		file << "   /  \\            \n";
		file << "  /    \\           \n";
		file << " /      \\    /\\   \n";
		file << "/________\\  /  \\  \n";
		file << "    ||     /____\\ \n";
		file << "    ||       ||    \n";
		file << "    ||       ||    \n";
    }
    else
        throw OpenFileException();
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}   