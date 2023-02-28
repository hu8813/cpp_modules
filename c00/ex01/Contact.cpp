#include "Contact.hpp"

// Constructors
Contact::Contact() : _index(1) {}

Contact::Contact(const Contact& copy)
{
    *this = copy;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret, int index)
    : _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret), _index(index) {}

// Destructor
Contact::~Contact() {}

// Operators
Contact& Contact::operator=(const Contact& assign)
{
    if (this != &assign)
    {
        _firstName = assign._firstName;
        _lastName = assign._lastName;
        _nickname = assign._nickname;
        _phoneNumber = assign._phoneNumber;
        _darkestSecret = assign._darkestSecret;
        _index = assign._index;
    }
    return *this;
}

// Getters / Setters
std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return _phoneNumber;
}

int Contact::getIndex()
{
    return _index;
}

void Contact::setFirstName(std::string firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    _darkestSecret = darkestSecret;
}

void Contact::setIndex(int index) 
{
    _index = index;
}
