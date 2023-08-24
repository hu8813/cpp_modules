#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (std::string::npos == first)
    {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

std::string getInput(const std::string& prompt)
{
    std::string input;
    while (true) {
        std::cout << COLOR_GREEN << prompt << COLOR_RESET;
        if (!std::getline(std::cin, input)) {
            std::cout << COLOR_RED << "End of input reached. Exiting. " << COLOR_RESET << std::endl;
            break;
        }
        std::string trimmedInput = trim(input);
        if (input.empty() || input == "\n" || input == "" || input == " " || input == "\t" || input == "\r" || trimmedInput.empty()) {
            std::cout << COLOR_RED << "Error: input cannot be empty. Please try again." << COLOR_RESET << std::endl;
            continue;
        }

        break;
    }
    return input;
}

int main()
{
    Contact contacts;
    PhoneBook phoneBook;
    std::string searchIndex;
    static int index;

    std::cout << COLOR_GREEN << "Welcome to your phone book!" << COLOR_RESET << std::endl;
  
    std::string command;
    while (true)
    {
    std::cout << COLOR_GREEN << "Available commands : ADD, SEARCH, EXIT" << COLOR_RESET << std::endl;
    std::cout  << COLOR_GREEN << std::endl << "Please enter a command: " << COLOR_RESET  << std::endl ;
    
    std::cin.clear();
    std::getline(std::cin, command);
    if (std::cin.eof())
        break;
    if (std::cin.fail() || std::cin.bad())
    {
        std::cerr << COLOR_RED << "Error: cin failed" << COLOR_RESET << std::endl;
        break;
    }
    if (command == "ADD")
    {
        std::string firstName = getInput("Enter first name: ");
        std::string lastName = getInput("Enter last name: ");
        std::string nickname = getInput("Enter nickname: ");
        std::string phoneNumber = getInput("Enter phone number: ");
        std::string darkestSecret = getInput("Enter darkest secret: ");
        contacts = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret, index);
        index = (index + 1) % 8  ;
        phoneBook.addContact(contacts);
    }
    else if (command == "SEARCH")
    {
        // if (index == 0)
        // {
        //     std::cout << COLOR_RED << "Nothing in PhoneBook. First add some contacts" << COLOR_RESET << std::endl << std::endl;
        //     continue;
        // }
        while (phoneBook.getNumberOfContacts() >= 0)
        {
        if (    phoneBook.getNumberOfContacts() == 0)
			{
				std::cout << COLOR_RED << "No contact saved in PhoneBook" << COLOR_RESET << std::endl;
				break ;
			}
			phoneBook.displayAllContacts();
            std::cout << COLOR_GREEN << std::endl << "Enter Index number (0 to return) " << COLOR_RESET << std::endl;
            if (!std::getline(std::cin, searchIndex)) {
            std::cerr << COLOR_RED << std::endl << "EOF detected. Exiting." << COLOR_RESET << std::endl;
            break;
            }
        
            std::istringstream iss(searchIndex);

            bool isDigits = true;
            for (size_t i = 0; i < searchIndex.length(); ++i) {
                if (!std::isdigit(searchIndex[i])) {
                    isDigits = false;
                    break;
                }
            }
             if (!isDigits) {
                std::cout << COLOR_RED << std::endl << "Error: invalid index number" << COLOR_RESET << std::endl;
                continue;
            }
            int index;

            if (!(iss >> index))
            {
                std::cout << COLOR_RED << std::endl << "Error: invalid index number" << COLOR_RESET << std::endl;
                continue;
            }
            if (std::cin.fail() || std::cin.bad() || std::cin.eof() || index == 0)
                break;
        
        phoneBook.showContact(index);
        }
    }
    else if (command == "EXIT")
    {
        std::cout << COLOR_GREEN << "command: EXIT. Bye!" << std::endl;
        break;
    }
    else
    {
        std::cout << COLOR_RED << std::endl << "Error: invalid command: '" << command << "'" << COLOR_RESET  << std::endl;
    }

    }

    return 0;
}