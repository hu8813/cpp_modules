#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _btcPrices.clear();

        for (std::map<std::string, double>::const_iterator it = other._btcPrices.begin(); it != other._btcPrices.end(); ++it) {
            _btcPrices[it->first] = it->second;
        }
    }
    
    return *this;
}

bool BitcoinExchange::isValidInput(const std::string &input)
{
    int dotCount = 0;
    int pipeCount = 0;
    int dashCount = 0;
    int spaceCount = 0;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
            {
                return false;
            }
        }
        else if (input[i] == '|')
        {
            pipeCount++;
            if (pipeCount > 1)
            {
                return false;
            }
        }
        else if (input[i] == ' ')
        {
            spaceCount++;
            if (spaceCount > 2)
            {
                return false;
            }
        }
        else if (i < 10 && input[i] == '-')
        {
            dashCount++;
            if (dashCount > 2)
            {
                return false;
            }
        }
        else if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+' && input[i] != '-')
        {
            return false;
        }
    }

    return true;
}

std::string BitcoinExchange::formatDouble(double value)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << value;
    std::string formatted = oss.str();

    while (!formatted.empty() && (formatted[formatted.size() - 1] == '0' || formatted[formatted.size() - 1] == '.'))
    {
        formatted.erase(formatted.size() - 1);
    }
    if (formatted.empty())
        formatted = "0";

    return formatted;
}

bool BitcoinExchange::isDateValid(std::string &dateStr)
{
    if (dateStr.size() != 10)
    {
        return false;
    }
    if (dateStr[4] != '-' || dateStr[7] != '-')
    {
        return false;
    }
    int year = 0, month = 0, day = 0;
    std::istringstream(dateStr.substr(0, 4)) >> year;
    std::istringstream(dateStr.substr(5, 2)) >> month;
    std::istringstream(dateStr.substr(8, 2)) >> day;
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1970 || year > 2050)
    {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }
    if (month == 2)
    {
        if (day > 29)
        {
            return false;
        }
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
        {
            return false;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
        {
            continue;
        }
        if (!std::isdigit(dateStr[i]))
        {
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::loadPrices(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (file.fail() || !file.is_open() || file.peek() == std::ifstream::traits_type::eof())
    {
        return false;
    }

    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        if (file.is_open())
            file.close();
        return false;
    }
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string dateStr;
        double price;
        std::getline(ss, dateStr, ',');

        if (ss.fail() || ss.eof() || dateStr.length() != 10 || !isDateValid(dateStr))
        {
            if (file.is_open())
                file.close();
            return false;
        }
        dateStr = dateStr.substr(0, 10);
        ss >> price;
        if (ss.fail() || !ss.eof() || price < 0)
        {
            if (file.is_open())
                file.close();
            return false;
        }
        if (price >= 0)
        {
            _btcPrices[dateStr] = price;
        }
    }

    if (file.is_open())
        file.close();
    return true;
}

double BitcoinExchange::getPriceForDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _btcPrices.find(date);
    if (date < _btcPrices.begin()->first)
    {
        return _btcPrices.begin()->second;
    }
    else if (date > _btcPrices.rbegin()->first)
    {
        return _btcPrices.rbegin()->second;
    }
    if (it == _btcPrices.end())
    {
        it = _btcPrices.lower_bound(date);
        if (it != _btcPrices.begin())
        {
            --it;
        }
    }
    double price = it->second;
    if (price < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return price;
    }
    if (price > 2147483647)
    {
        std::cout << "Error: too large a number." << std::endl;
        return price;
    }
    return price;
}
