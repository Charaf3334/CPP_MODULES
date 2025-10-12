#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    throw std::runtime_error("Error: Can't work with empty object.");
}

BitcoinExchange::BitcoinExchange(const std::string path) : file(path.c_str())
{
    if (!this->file.is_open())
        throw std::runtime_error("Error: Failed to open file.");
    if (this->isFileEmpty(this->file))
        throw std::runtime_error("Error: file is empty.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &theOtherObject)
{
    static_cast<void>(theOtherObject);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &theOtherObject)
{
    if (this != &theOtherObject)
        static_cast<void>(theOtherObject);
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    this->file.close();
}

void BitcoinExchange::readDatabase(const std::string database_path)
{
    std::ifstream database(database_path.c_str());
    std::string line;

    if (!database.is_open())
        throw std::runtime_error("Error: failed to open database.");
    if (this->isFileEmpty(database))
    {
        database.close();
        throw std::runtime_error("Error: database file is empty.");
    }
    database.clear();
    database.seekg(0, std::ios::beg);
    while (std::getline(database, line))
    {
        if (line == "date,exchange_rate")
            continue;
        std::string date = line.substr(0, 10);
        std::string rate_str = line.substr(11, line.length());
        double rate = atof(rate_str.c_str());
        this->myMap[date] = rate;
    }

    // std::map<std::string, double>::iterator it;
    // for (it = this->myMap.begin(); it != this->myMap.end(); ++it)
    //     std::cout << it->first << "->" << it->second << std::endl;
    
    database.close();
}

bool BitcoinExchange::isFileEmpty(std::ifstream &file) const
{
    char c;

    while(file.get(c))
    {
        if (!std::isspace(static_cast<unsigned char>(c)))
            return false;
    }
    return true;
}

void BitcoinExchange::checkFile(void)
{
    std::string line;
    int flag = 0;

    this->file.clear();
    this->file.seekg(0, std::ios::beg);
    while (std::getline(this->file, line))
    {
        line = this->_trim(line);
        if (line == "date | value")
        {
            if (flag > 0)
                throw std::runtime_error("Error: date | value should be at top of the file.");
            continue;
        }
        if (line == "")
            throw std::runtime_error("Error: empty line found inside the file.");
        if (line.length() > 17)
            throw std::runtime_error("Error: " + line + " is not a valid line.");
            
        std::string date = checkDate(line);
        flag++;
    }
}

std::string BitcoinExchange::checkDate(std::string date) const
{
    std::string newDate = date.substr(0, 10);
    std::cout << newDate << std::endl;

    std::string year, month, day;

    year = newDate.substr(0, 4);
    // month = newDate.substr()

    return date;
}

std::string BitcoinExchange::_trim(std::string str) const
{
	size_t start = 0;
	size_t end = str.length();

	while (start < str.length())
	{
		if (!std::isspace(str[start]))
			break;
		start++;
	}
	while (end > start)
	{
		if (!std::isspace(str[end - 1]))
			break;
		end--;
	}
	return str.substr(start, end - start);
}