#include <iostream>
#include <fstream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *data = new Data("Hello", 42, "World");
    uintptr_t raw;
    
    std::cout << "Data: " << data->getS1() << " " << data->getN() << " " << data->getS2() << std::endl;
    raw = Serializer::serialize(data);
    std::cout << "Raw: " << raw << std::endl;
    data = Serializer::deserialize(raw);
    std::cout << "Data: " << data->getS1() << " " << data->getN() << " " << data->getS2() << std::endl;
    delete data;
    
    return 0;
}
