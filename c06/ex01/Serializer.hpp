#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
};
