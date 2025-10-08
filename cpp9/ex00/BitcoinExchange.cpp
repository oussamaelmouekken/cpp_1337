#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default constructor called" << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {
    std::cout << "Copy constructor called" << std::endl;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        data = other.data;
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor called" << std::endl;
}

std::string BitcoinExchange::trim(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isspace(*it))
        ++it;
    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && std::isspace(*rit))
        ++rit;
    return std::string(it, rit.base());
}

bool BitcoinExchange::isLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year, month, day;
    if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3)
        return false;
    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;
    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    
    return day <= daysInMonth[month - 1];
}

void BitcoinExchange::readData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open database file.");
    }
    
    std::string line;
    std::getline(file, line); // skip header
    while(std::getline(file, line))
    {
        if (line.empty())
            continue;
            
        std::stringstream all_line(line);
        std::string str, price;
        if(std::getline(all_line, str, ',') && std::getline(all_line, price))
        {
            std::istringstream iss(price);
            float price_float;
            if (!(iss >> price_float) || !iss.eof())
            {
                throw std::runtime_error("Error: invalid price in database: " + price);
            }
            data[str] = price_float;
        }
        else
        {
            throw std::runtime_error("Error: invalid format in database: " + line);
        }
    }
}

void BitcoinExchange::processFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        if(line.empty())
            continue;
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = BitcoinExchange::trim(line.substr(0, pos));
        std::string valueStr = BitcoinExchange::trim(line.substr(pos + 1));
        
        // Validate date format
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        // Validate and parse value
        std::istringstream iss(valueStr);
        float value;
        if (!(iss >> value) || !iss.eof()) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000.0f) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, float>::const_iterator it = data.lower_bound(date);
        if (it == data.end() || it->first != date) {
            if (it == data.begin()) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it;
        }
        float result = value * it->second;
        std::cout << date << " => " << value << " = ";
        if (result * 10 == static_cast<int>(result * 10))
            std::cout << std::fixed << std::setprecision(1) << result << std::endl;
        else
            std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    }
}
