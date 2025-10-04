#include "Serializer.hpp"

int main(void)
{
    Data *test = new Data;

    test->name = "spongebob";
    test->age = 20;
    test->score = 14.20f;

    uintptr_t raw = Serializer::serialize(test);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "address: " << test << std::endl;
    std::cout << "address: " << reinterpret_cast<void*>(raw) << std::endl;

    std::cout << "----------" << std::endl;
    std::cout << ptr->name << std::endl;
    std::cout << ptr->age << std::endl;
    std::cout << ptr->score << std::endl;
    
    delete ptr;

    return 0;
}