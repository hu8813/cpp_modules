#include "PhoneBook.hpp"

// Constructors
PhoneBook::PhoneBook() : _numberOfContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::start()
{
    Contact contacts;
    std::string searchIndex;
    static int index;

    std::cout << COLOR_GREEN << "Welcome to your phone book!" << COLOR_RESET << std::endl;

    std::string command;
    while (true)
    {
        std::cout << COLOR_GREEN << "Available commands : ADD, SEARCH, EXIT" << COLOR_RESET << std::endl;
        std::cout << COLOR_GREEN << std::endl
                  << "Please enter a command: " << COLOR_RESET << std::endl;

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
            std::string phoneNumber = getValidPhoneNumber();
            std::string darkestSecret = getInput("Enter darkest secret: ");
            contacts = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret, index);
            index = (index + 1) % 8;
            addContact(contacts);
        }
        else if (command == "SEARCH")
        {
            while (getNumberOfContacts() >= 0)
            {
                if (getNumberOfContacts() == 0)
                {
                    std::cout << COLOR_RED << "No contact saved in PhoneBook" << COLOR_RESET << std::endl;
                    break;
                }
                displayAllContacts();
                std::cout << COLOR_GREEN << std::endl
                          << "Enter Index number (to return to previous Menu, enter 0) " << COLOR_RESET << std::endl;
                if (!std::getline(std::cin, searchIndex))
                {
                    std::cerr << COLOR_RED << std::endl
                              << "EOF detected. Exiting." << COLOR_RESET << std::endl;
                    break;
                }

                std::istringstream iss(searchIndex);

                bool isDigits = true;
                for (size_t i = 0; i < searchIndex.length(); ++i)
                {
                    if (!std::isdigit(searchIndex[i]))
                    {
                        isDigits = false;
                        break;
                    }
                }
                if (!isDigits)
                {
                    std::cout << COLOR_RED << std::endl
                              << "Error: invalid index number" << COLOR_RESET << std::endl;
                    continue;
                }
                int index;

                if (!(iss >> index))
                {
                    std::cout << COLOR_RED << std::endl
                              << "Error: invalid index number" << COLOR_RESET << std::endl;
                    continue;
                }
                if (std::cin.fail() || std::cin.bad() || std::cin.eof() || index == 0)
                    break;

                showContact(index);
            }
        }
        else if (command == "EXIT")
        {
            std::cout << COLOR_GREEN << "command: EXIT. Bye!" << COLOR_RESET << std::endl;
            break;
        }
        else
        {
            std::cout << COLOR_RED << std::endl
                      << "Error: invalid command: '" << command << "'" << COLOR_RESET << std::endl;
        }
    }
}

std::string PhoneBook::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (std::string::npos == first)
    {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

bool PhoneBook::isValidPhoneNumber(const std::string &phoneNumber)
{
    int plusCount = 0;
    int digits = 0;
    for (std::string::size_type i = 0; i < phoneNumber.length(); ++i)
    {
        char c = phoneNumber.at(i);

        if (c == '+')
        {
            plusCount++;
            if (plusCount > 1)
            {
                return false;
            }
        }
        else if (!(std::isdigit(c) || std::isspace(c)))
        {
            return false;
        }
        else if (std::isdigit(c))
        {
            digits++;
        }
    }
    return digits > 0;
}

std::string PhoneBook::getInput(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << COLOR_GREEN << prompt << COLOR_RESET << std::endl;
        if (!std::getline(std::cin, input))
        {
            std::cout << COLOR_RED << "End of input reached. Exiting. " << COLOR_RESET << std::endl;
            break;
        }
        std::string trimmedInput = trim(input);
        if (input.empty() || input == "\n" || input == "" || input == " " || input == "\t" || input == "\r" || trimmedInput.empty())
        {
            std::cout << COLOR_RED << "Error: input cannot be empty. Please try again." << COLOR_RESET << std::endl;
            continue;
        }

        break;
    }
    return input;
}

std::string PhoneBook::getValidPhoneNumber()
{
    while (true)
    {
        std::string phoneNumber = getInput("Enter phone number: ");
        if (isValidPhoneNumber(phoneNumber))
        {
            return phoneNumber;
        }
        else
        {
            std::cout << "Invalid phone number. Please enter a valid phone number. i.e. +4350111 (Only plus sign, space and digits allowed)" << std::endl;
        }
        if (std::cin.eof())
            return "";
        if (std::cin.fail() || std::cin.bad())
        {
            std::cerr << COLOR_RED << "Error: cin failed" << COLOR_RESET << std::endl;
            return "";
        }
    }
}

void PhoneBook::displayAllContacts() const
{
    std::cout << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First Name"
              << "|" << std::setw(10) << std::right << "Last Name"
              << "|" << std::setw(10) << std::right << "Nickname" << std::endl;

    for (int i = 0; i < _numberOfContacts; i++)
    {
        Contact contact = getContact(i);
        std::string firstName = contact.getFirstName();
        std::string lastName = contact.getLastName();
        std::string nickname = contact.getNickname();

        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";

        std::cout << std::setw(10) << std::right << i + 1
                  << "|" << std::setw(10) << std::right << firstName
                  << "|" << std::setw(10) << std::right << lastName
                  << "|" << std::setw(10) << std::right << nickname << std::endl;
    }
}

void PhoneBook::addContact(Contact &contact)
{
    // If there are less than 8 contacts, add the new contact to the next index

    int index = contact.getIndex();
    _contacts[index] = contact;
    index = ((index + 1) % 8);
    contact.setIndex(index);
    if (_numberOfContacts < 8)
        _numberOfContacts++;
}

Contact PhoneBook::getContact(int index) const
{
    if (index >= 0 && index < _numberOfContacts && index < _maxContacts)
    {
        return _contacts[index];
    }
    else
    {
        std::cout << COLOR_RED << "Error: index out of range." << COLOR_RESET << std::endl;
        return Contact();
    }
}

int PhoneBook::getNumberOfContacts() const
{
    return _numberOfContacts;
}

void PhoneBook::showContact(int index) const
{
    if (index < 1 || index > _numberOfContacts || index > _maxContacts)
    {
        std::cout << COLOR_RED << "Error: index out of range" << COLOR_RESET << std::endl;
        return;
    }
    Contact contact = _contacts[index - 1];
    std::cout << std::endl
              << "Contact #" << index << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl
              << std::endl;
}
