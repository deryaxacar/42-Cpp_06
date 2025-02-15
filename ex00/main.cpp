#include "Converter.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        cout << "Error: Argument Error!" << endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
