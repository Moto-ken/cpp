
#include "phonebook.hpp"

int main(void) {
    std::string a;
    PhoneBook phoneBook;

    while (1) {
        std::cout << "select mode" << std::endl;
        std::cin >> a;
        if (a == "ADD") {
            phoneBook.addContact();
        } else if (a == "SEARCH") {
            phoneBook.searchContact();
        } else if (a == "EXIT") {
            break;
        } else {
            std::cout << "invailid command" << std::endl;
        }
    }
    return (0);
}
