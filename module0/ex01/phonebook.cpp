
#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(0), index(0) {}

void PhoneBook::addContact() {
    std::string last;
    std::string first;
    std::string nick;
    std::string phone;
    std::string secret;

    // MUST:check enpty value
    std::cout << "first name: ";
    if (!(std::cin >> first)) return;
    std::cout << "last name: ";
    if (!(std::cin >> last)) return;
    std::cout << "nickname: ";
    if (!(std::cin >> nick)) return;
    std::cout << "phone: ";
    if (!(std::cin >> phone)) return;
    std::cout << "secret: ";
    if (!(std::cin >> secret)) return;
    std::cout << "input ok!" << std::endl;
    contacts[index].setContact(first, last, nick, phone, secret);

    index = (index + 1) % 8;
    if (count < 8) count++;
}

void PhoneBook::printContact(int idx) const {
    std::cout << "First name: " << contacts[idx].getFirst() << std::endl;
    std::cout << "Last name: " << contacts[idx].getLast() << std::endl;
    std::cout << "Nickname: " << contacts[idx].getNick() << std::endl;
    std::cout << "Phone: " << contacts[idx].getPhone() << std::endl;
    std::cout << "Darkest secret: " << contacts[idx].getDark() << std::endl;
}

void PhoneBook::searchContact() const {
    int i = 0;
    int idx;

    // format attended display
    // cout << right << setw(10) 10文字分の右寄せとか
    std::cout << "index | first name | last name | nickname" << std::endl;
    while (i < count) {
        std::cout << i << "|" << contacts[i].getFirst() << "|"
                  << contacts[i].getLast() << "|" << contacts[i].getNick()
                  << std::endl;
        i++;
    }

    std::cout << "Enter index:";
    std::cin >> idx;
    if (idx >= 0 && idx < count)
        printContact(idx);
    else
        std::cout << "Invalid index" << std::endl;
}
