#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}


int Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}


int Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}


int Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}


void    Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:";
    std::cout << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}


Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}


Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}



void    Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
    std::cout << ";amount:" << this->_amount << ";nb_deposits" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal <= this->_amount)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        std::cout << ";amount:" << this->_amount << ";nb_withdrawals" << this->_nbWithdrawals << std::endl;
        return (true);
    }
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
    return (false);

}


int Account::checkAmount( void ) const
{
    return (this->_amount);
}


void    Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals" << this->_nbWithdrawals << std::endl;
}


void    Account::_displayTimestamp( void )
{
    std::time_t now;
    char        buf[19];

    now = time(nullptr);
    if (std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&now))) {
        std::cout << buf;
    }
}

int Account::_nbAccounts = 0;


int Account::_totalAmount = 0;


int Account::_totalNbDeposits = 0;


int Account::_totalNbWithdrawals = 0;
