#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
    public:
        std::string infile_str;
        std::string outfile_str;
        std::ofstream outfile;
        std::ifstream infile;
        std::string search;
        std::string replace;
        std::string line;
        std::string replacing(std::string& line, std::string& search, std::string& replace);
        Sed(std::string infile_str, std::string search, std::string replace);
};

#endif