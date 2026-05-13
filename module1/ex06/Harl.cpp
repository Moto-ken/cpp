
#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger.\nI "
                 "really do!"
              << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "I think I deserve to have some extra bacon for free.\nI’ve been "
           "coming for years, whereas you started working here just last month."
        << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int index = -1;
    int i = 0;
    while (i < 4) {
        if (levels[i] == level) {
            index = i;
            break;
        }
        i++;
    }
    switch (index) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
            std::cout << std::endl;
            // fall through
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            info();
            std::cout << std::endl;
            // fall through
        case 2:
            std::cout << "[ WARGING ]" << std::endl;
            warning();
            std::cout << std::endl;
            // fall through
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
    }
}
