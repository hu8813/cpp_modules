#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        BitcoinExchange exchange;
        if (!exchange.loadPrices("data.csv"))
        {
            std::cerr << "Error: could not load bitcoin prices." << std::endl;
            return 1;
        }

        std::ifstream inputFile(argv[1]);
        if (inputFile.bad() || !inputFile.is_open())
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        std::string line;
        std::getline(inputFile, line);
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            if (inputFile.is_open())
                inputFile.close();
            return 1;
        }
        if (line != "date|value" && line != "date | value" && line != "date |value" && line != "date| value")
        {
            std::cout << "Error: bad input => " << line << std::endl;
            if (inputFile.is_open())
                inputFile.close();
            return 1;
        }
        while (std::getline(inputFile, line))
        {
            try
            {
                if (line.empty() || line == "" || line.find("|") == std::string::npos || !exchange.isValidInput(line))
                {
                    std::cout << "Error: bad input => " << line << std::endl;
                    continue;
                }
                int pos = line.find("|");
                if (line[pos + 1] && line[pos + 1] != ' ')
                {
                    line.insert(pos + 1, " ");
                }
                pos = line.find("|");
                if (line[pos - 1] && line[pos - 1] != ' ')
                {
                    line.insert(pos, " ");
                }
                pos = line.find("|");
                std::stringstream ss(line);
                std::string dateStr;
                char delimiter;
                double value;
                ss >> dateStr >> delimiter >> value;

                if (ss.fail() || delimiter != '|' || !ss.eof())
                {
                    std::cout << "Error: bad input => " << line << std::endl;
                    continue;
                }
                dateStr.erase(std::remove(dateStr.begin(), dateStr.end(), ' '), dateStr.end());
                std::string valueStr = line.substr(pos + 1);

                valueStr.erase(std::remove(valueStr.begin(), valueStr.end(), ' '), valueStr.end());
                if ((valueStr[0] && !isdigit(valueStr[0])) || valueStr.find(" ") != std::string::npos)
                {
                    std::cout << "Error: bad input => " << line << std::endl;
                    continue;
                }
                if (value <= 0)
                {
                    std::cout << "Error: not a positive number." << std::endl;
                    continue;
                }
                if (value > 1000)
                {
                    std::cout << "Error: too large a number." << std::endl;
                    continue;
                }

                if (!exchange.isDateValid(dateStr))
                {
                    std::cout << "Error: bad input => " << dateStr << std::endl;
                    continue;
                }

                double exchangeRate = exchange.getPriceForDate(dateStr);
                if (exchangeRate >= 0)
                {
                    std::cout << dateStr << " => " << std::fixed << exchange.formatDouble(value);
                    std::cout << " = " << std::fixed << exchange.formatDouble(exchangeRate * value) << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        if (inputFile.is_open())
            inputFile.close();

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
