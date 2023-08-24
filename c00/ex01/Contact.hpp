#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
public:
    // Constructors
    Contact();
    Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret, int index);

    // Destructor
    ~Contact();

    // Getters / Setters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    int getIndex();

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickname(std::string nickname);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string darkestSecret);
    void setIndex(int index);

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    int _index;
};

#endif
