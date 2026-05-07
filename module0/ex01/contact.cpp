
#include "phonebook.hpp"

void Contact::setContact(std::string first, std::string last, std::string nick,
                         std::string phone, std::string secret) {
    first_name = first;
    last_name = last;
    nickname = nick;
    phone_number = phone;
    darkest_secret = secret;
}

std::string Contact::getFirst() const { return (first_name); }

std::string Contact::getLast() const { return (last_name); }

std::string Contact::getNick() const { return (nickname); }

std::string Contact::getPhone() const { return (phone_number); }

std::string Contact::getDark() const { return (darkest_secret); }
