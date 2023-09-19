#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>
#include <fstream>

class BitcoinExchange {
public:
    
    BitcoinExchange(void);
    BitcoinExchange( BitcoinExchange const & src );
    ~BitcoinExchange();

    BitcoinExchange & operator=( BitcoinExchange const & rhs ); 
    void print_rates(void);

private:
    std::map<std::string, double> _rates;


};

#endif 
