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



bool valid_date(std::string date)
{
    int year;
    int month;
    int day;
    int daysInMonth;
    
    if (date.length()!= 10)
        return false;
    
    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false; 

    if (year < 0 || month < 1 || month > 12 || day < 1) 
        return false;
    
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29; 
        } else {
            daysInMonth = 28; 
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30; 
    } else 
        daysInMonth = 31; 
    if (day > daysInMonth) 
        return false;
    
    if (year < 2009 || (year == 2009 && month == 01 && day == 01))
        return false;
    
    if (year > 2022 || (year == 2022 && month > 03) || (year == 2022 && month == 03 && day > 29))
        return false;
    return true;
}

bool has_digit(std::string line)
{
    return std::any_of(line.begin(), line.end(), ::isdigit);
}

void get_output(std::map<std::string, double> &rates, std::string data_file, char c)
{
    std::ifstream file;
    file.open(data_file);
    std::string line;
    std::size_t pos;
    std::string date;
    std::map<std::string, double>::iterator it;
    double value;

    if (file.is_open())
    {
        while(std::getline(file, line) )
        {
            if (has_digit(line))
            {
                pos = line.find(c);
                if (pos != std::string::npos)
                {
                    while (line[pos] == c || line[pos] == 32)
                        pos--;
                    pos++;
                    date = line.substr(0, pos);
                }
                else
                    date = line;
                if (valid_date(date))
                {
                    it = rates.begin();
                    while ( it != rates.upper_bound(date))
                        it++;
                    it--;
                    while (line[pos] == c || line[pos] == 32)
                        pos++;
                    value = atof(line.substr(pos).c_str());
                    if (value < 0)
                        std::cout << "Error: not a positive number " << std::endl;
                    else if (value > 1000)
                        std::cout << "Error: too large a number " << std::endl;
                    else
                        std::cout << date << " ==> " << value << " = " << value * it->second << std::endl;
                } else
                    std::cout << "Error: bad input ==> " << date << std::endl;
            }

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



