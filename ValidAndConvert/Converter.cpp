#include "Converter.hpp"

#include <limits>
#include <stdexcept>

//
// ==================== TO INT ====================
//

int Converter::toInt(const std::string& value)
{
    size_t pos;

    int result = std::stoi(value, &pos);

    if (pos != value.length())
    {
        throw std::invalid_argument("Invalid int string");
    }

    return result;
}

int Converter::toInt(int value)
{
    return value;
}

int Converter::toInt(double value)
{
    if (value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min())
    {
        throw std::out_of_range("Double out of int range");
    }

    return static_cast<int>(value);
}

int Converter::toInt(char value)
{
    if (value >= '0' && value <= '9')
    {
        return value - '0';
    }

    return static_cast<int>(value);
}

//
// ==================== TO DOUBLE ====================
//

double Converter::toDouble(const std::string& value)
{
    size_t pos;

    double result = std::stod(value, &pos);

    if (pos != value.length())
    {
        throw std::invalid_argument("Invalid double string");
    }

    return result;
}

double Converter::toDouble(int value)
{
    return static_cast<double>(value);
}

double Converter::toDouble(double value)
{
    return value;
}

double Converter::toDouble(char value)
{
    return static_cast<double>(value);
}

//
// ==================== TO LONG ====================
//

long long Converter::toLong(const std::string& value)
{
    size_t pos;

    long long result = std::stoll(value, &pos);

    if (pos != value.length())
    {
        throw std::invalid_argument("Invalid long string");
    }

    return result;
}

long long Converter::toLong(int value)
{
    return static_cast<long long>(value);
}

long long Converter::toLong(double value)
{
    if (value > std::numeric_limits<long long>::max() ||
        value < std::numeric_limits<long long>::min())
    {
        throw std::out_of_range("Double out of long range");
    }

    return static_cast<long long>(value);
}

long long Converter::toLong(char value)
{
    return static_cast<long long>(value);
}

//
// ==================== TO SHORT ====================
//

short Converter::toShort(const std::string& value)
{
    size_t pos;

    int result = std::stoi(value, &pos);

    if (pos != value.length())
    {
        throw std::invalid_argument("Invalid short string");
    }

    if (result > std::numeric_limits<short>::max() ||
        result < std::numeric_limits<short>::min())
    {
        throw std::out_of_range("Short out of range");
    }

    return static_cast<short>(result);
}

short Converter::toShort(int value)
{
    if (value > std::numeric_limits<short>::max() ||
        value < std::numeric_limits<short>::min())
    {
        throw std::out_of_range("Int out of short range");
    }

    return static_cast<short>(value);
}

short Converter::toShort(double value)
{
    if (value > std::numeric_limits<short>::max() ||
        value < std::numeric_limits<short>::min())
    {
        throw std::out_of_range("Double out of short range");
    }

    return static_cast<short>(value);
}

short Converter::toShort(char value)
{
    return static_cast<short>(value);
}

//
// ==================== TO STRING ====================
//

std::string Converter::toString(const std::string& value)
{
    return value;
}

std::string Converter::toString(int value)
{
    return std::to_string(value);
}

std::string Converter::toString(double value)
{
    return std::to_string(value);
}

std::string Converter::toString(char value)
{
    return std::string(1, value);
}