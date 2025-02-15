#include "Serializer.hpp"

int main()
{
    Data *ds = new Data;
    ds->a = 42;
    ds->b = ds->a * 1e-2;

    cout << endl << "-----------------------------------------------" << endl;
    cout << "Before: " << ds << endl;
    uintptr_t rawPtr = Serializer::serialize(ds);
    cout << "After: " << rawPtr << endl;
    cout << "-----------------------------------------------" << endl << endl;
    cout << "-----------------------------------------------" << endl;

    Data *tmp = NULL;
    tmp = Serializer::deserialize(rawPtr);
    cout << "Before: " << tmp << endl;
    cout << "tmp->a: " << tmp->a << endl;
    cout << "tmp->b: " << tmp->b << endl;
    cout << "-----------------------------------------------" << endl << endl;

    delete ds;
    return 0;
}