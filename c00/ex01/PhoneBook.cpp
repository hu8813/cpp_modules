#include "PhoneBook.hpp"

// Constructors
PhoneBook::PhoneBook() : _numberOfContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::displayAllContacts() const
{
    std::cout << std::setw(10) << std::right << "Index"
              << " | " << std::setw(10) << std::right << "First Name"
              << " | " << std::setw(10) << std::right << "Last Name"
              << " | " << std::setw(10) << std::right << "Nickname" << std::endl;

    for (int i = 1; i <= _numberOfContacts; i++)
    {
        Contact contact = getContact(i);
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

void PhoneBook::addContact(Contact& contact)
{
    // If there are less than 8 contacts, add the new contact to the next index

        int index = contact.getIndex();
        index = ((index) % 8);
        if (index == 0)
            index = 1;
        contact.setIndex(index);
        _contacts[index - 1] = contact;
        _numberOfContacts++;

    
}

Contact PhoneBook::getContact(int index) const
{
    if (index >= 1 && index <= _numberOfContacts) {
        return _contacts[index - 1];
    } else {
        std::cerr << "Error: index out of range." << std::endl;
        return Contact();
    }
}

int PhoneBook::getNumberOfContacts() const
{
    return _numberOfContacts;
}

void PhoneBook::showContact(int index) const
{
    if (index < 0 || index > _numberOfContacts)
    {
        std::cout << "Error: index out of range" << std::endl;
        return;
    }

    Contact contact = _contacts[index - 1];
    std::cout  << std::endl << "Contact #" << index << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl << std::endl;
}
