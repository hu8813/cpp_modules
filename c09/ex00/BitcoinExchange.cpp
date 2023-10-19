#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

bool BitcoinExchange::loadPrices(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string dateStr;
        double price;
        if (std::getline(ss, dateStr, ',') && dateStr.length() == 10) {
            dateStr = dateStr.substr(0, 10);
        }
        if (ss >> price) {
            btcPrices[dateStr] = price;
        }
    }

    file.close();
    return true;
}

double BitcoinExchange::getPriceForDate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = btcPrices.find(date);
    if (date < btcPrices.begin()->first || date > btcPrices.rbegin()->first) {
        std::cout << "Error: date out of range. => "<< date << std::endl;
        return -1;
    }
    if (it == btcPrices.end()) {
        it = btcPrices.lower_bound(date);
        if (it != btcPrices.begin()) {
            --it;
        }
    }
    double price = it->second;
    if (price < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return price;
    }
    if (price > 9999999) {
        std::cout << "Error: too large a number." << std::endl;
        return price;
    }
    return price;
}
