#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string getInput(const std::string& prompt)
{
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Check if the input is empty
        if (input.empty() || input == "\n" || input == "" || input == " " || input == "\t" || input == "\r") {
            std::cout << "Error: input cannot be empty. Please try again." << std::endl;
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

    std::cout << "Welcome to your phone book!" << std::endl;
  
    std::string command;
    while (true)
    {
    std::cout << "Available commands    : ADD, SEARCH, EXIT" << std::endl;
    std::cout  << std::endl << "Please enter a command: ";
    
    std::cin.clear();
    std::getline(std::cin, command);
    if (std::cin.eof())
        break;
    if (std::cin.fail() || std::cin.bad())
    {
        std::cout << "Error: cin failed" << std::endl;
        break;
    }
    if (command == "ADD")
    {
        std::string firstName = getInput("Enter first name: ");
        std::string lastName = getInput("Enter last name: ");
        std::string nickname = getInput("Enter nickname: ");
        std::string phoneNumber = getInput("Enter phone number: ");
        std::string darkestSecret = getInput("Enter darkest secret: ");
        index = (index + 1) % 8  ;
        contacts = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret, index);
        phoneBook.addContact(contacts);
    }
    else if (command == "SEARCH")
    {
        if (index == 0)
        {
            std::cout << "Nothing in PhoneBook. First add some contacts" << std::endl << std::endl;
            continue;
        }
        while (index != 0)
        {
        if (    phoneBook.getNumberOfContacts() == 0)
			{
				std::cout << "No contact saved in PhoneBook" << std::endl;
				continue ;
			}
			phoneBook.displayAllContacts();
            std::cout << std::endl << "Enter Index number (0 to return): ";
            if (!std::getline(std::cin, searchIndex)) {
            std::cout << std::endl << "EOF detected. Exiting." << std::endl;
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
                std::cout << std::endl << "Error: invalid index number" << std::endl;
                continue;
            }
            int index;

            if (!(iss >> index))
            {
                std::cout << std::endl << "Error: invalid index number" << std::endl;
                continue;
            }
            if (std::cin.fail() || std::cin.bad() || std::cin.eof() || index == 0)
                break;
        
        phoneBook.showContact(index);
        }
    }
    else if (command == "EXIT")
    {
        std::cout << "command: EXIT. Bye!" << std::endl;
        break;
    }
    else
    {
        std::cout << "Error: invalid command: '" << command << "'" << std::endl;
    }

    }

    return 0;
}