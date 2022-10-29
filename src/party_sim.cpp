#include <iostream>
#include "constituency.hpp"

int main(int arv, char** argc) {

    Constituency* c = ConstituencyGenerator::make_constituency();
    std::cout << "hello world" << std::endl;
    std::cout << *c << std::endl;
    return 0;
}