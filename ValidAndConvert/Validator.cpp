#include "Validator.hpp"
#include <limits>
#include <string>
#include <cctype>

bool Validator::isInt(const std::string& str) {
    try {
        size_t pos;
        std::stoi(str, &pos);
        return pos == str.length();
    }
    catch (...) {
        return false;
    }
}

bool Validator::isShort(const std::string& str) {
    try {
        size_t pos;
        int value = std::stoi(str, &pos);

        if (pos != str.length()) return false;

        return value >= std::numeric_limits<short>::min() &&
            value <= std::numeric_limits<short>::max();
    }
    catch (...) {
        return false;
    }
}

bool Validator::isString(const std::string& str) {
    if (str.empty()) return false;

    for (char c : str) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            return true;
        }
    }

    return false;
}

bool Validator::isLong(const std::string& str)
{
    try {
        size_t pos = 0;
        std::stoll(str, &pos);

        if (pos != str.length())
            return false;

        return true;
    }
    catch (...) {
        return false;
    }
}

bool Validator::isDouble(const std::string& str) {
    try {
        size_t pos;
        std::stod(str, &pos);
        return pos == str.length();
    }
    catch (...) {
        return false;
    }
}