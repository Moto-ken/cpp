
#include "phonebook.hpp"

int main(void) {
    std::string cmd;
    PhoneBook phoneBook;

    while (1) {
        std::cout << "select mode" << std::endl;
        if (!std::getline(std::cin, cmd)) return (1);
        if (cmd == "ADD") {
            phoneBook.addContact();
        } else if (cmd == "SEARCH") {
            phoneBook.searchContact();
        } else if (cmd == "EXIT") {
            break;
        } else {
            std::cout << "invailid command" << std::endl;
        }
    }
    return (0);
}
