#include "pch.h"
#include "CppUnitTest.h"
#include "../ValidAndConvert/Converter.hpp"
#include "../ValidAndConvert/Validator.hpp"
#include <random>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		// VALIDATOR

		TEST_METHOD(ValidatorIntTrue)
		{
			Assert::IsTrue(Validator::isInt("0"));
			Assert::IsTrue(Validator::isInt("123"));
			Assert::IsTrue(Validator::isInt("-123"));
		}

		TEST_METHOD(ValidatorShortTrue)
		{
			Assert::IsTrue(Validator::isShort("0"));
			Assert::IsTrue(Validator::isShort("123"));
			Assert::IsTrue(Validator::isShort("-123"));
		}

		TEST_METHOD(ValidatorDoubleTrue)
		{
			Assert::IsTrue(Validator::isDouble("0"));
			Assert::IsTrue(Validator::isDouble("12.3"));
			Assert::IsTrue(Validator::isDouble("-12.3"));
			Assert::IsTrue(Validator::isDouble("3.14159"));
			Assert::IsTrue(Validator::isDouble("1e10"));
		}

		TEST_METHOD(ValidatorStringTrue)
		{
			Assert::IsTrue(Validator::isString("a"));
			Assert::IsTrue(Validator::isString("abc"));
			Assert::IsTrue(Validator::isString("123"));
		}

		TEST_METHOD(ValidatorLongTrue)
		{
			Assert::IsTrue(Validator::isLong("0"));
			Assert::IsTrue(Validator::isLong("123"));
			Assert::IsTrue(Validator::isLong("-123"));
		}

		TEST_METHOD(ValidatorIntFalse)
		{
			Assert::IsFalse(Validator::isInt("123a"));
			Assert::IsFalse(Validator::isInt("12.3"));
			Assert::IsFalse(Validator::isInt(""));
			Assert::IsFalse(Validator::isInt("   "));
		}

		TEST_METHOD(ValidatorShortFalse)
		{
			Assert::IsFalse(Validator::isShort("123a"));
			Assert::IsFalse(Validator::isShort("12.3"));
			Assert::IsFalse(Validator::isShort(""));
			Assert::IsFalse(Validator::isShort("   "));
		}

		TEST_METHOD(ValidatorDoubleFalse)
		{
			Assert::IsFalse(Validator::isDouble("abc"));
			Assert::IsFalse(Validator::isDouble(""));
			Assert::IsFalse(Validator::isDouble("12.3.4"));
			Assert::IsFalse(Validator::isDouble("   "));
			Assert::IsFalse(Validator::isDouble("12,3")); // запятая
		}

		TEST_METHOD(ValidatorStringFalse)
		{
			Assert::IsFalse(Validator::isString(" "));
			Assert::IsFalse(Validator::isString(""));
		}

		TEST_METHOD(ValidatorLongFalse)
		{
			Assert::IsFalse(Validator::isLong("123a"));
			Assert::IsFalse(Validator::isLong("12.3"));
			Assert::IsFalse(Validator::isLong(""));
			Assert::IsFalse(Validator::isLong("   "));
		}

		TEST_METHOD(IsIntOutOf)
		{
			Assert::IsTrue(Validator::isInt("2147483647"));   // INT_MAX
			Assert::IsTrue(Validator::isInt("-2147483648"));  // INT_MIN
			
			Assert::IsFalse(Validator::isInt("2147483648"));
			Assert::IsFalse(Validator::isInt("-2147483649"));
		}

		TEST_METHOD(IsShortOutOf)
		{
			Assert::IsTrue(Validator::isShort("32767"));   // SHRT_MAX
			Assert::IsTrue(Validator::isShort("-32768"));  // SHRT_MIN

			Assert::IsFalse(Validator::isShort("32768"));
			Assert::IsFalse(Validator::isShort("-32769"));
		}

		TEST_METHOD(IsLongOutOf)
		{
			Assert::IsTrue(Validator::isLong("9223372036854775807"));   // LONG_MAX
			Assert::IsTrue(Validator::isLong("-9223372036854775808"));  // LONG_MIN

			Assert::IsFalse(Validator::isLong("9223372036854775808"));
			Assert::IsFalse(Validator::isLong("-9223372036854775809"));
		}

		TEST_METHOD(IsDoubleOutOf)
		{
			Assert::IsTrue(Validator::isDouble("1e308"));
			Assert::IsTrue(Validator::isDouble("-1e308"));

			Assert::IsFalse(Validator::isDouble("1e9999"));   // overflow -> inf
			Assert::IsFalse(Validator::isDouble("-1e9999"));  // -inf
		}

		TEST_METHOD(isInstanceTrue)
		{
			class Animal {};

			Animal animal, animalXmpl;

			Assert::IsTrue(Validator::isInstanceOf(animal, animalXmpl));
		}

		TEST_METHOD(isInstanceFalse)
		{
			class Animal {};
			class Dog {};

			Animal animal; Dog dog;

			Assert::IsFalse(Validator::isInstanceOf(animal, dog));
		}

		// CONVERTOR

		TEST_METHOD(ConverterToInt)
		{
			Assert::AreEqual(1, Converter::toInt(std::string("1")));
		}

		TEST_METHOD(ConverterToDouble)
		{
			Assert::AreEqual(1.0, Converter::toDouble(std::string("1")), 0.001);
		}

		TEST_METHOD(ConverterToLong)
		{
			Assert::AreEqual(long long(9223372036854775806), Converter::toLong(std::string("9223372036854775806")));
		}

		TEST_METHOD(ConverterToShort)
		{
			Assert::AreEqual(short(32767), Converter::toShort(std::string("32767")));
		}

		TEST_METHOD(ConverterToString)
		{
			Assert::AreEqual(std::string("333"), Converter::toString(333));
		}
	};
}

