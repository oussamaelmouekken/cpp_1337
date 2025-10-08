#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        bool isValidDate(const std::string &date) const;
        bool isLeapYear(int year) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void readData(const std::string &filename);
        void processFile(const std::string &filename);
        std::string trim(const std::string& s);
};

#endif // BITCOINEXCHANGE_HPP