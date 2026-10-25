
#ifndef BITCONIEXCHANGE_HPP
#define BITCONIEXCHANGE_HPP

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    bool processInput(const std::string& filename) const;

   private:
    std::map<std::string, double> _database;

    static bool isValidDate(const std::string& date);
};

#endif
