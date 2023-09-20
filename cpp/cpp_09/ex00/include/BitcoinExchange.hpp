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

    BitcoinExchange &           operator=( BitcoinExchange const & rhs ); 
    void                        print_rates(void);
    void                        print_input(void);
    //std::string                 getInput();
    void                        setInput(std::string);          

private:
    std::map<std::string, double>   _rates;
    std::map<std::string, double>   _input;



};

#endif 
