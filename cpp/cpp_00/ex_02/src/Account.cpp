#include Account.hpp

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