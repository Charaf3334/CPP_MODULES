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
        throw std::runtime_error("Error: File is empty.");
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
        throw std::runtime_error("Error: Failed to open database.");
    if (this->isFileEmpty(database))
    {
        database.close();
        throw std::runtime_error("Error: Database file is empty.");
    }
    database.clear();
    database.seekg(0, std::ios::beg);
    while (std::getline(database, line))
    {
        line = this->_trim(line);
        if (line == "date,exchange_rate")
            continue;
        std::string date = line.substr(0, 10);
        std::string rate_str = line.substr(11, line.length());
        double rate = atof(rate_str.c_str());
        this->myMap[date] = rate;
    }
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

void BitcoinExchange::checkFileAndPrint(void)
{
    std::string line;
    int flag = 0;

    this->file.clear();
    this->file.seekg(0, std::ios::beg);
    if (!this->myMap.size())
        throw std::runtime_error("Error: Database is empty.");
    while (std::getline(this->file, line))
    {
        line = this->_trim(line);
        if (!flag && line != "date | value")
        {
            std::cerr << "Error: date | value is not present at the top of the file." << std::endl;
            flag++;
            continue;
        }
        if (line == "date | value")
        {
            if (flag > 0)
                std::cerr << "Error: date | value should be at top of the file." << std::endl;
            flag++;
            continue;
        }
        if (line == "")
        {
            std::cerr << "Error: Empty line found inside the file." << std::endl;
            flag++;
            continue;
        }
        if (!this->lineRegex(line))
        {
            std::cerr << "Error: " + line + " is not a valid line." << std::endl;
            flag++;
            continue;
        }   
        std::string date = checkDate(line);
        if (date == "")
        {
            flag++;
            continue;
        }
        double value = checkValue(line);
        if (value == -1)
        {
            flag++;
            continue;
        }
        this->printingValues(date, value);
        flag++;
    }
}

std::string BitcoinExchange::checkDate(std::string line) const
{
    std::string newDate = line.substr(0, 10);

    std::string year, month, day;

    year = newDate.substr(0, 4);
    if (atoi(year.c_str()) < 2009 || atoi(year.c_str()) > 2022)
    {
        std::cerr << "Error: " + year + " is not a valid year." << std::endl;
        return "";
    }
    month = newDate.substr(5, 2);
    if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
    {
        std::cerr << "Error: " + month + " is not a valid month." << std::endl;
        return "";
    }
    day = newDate.substr(8, 2);
    if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
    {
        std::cerr << "Error: " + day + " is not a valid day." << std::endl;
        return "";
    }
    return newDate;
}

double BitcoinExchange::checkValue(const std::string line) const
{
    std::string value_str = line.substr(13, line.length());
    double value = atof(value_str.c_str());
    if (value < 0 || value > 1000)
    {
        std::cerr << "Error: " + value_str + " is not a valid value." << std::endl;
        return -1;
    }
    return value;
}

void BitcoinExchange::printingValues(const std::string date, double value)
{
    std::map<std::string, double>::iterator it2 = this->myMap.lower_bound(date);

    if (it2 != this->myMap.end() && it2->first == date)
        std::cout << date << " => " << value << " = " << (value * it2->second) << std::endl;

    else if (it2 != this->myMap.begin())
    {
        --it2;
        std::cout << date << " => " << value << " = " << (value * it2->second) << std::endl;
    }
    else
        std::cerr << "No valid date in the database that matches or its lower than " << date << "." << std::endl;
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

bool BitcoinExchange::lineRegex(const std::string line) const
{
    bool has_digit = false;
    bool has_dot = false;
    size_t i = 13;

    if (line.size() < 14)
        return false;
    for (int j = 0; j < 10; j++)
    {
        if (j == 4 || j == 7)
        {
            if (line[j] != '-')
                return false;
        }
        else if (!isdigit(line[j]))
            return false;
    }
    if (line.substr(10, 3) != " | ")
        return false;
    if (line.size() == 13)
        return false;
    
    if (line[i] == '-')
        i++;
    for (; i < line.size(); ++i)
    {
        char c = line[i];
        if (isdigit(c))
            has_digit = true;
        else if (c == '.' && !has_dot)
            has_dot = true;
        else 
            return false;
    }
    return has_digit;
}