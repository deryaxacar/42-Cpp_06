#include "Serializer.hpp"

int main()
{
    Data *ds = new Data;
    ds->a = 42;
    ds->b = ds->a * 1e-2;

    cout << endl << "\033[0;36m-----------------------------------------------" << endl;
    cout << "\033[0;32mBefore: \033[0m\033[0;36m" << ds << endl;
    uintptr_t rawPtr = Serializer::serialize(ds);
    cout << "\033[0;31mAfter: \033[0m\033[0;36m" << rawPtr << endl;
    cout << "-----------------------------------------------" << endl << endl;
    cout << "\033[0;37m-----------------------------------------------" << endl;

    Data *tmp = NULL;
    tmp = Serializer::deserialize(rawPtr);
    cout << "\033[0;34mBefore: \033[0m\033[0;37m" << tmp << endl;
    cout << "\033[0;35mtmp->a: \033[0m\033[0;37m" << tmp->a << endl;
    cout << "\033[0;35mtmp->b: \033[0m\033[0;37m" << tmp->b << endl;
    cout << "-----------------------------------------------" << endl << endl;

    delete ds;
    return 0;
}