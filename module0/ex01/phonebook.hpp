
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include <string>

int ft_stoi(const std::string& s);

class Contact {
   private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

   public:
    void setContact(std::string first, std::string last, std::string nick,
                    std::string phone, std::string secret);
    std::string getFirst() const;
    std::string getLast() const;
    std::string getNick() const;
    std::string getPhone() const;
    std::string getDark() const;
};

class PhoneBook {
   private:
    Contact contacts[8];
    int count;
    int index;

   public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact() const;
    void printContact(int idx) const;
    void printTable() const;
};

#endif
