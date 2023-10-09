#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
    // Declare the ofstream object
    std::ofstream outfile;

    try {
        outfile.open((_target + "_shrubbery").c_str()); // Open the file

        // Check if the file is open
        if (outfile.is_open()) {
            outfile << "      /\\\n"
                       "     /\\*\\\n"
                       "    /\\O\\*\\\n"
                       "   /*/\\/\\/\\\n"
                       "  /\\O\\/\\*\\/\\\n"
                       " /\\*\\/\\*\\/\\/\\\n"
                       "/\\O\\/\\/*/\\/O/\\\n"
                       "      ||\n"
                       "      ||\n"
                       "      ||\n";

            // Close the file explicitly
            outfile.close();

            // Check for any errors while writing
            if (outfile.fail()) {
                throw std::runtime_error("Error writing to file");
            }
        } else {
            throw std::runtime_error("Unable to open file for writing");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}





