#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();

    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    bool loadPrices(const std::string &filename);
    double getPriceForDate(const std::string &date) const;
    bool isDateValid(std::string &dateStr);
    bool isValidInput(const std::string &input);
    std::string formatDouble(double value);

private:
    std::map<std::string, double> _btcPrices;
};
