#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
    public:
    std::string _name;
    int _value;

} Data;
class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    
};
