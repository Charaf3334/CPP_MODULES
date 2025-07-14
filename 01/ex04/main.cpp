#include <iostream>
#include <fstream>

static std::string replacing(std::string& line, std::string& search, std::string& replace)
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

int main(int ac, char **av)
{
    if (ac != 4) 
    {
        std::cerr << "Number of args is not valid" << std::endl;
        return 1;
    }
    
    std::ifstream infile(av[1]);
    if (!infile.is_open() || infile.fail()) {
        std::cerr << "Error in opening the infile" << std::endl;
        return 1;
    }

    std::string outfile_str = std::string(av[1]) + ".replace";
    std::ofstream outfile(outfile_str.c_str());
    if (!outfile.is_open() || outfile.fail()) 
    {
        std::cerr << "Error in creating output file" << std::endl;
        infile.close();
        return 1;
    }

    std::string search = av[2];
    std::string replace = av[3];
    std::string line;

    while (std::getline(infile, line))
        outfile << replacing(line, search, replace) << std::endl;

    outfile.close();
    infile.close();
    return 0;
}