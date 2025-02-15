#pragma once

#include <stdint.h>
#include <iostream>

using std::cout;
using std::endl;

typedef struct {
    float a, b;
} Data;

class Serializer {
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(const Serializer& copy);
        Serializer &operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};