#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

void displayContacts(const PhoneBook& phoneBook)
{
    std::cout << std::setw(10) << std::right << "Index"
              << " | " << std::setw(10) << std::right << "First Name"
              << " | " << std::setw(10) << std::right << "Last Name"
              << " | " << std::setw(10) << std::right << "Nickname" << std::endl;
    
    for (int i = 1; i <= phoneBook.getNumberOfContacts(); i++)
    {
        Contact contact = phoneBook.getContact(i);
        std::string firstName = contact.getFirstName();
        std::string lastName = contact.getLastName();
        std::string nickname = contact.getNickname();

        // Truncate the strings if they are too long
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        
        std::cout << std::setw(10) << std::right << i
                  << " | " << std::setw(10) << std::right << firstName
                  << " | " << std::setw(10) << std::right << lastName
                  << " | " << std::setw(10) << std::right << nickname << std::endl;
    }
}

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
        while (index != 0)
        {
        if (    phoneBook.getNumberOfContacts() == 0)
			{
				std::cout << "No contact saved in PhoneBook" << std::endl;
				continue ;
			}
			displayContacts(phoneBook);
            std::cout << "Enter Index number (0 to return): ";
            std::getline(std::cin, searchIndex);
            std::istringstream iss(searchIndex);
            int index;
            if (!(iss >> index))
            {
                std::cout << "Error: invalid index number" << std::endl;
                continue;
            }
            if (index == 0)
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