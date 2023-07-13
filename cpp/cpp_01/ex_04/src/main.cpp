
#include <unistd.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>


void search_and_replace(std::string *line, std::string str, int pos)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".|");
    }
    else
        str.append("|");
    line->replace(pos - str.length(), str.length(), str);
}

int main(int ac, char** av) 
{
   if (ac == 4)
   {
        std::string     name_input(av[1]);
        std::string     s1(av[2]);
        std::string     s2(av[3]);

        std::ifstream f_input(name_input);
        std::ofstream f_output(name_input.append(".replace"));
        std::string  output;
        std::filebuf* inbuf = f_input.rdbuf();

        char c = inbuf->sbumpc();
        while (c != EOF)
        {
            if (c == s1.at(0))
               std::cout << "YOOO" << std::endl;
            output.push_back(c);
            c = inbuf->sbumpc();
        }
        f_input.close();
        f_output << output;
        return(0);
   }
}