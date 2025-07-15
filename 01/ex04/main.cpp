#include "Sed.hpp"

// static std::string replacing(std::string& line, std::string& search, std::string& replace)
// {
//     std::string result;
//     size_t i = 0;

//     while (1) 
//     {
//         size_t found = line.find(search, i);
//         if (found == std::string::npos)
//         {
//             result += line.substr(i);
//             break ;
//         }
//         result += line.substr(i, found - i) + replace;
//         i = found + search.length();
//     }
//     return result;
// }


int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Number of args is not valid" << std::endl;
        return 1;
    }

    Sed sed(av[1], av[2], av[3]);

    sed.infile.open(sed.infile_str);
    if (!sed.infile.is_open() || sed.infile.fail())
    {
        std::cerr << "Error in opening the infile" << std::endl;
        return 1;
    }

    sed.outfile_str = std::string(av[1]) + ".replace";
    sed.outfile.open(sed.outfile_str.c_str());
    if (!sed.outfile.is_open() || sed.outfile.fail())
    {
        std::cerr << "Error in creating output file" << std::endl;
        sed.infile.close();
        return 1;
    }

    while (std::getline(sed.infile, sed.line))
        sed.outfile << sed.replacing(sed.line, sed.search, sed.replace) << std::endl;

    sed.outfile.close();
    sed.infile.close();

    return 0;
}