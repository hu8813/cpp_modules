#include "BitcoinExchange.hpp"

bool isDateValid(const std::string& dateStr) {
    if (dateStr.size() != 10) {
        return false;
    }
    if (dateStr[4] != '-' || dateStr[7] != '-') {
        return false;
    }
    int year = 0, month = 0, day = 0;
    std::istringstream(dateStr.substr(0, 4)) >> year;
    std::istringstream(dateStr.substr(5, 2)) >> month;
    std::istringstream(dateStr.substr(8, 2)) >> day;
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2000) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        if (day > 29) {
            return false;
        }
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
            return false;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!std::isdigit(dateStr[i])) {
            return false;
        }
    }
    return true;
}

std::string formatDouble(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << value;
    std::string formatted = oss.str();

    while (!formatted.empty() && (formatted[formatted.size() - 1] == '0' || formatted[formatted.size() - 1] == '.')) {
        formatted.erase(formatted.size() - 1);
    }

    return formatted;
}

bool isValidInput(const std::string& input) {
    int dotCount = 0;
    int pipeCount = 0;
    int dashCount = 0;
    
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false;
            }
        } else if (input[i] == '|') {
            pipeCount++;
            if (pipeCount > 1) {
                return false;
            }
        } else if ( i < 10 && input[i] == '-') {
            dashCount++;
            if (dashCount > 2) {
                return false;
            }
        } else if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+'  && input[i] != '-') {
            return false;
        }
    }

    return true;
}


int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        BitcoinExchange exchange;
        if (!exchange.loadPrices("data.csv")) {
            std::cerr << "Error: could not load bitcoin prices." << std::endl;
            return 1;
        }

        std::ifstream inputFile(argv[1]);
        if (!inputFile.is_open()) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        std::string line;
        std::getline(inputFile, line);
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            return 1;
        }
        if (line != "date|value" && line != "date | value" && line != "date |value" && line != "date| value") {
            std::cout << "Error: bad input => " << line << std::endl;
            return 1;
        }
        while (std::getline(inputFile, line)) {
            try {
                if (line.empty() || line == "" || line.find("|") == std::string::npos || !isValidInput(line)) {
                    std::cout << "Error: bad input => " <<  line << std::endl;
                    continue;
                }
                int pos = line.find("|");
                if (line[pos + 1] && line[pos + 1] != ' ') {
                    line.insert(pos + 1, " ");
                }
                pos = line.find("|");
                if (line[pos - 1] && line[pos - 1] != ' ') {
                    line.insert(pos, " ");
                }
                pos = line.find("|");
                std::stringstream ss(line);
                std::string dateStr;
                char delimiter;
                double value;
                ss >> dateStr >> delimiter >> value;
                dateStr.erase(std::remove(dateStr.begin(), dateStr.end(), ' '), dateStr.end());
                if (ss.fail() || delimiter != '|') {
                    std::cout << "Error: bad input => " <<  line << std::endl;
                    continue;
                }
                std::string valueStr = line.substr(pos + 1);
                
                valueStr.erase(std::remove(valueStr.begin(), valueStr.end(), ' '), valueStr.end());
                if (valueStr[0] == '.')
                {
                    std::cout << "Error: bad input => " <<  valueStr << std::endl;
                    continue;
                }
                if (value <= 0) {
                    std::cout << "Error: not a positive number." << std::endl;
                    continue;
                }
                if (value > 1000) {
                    std::cout << "Error: too large a number." << std::endl;
                    continue;
                }

                if (!isDateValid(dateStr)) {
                    std::cout << "Error: bad input => " << dateStr << std::endl;
                    continue;
                }
                
                double exchangeRate = exchange.getPriceForDate(dateStr);
                if (exchangeRate == 0.0) {
                    exchangeRate = exchange.getPriceForDate("2009-01-02");
                }
                if (exchangeRate >= 0)
                {
                std::cout << dateStr << " => " << std::fixed  << formatDouble(value);
                std::cout << " = " << std::fixed  << formatDouble(exchangeRate * value) << std::endl;
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }

        inputFile.close();

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
