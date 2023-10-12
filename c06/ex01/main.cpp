#include <iostream>
#include <fstream>
#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    uintptr_t raw;
    
    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";

    std::cout << "Data: " << data->s1 << " " << data->n << " " << data->s2 << std::endl;
    raw = Serializer::serialize(data);
    std::cout << "Raw: " << raw << std::endl;
    data = Serializer::deserialize(raw);
    std::cout << "Data: " << data->s1 << " " << data->n << " " << data->s2 << std::endl;


    return 0;
}
