#include "Converter.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cout << "Error: This program accepts only 1 argument!" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
