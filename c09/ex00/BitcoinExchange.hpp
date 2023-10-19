#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

class BitcoinExchange {
public:
    BitcoinExchange();
    bool loadPrices(const std::string& filename);
    double getPriceForDate(const std::string& date) const;

private:
    std::map<std::string, double> btcPrices;
};
