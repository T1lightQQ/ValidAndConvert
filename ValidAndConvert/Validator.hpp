#pragma once

#include <string>
#include <typeinfo>

class Validator {
public:
    static bool isInt(const std::string& str);
    static bool isShort(const std::string& str);
    static bool isString(const std::string& str);
    static bool isLong(const std::string& str);
    static bool isDouble(const std::string& str);

    template<typename T1, typename T2>
    static bool isInstanceOf(const T1& obj1, const T2& obj2) {
        return typeid(obj1) == typeid(obj2);
    }
};
