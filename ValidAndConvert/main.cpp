#include <windows.h>
#include <iostream>

#include "Converter.hpp"
#include "Validator.hpp"

class Animal {};
class Dog : public Animal {};

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

    //int number;
    //std::string text;

    //Converter::stringToInt("123", number);
    //std::cout << number << "\n";

    //Converter::intToString(456, text);
    //std::cout << text << "\n";

    //std::cout << Validator::isInt("999") << "\n";
    //std::cout << Validator::isInt("ААА") << "\n";
    //std::cout << Validator::isDouble("12.5") << "\n";

    //Animal a;
    //Dog d;

    //std::cout << Validator::isInstanceOf(a, d) << "\n";

    auto value = Converter::toInt("200");

    std::cout << value + 100;

   

    return 0;
}