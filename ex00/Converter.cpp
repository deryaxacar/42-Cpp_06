/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:20:34 by deryacar          #+#    #+#             */
/*   Updated: 2025/02/25 19:20:34 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

bool ScalarConverter::isDisplayableChar(int value) {
    return (value >= 32 && value <= 126);
}

void ScalarConverter::convert(const string &input) {
    try {
        if (input == "nan" || input == "-nan" || input == "nanf" || input == "-nanf") {
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: nanf" << endl;
            cout << "double: nan" << endl;
            return;
        }

        if (input == "inf" || input == "-inf" || input == "inff" || input == "-inff") {
            cout << "char: impossible" << endl;
            cout << "int: impossible" << endl;
            cout << "float: " << input << "f" << endl;
            cout << "double: " << input << endl;
            return;
        }

        int intValue = atoi(input.c_str());
        toChar(intValue);

    } catch (...) {
        cout << "char: impossible" << endl;
    }

    try {
        int i = atoi(input.c_str());
        cout << "int: " << i << endl;
    } catch (...) {
        cout << "int: impossible" << endl;
    }

    try {
        float f = atof(input.c_str());
        cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << endl;
    } catch (...) {
        cout << "float: impossible" << endl;
    }

    try {
        double d = atof(input.c_str());
        cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << endl;
    } catch (...) {
        cout << "double: impossible" << endl;
    }
}

char ScalarConverter::toChar(int value) {
    char c = static_cast<char>(value);

    if (value > numeric_limits<char>::max() || value < numeric_limits<char>::min())
        cout << "char: impossible" << endl;
    else if (!isDisplayableChar(c))
        cout << "char: Non displayable" << endl;
    else
        cout << "char: '" << c << "'" << endl;
    return c;
}

int ScalarConverter::toInt(int value) {
    return value;
}

float ScalarConverter::toFloat(float value) {
    if (value != value)
        return numeric_limits<float>::quiet_NaN();
    else if (value == numeric_limits<float>::infinity())
        return numeric_limits<float>::infinity();
    else if (value == -numeric_limits<float>::infinity())
        return -numeric_limits<float>::infinity();
    return value;
}

double ScalarConverter::toDouble(double value) {
    if (value != value)
        return numeric_limits<double>::quiet_NaN();
    else if (value == numeric_limits<double>::infinity())
        return numeric_limits<double>::infinity();
    else if (value == -numeric_limits<double>::infinity())
        return -numeric_limits<double>::infinity();
    return value;
}
