
#include <unistd.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>


void ft_replace(std::string *string, const std::string& str_to_be_replaced, const std::string& str_that_replace)
{
    size_t i = 0;
    while (string->find(str_to_be_replaced, i) != std::string::npos)
    {    
        i = string->find(str_to_be_replaced, i);
        string->erase(i, str_to_be_replaced.length());
        string->insert(i, str_that_replace);
        i += str_that_replace.length();     
    }
}


int main(int ac, char** av) 
{
   if (ac == 4)
   {
        std::string     name_input(av[1]);
        std::string     s1(av[2]);
        std::string     s2(av[3]);

        std::ifstream f_input(name_input);
        if (f_input.fail())
        {
            std::cout <<  "problem with input file" << std::endl;
            return (1);
        }
        std::ofstream f_output(name_input.append(".replace"));
        if (f_output.fail())
        {
            std::cout <<  "problem with output file" << std::endl;
            return (2);
        }
        std::string  output;

        // std::filebuf* inbuf = f_input.rdbuf();

        // char c = inbuf->sbumpc();
        // while (c != EOF)
        // {
        //     output.push_back(c);
        //     c = inbuf->sbumpc();
        // }
        
        std::getline(f_input, output, '\0' );
        ft_replace(&output, s1, s2);
        f_output << output;
        f_output.close();
        f_input.close();
   }
   else
        std::cout << "wrong number of arguments" << std::endl;
    return (0);
}