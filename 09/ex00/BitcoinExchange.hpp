#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
    private:
        std::ifstream file;
        std::map<std::string, double> myMap;

        bool isFileEmpty(std::ifstream &file) const;
        std::string _trim(std::string str) const;
        bool lineRegex(const std::string line) const;
        std::string checkDate(std::string line) const;
        double checkValue(const std::string line) const;
        void printingValues(const std::string date, double value);
        BitcoinExchange(const BitcoinExchange &theOtherObject);
        BitcoinExchange& operator=(const BitcoinExchange &theOtherObject);
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string path);
        ~BitcoinExchange();
        void readDatabase(const std::string database_path);
        void checkFileAndPrint(void);
};

#endif
