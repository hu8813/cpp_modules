#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    _amount = initial_deposit;
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (_amount - withdrawal < 0)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    else
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return (true);
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}


int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}   

void Account::_displayTimestamp(void)
{
    char timeString[20];
    struct tm* timeInfo;
    std::time_t currentTime;

    std::time(&currentTime);
    timeInfo = localtime(&currentTime);

    std::strftime(timeString, sizeof(timeString), "[%Y%m%d_%H%M%S] ", timeInfo);

    std::cout << timeString ;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
