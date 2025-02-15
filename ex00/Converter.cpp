#include "Converter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    return *this;
}

bool ScalarConverter::isDisplayableChar(int value) {
    return ((value >= 32) && (value <= 126));
}

void ScalarConverter::convert(const string &input) {
    try {
        int intValue = std::stoi(input);
        char c = toChar(intValue);
    } catch (const exception &e) {
        cout << "char: impossible" << endl;
    }

    try {
        int i = toInt(std::stoi(input));
        cout << "int: " << i << endl;
    } catch (const exception &e) {
        cout << "int: impossible" << endl;
    }

    try {
        float f = toFloat(std::stof(input));
        cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << endl;
    } catch (const exception &e) {
        cout << "float: impossible" << endl;
    }

    try {
        double d = toDouble(std::stod(input));
        cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << endl;
    } catch (const exception &e) {
        cout << "double: impossible" << endl;
    }
}

char ScalarConverter::toChar(int value) {
    char c = static_cast<char>(value);

    if (!isDisplayableChar(c))
        cout << "char: Non displayable" << endl;
    else
        cout << "char: '" << c << "'" << endl;
    return c;
}

int ScalarConverter::toInt(int value) {
    return (value);
}

float ScalarConverter::toFloat(float value) {
    if (std::isnan(value))
        return NAN;
    else if (std::isinf(value))
        return ((value > 0) ? INFINITY : -INFINITY);
    return (value);
}

double ScalarConverter::toDouble(double value) {
    if (std::isnan(value))
        return NAN;
    else if (std::isinf(value))
        return ((value > 0) ? INFINITY : -INFINITY);
    return (value);
}