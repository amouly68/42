#include "../include/BitcoinExchange.hpp"

#include <iostream>

void fill_map(std::map<std::string, double> &rates, std::string data_file)
{
    std::ifstream file(data_file);
    std::string line;
    std::size_t pos;
    std::string key;
    double value;

    if (file.is_open())
    {
        while(file)
        {
            std::getline(file, line);
            pos = line.find(',');
            key = line.substr(0, pos);
            pos++;
            value = std::stod(line.substr(pos));
            rates[key] = value;
        }
    }
}


BitcoinExchange::BitcoinExchange(void) 
{
    fill_map(_rates, "data.csv");

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) 
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange() 
{
    // TODO: Implémenter le destructeur
}

BitcoinExchange &    BitcoinExchange::operator=( BitcoinExchange const & rhs ) 
{
    (void) rhs;
    return (*this);
}


void BitcoinExchange::print_rates()
{
    for (std::map<std::string, double>::iterator it = _rates.begin(); it != _rates.end(); it++ )
        std::cout << "Date : " << it->first << "   ---- Valeur  : " << it->second << std::endl ;
}


