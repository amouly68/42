#include "../include/BitcoinExchange.hpp"

#include <iostream>

void fill_map(std::map<std::string, double> &rates, std::string data_file, char c)
{
    std::ifstream file;
    file.open(data_file);
    std::string line;
    std::size_t pos;
    std::string key;
    double value;

    if (file.is_open())
    {
        while(file)
        {
            std::getline(file, line);
            pos = line.find(c);
            while (line[pos] == c || line[pos] == 32)
                pos--;
            pos++;
            key = line.substr(0, pos);
            while (line[pos] == c || line[pos] == 32)
                pos++;
            value = atof(line.substr(pos).c_str());
            rates[key] = value;
        }
        file.close();
    }
    
}

void get_output(std::map<std::string, double> &rates, std::string data_file, char c)
{
    std::ifstream file;
    file.open(data_file);
    std::string line;
    std::size_t pos;
    std::string key;
    std::map<std::string, double>::iterator it;
    
    double value;

    if (file.is_open())
    {
        while(file)
        {
            std::getline(file, line);
            pos = line.find(c);
            while (line[pos] == c || line[pos] == 32)
                pos--;
            pos++;
            key = line.substr(0, pos);
            it = rates.begin();
            while ( it != rates.upper_bound(key))
                it++;
            it--;
            std::cout << "rate = " << it->second << std::endl;
            while (line[pos] == c || line[pos] == 32)
                pos++;
            value = atof(line.substr(pos).c_str());
            std::cout << key << " ==> " << value << " = " << value * it->second << std::endl;
        }
        file.close();
    }
    
}



BitcoinExchange::BitcoinExchange(void) 
{
    fill_map(_rates, "data.csv", ',');
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

void BitcoinExchange::print_input()
{
    for (std::map<std::string, double>::iterator it = _input.begin(); it != _input.end(); it++ )
        std::cout << "Date : " << it->first << "   ---- Valeur  : " << it->second << std::endl ;
}


void     BitcoinExchange::setInput(std::string input)
{
   get_output(_rates, input, '|');

}



