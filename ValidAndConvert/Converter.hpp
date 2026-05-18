#pragma once

#include <string>
#include <optional>
#include <limits>

class Converter {
public:

    static int toInt(const std::string& value);
    static int toInt(int value);
    static int toInt(double value);
    static int toInt(char value);

    // TO DOUBLE
    static double toDouble(const std::string& value);
    static double toDouble(int value);
    static double toDouble(double value);
    static double toDouble(char value);

    // TO LONG LONG
    static long long toLong(const std::string& value);
    static long long toLong(int value);
    static long long toLong(double value);
    static long long toLong(char value);

    // TO SHORT
    static short toShort(const std::string& value);
    static short toShort(int value);
    static short toShort(double value);
    static short toShort(char value);

    // TO STRING
    static std::string toString(const std::string& value);
    static std::string toString(int value);
    static std::string toString(double value);
    static std::string toString(char value);
};