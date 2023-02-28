#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

    void addContact(Contact& contact);
    Contact getContact(int index) const;
    int getNumberOfContacts() const;
    void showContact(int index) const;

private:
    Contact _contacts[8];
    int _numberOfContacts;
};

#endif
