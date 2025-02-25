#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>

using std::string;
using std::cout;
using std::endl;
using std::numeric_limits;

class ScalarConverter{
    
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter(void);

    public:
        static bool isDisplayableChar(int value);
        static void convert(const string &input);

        static char toChar(int value);
        static int toInt(int value);
        static float toFloat(float value);
        static double toDouble(double value);
};