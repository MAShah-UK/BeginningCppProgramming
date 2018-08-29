#include "Test.h"

Test::Test(int data)
    : data {data} {
    std::cout << "\tTest constructor (" << data << ")" << std::endl;
}

Test::~Test() {
    std::cout << "\tTest destructor (" << data << ")" << std::endl;
}

int Test::get_data() const {
    return data;
}