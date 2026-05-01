
#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(0), index(0) {}

PhoneBook::~PhoneBook() {}

bool hasControlChar(const std::string& str) {
    size_t i = 0;
    while (i < str.size()) {
        if (iscntrl(static_cast<unsigned char>(str[i]))) return (true);
        i++;
    }
    return (false);
}

bool getVailidInput(std::string& out) {
    if (!std::getline(std::cin, out)) return (false);
    if (out.empty() || hasControlChar(out)) {
        std::cout << "Invalid input" << std::endl;
        return (false);
    }
    return (true);
}

void PhoneBook::addContact() {
    std::string first, last, nick, phone, secret;

    std::cout << "first name:";
    if (!getVailidInput(first)) return;

    std::cout << "last name:";
    if (!getVailidInput(last)) return;

    std::cout << "nickname:";
    if (!getVailidInput(nick)) return;
    // check only number??
    std::cout << "phone:";
    if (!getVailidInput(phone)) return;

    std::cout << "secret:";
    if (!getVailidInput(secret)) return;

    std::cout << "input ok!" << std::endl;
    contacts[index].setContact(first, last, nick, phone, secret);

    index = (index + 1) % 8;
    if (count < 8) count++;
    return;
}

void PhoneBook::printContact(int idx) const {
    std::cout << "First name:" << contacts[idx].getFirst() << std::endl;
    std::cout << "Last name:" << contacts[idx].getLast() << std::endl;
    std::cout << "Nickname:" << contacts[idx].getNick() << std::endl;
    std::cout << "Phone:" << contacts[idx].getPhone() << std::endl;
    std::cout << "Darkest secret:" << contacts[idx].getDark() << std::endl;
}

std::string formatColumn(const std::string& str) {
    if (str.length() > 10) return (str.substr(0, 9) + ".");
    return (str);
}

void PhoneBook::printTable() const {
    int i = 0;
    int j = 0;

    std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10)
              << "first name" << "|" << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << "|" << std::endl;
    while (i < count) {
        j = i + 1;
        std::cout << "|" << std::setw(10) << std::right << j << "|"
                  << std::setw(10) << std::right
                  << formatColumn(contacts[i].getFirst()) << "|"
                  << std::setw(10) << std::right
                  << formatColumn(contacts[i].getLast()) << "|" << std::setw(10)
                  << std::right << formatColumn(contacts[i].getNick()) << "|"
                  << std::endl;
        i++;
    }
}

void PhoneBook::searchContact() const {
    int user_in;
    std::string input;

    printTable();

    std::cout << "Enter index:";
    std::getline(std::cin, input);
    try {
        user_in = ft_stoi(input);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input (not a number)" << std::endl;
        return;
    } catch (const std::out_of_range& e) {
        std::cout << "Number out of range" << std::endl;
        return;
    }

    if (user_in < 1 || user_in > count) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    printContact(user_in - 1);
}
