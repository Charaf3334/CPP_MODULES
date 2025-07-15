#include "Sed.hpp"

Sed::Sed(std::string infile_str, std::string search, std::string replace)
{
    this->infile_str = infile_str;
    this->search = search;
    this->replace = replace;
}

std::string Sed::replacing(std::string& line, std::string& search, std::string& replace)
{
    std::string result;
    size_t i = 0;

    while (1) 
    {
        size_t found = line.find(search, i);
        if (found == std::string::npos)
        {
            result += line.substr(i);
            break ;
        }
        result += line.substr(i, found - i) + replace;
        i = found + search.length();
    }
    return result;
}
