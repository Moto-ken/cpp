
#include "Serializer.hpp"

int main(void) {
    Data data(100);

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "original: " << &data << std::endl;
    std::cout << "raw: " << raw << std::endl;
    std::cout << "restored: " << ptr << std::endl;
    std::cout << "same address: " << (ptr == &data ? "OK" : "KO") << std::endl;
    std::cout << "restored nb: " << ptr->getNb() << std::endl;

    return 0;
}
