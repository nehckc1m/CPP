#include "Serializer.hpp"



int main()
{
    Data *data = new Data();
    data->_name = "eating tuna";
    data->_value = 42;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << data->_name << ", Value: " << data->_value << std::endl;

    std::cout << "----------------------------------------" << std::endl;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;


    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Deserializing...: " << raw << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << deserializedData->_name << ", Value: " << deserializedData->_value << std::endl;

    delete data;
    return 0;
}