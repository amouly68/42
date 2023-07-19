
#include Account.hpp
#include <ctime>
#include <iomanip>
#include <iostream>

Account::Account( int initial_deposit ){

}

Account::Account( void ){

}

Account::~Account( void ){

}

static int	Account::getNbAccounts( void ){
    return(this->_nbAccounts);
}

static int	Account::getTotalAmount( void ){
    return (this->_totalAmount);
}

static int	Account::getNbDeposits( void ){
    return(this->_totalNbDeposits);

}

static int	Account::getNbWithdrawals( void ){
    return(this->_totalNbWithdrawals);
}

static void	Account::displayAccountsInfos( void ){

}

void	Account::makeDeposit( int deposit ){

}

bool	Account::makeWithdrawal( int withdrawal ){

}

int		Account::checkAmount( void ) const{

}
void	Account::displayStatus( void ) const{

}

static void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm *TimeInfo = stdd::localtime(&now);

    std::cout << '['
    std::cout << std::setw(4) << std::setfill('0') <<  (TimeInfo->tm_year + 1900)
    std::cout << std::setw(2) << std::setfill('0') <<  (TimeInfo->tm_mon + 1)
    std::cout << std::setw(2) << std::setfill('0') <<  (TimeInfo->tm_mday)
    std::cout << '_'
    std::cout << std::setw(2) << std::setfill('0') <<  (TimeInfo->tm_hour)
    std::cout << std::setw(2) << std::setfill('0') <<  (TimeInfo->tm_min)
    std::cout << std::setw(2) << std::setfill('0') <<  (TimeInfo->tm_sec)
    std::cout << "] ";
}