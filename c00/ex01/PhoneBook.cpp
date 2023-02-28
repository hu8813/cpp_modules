#include "PhoneBook.hpp"

// Constructors
PhoneBook::PhoneBook() : _numberOfContacts(0) {}

PhoneBook::~PhoneBook() {}

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
    std::cout << "Contact #" << index << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
