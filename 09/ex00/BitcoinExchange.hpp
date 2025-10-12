#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <map>

// parse the input.txt date and check if valid
// handle all other errors

class BitcoinExchange
{
    private:
        std::ifstream file;
        std::map<std::string, double> myMap;
        std::map<std::string, double> myMapInput;
        bool isFileEmpty(std::ifstream &file) const;
        std::string _trim(std::string str) const;
        std::string checkDate(std::string date) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string path);
        BitcoinExchange(const BitcoinExchange &theOtherObject);
        BitcoinExchange& operator=(const BitcoinExchange &theOtherObject);
        ~BitcoinExchange();
        void readDatabase(const std::string database_path);
        void checkFile(void);
};

#endif