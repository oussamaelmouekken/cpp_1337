#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout<<"Serializer constructor \n";
}

Serializer::Serializer(Serializer const  &other) 
{
    (void)other;
    std::cout << "Serializer copied! (This should not happen!)" << std::endl;
}

Serializer &Serializer ::operator=(Serializer const &other) 
{
    (void)other;
    std::cout << "Serializer assigned! (This should not happen!)" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout<<"Serializer destructor \n";
}

uintptr_t Serializer::serialize(Data* ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw) 
{
    return reinterpret_cast<Data*>(raw);
}
