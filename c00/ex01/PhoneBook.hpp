#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

const std::string COLOR_RESET = "\x1B[0m";
const std::string COLOR_RED = "\x1B[31m";
const std::string COLOR_GREEN = "\x1B[32m";

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

    void addContact(Contact &contact);
    Contact getContact(int index) const;
    int getNumberOfContacts() const;
    void showContact(int index) const;
    void displayAllContacts() const;

private:
    const static int _maxContacts = 8;
    Contact _contacts[_maxContacts];
    int _numberOfContacts;
};

#endif
