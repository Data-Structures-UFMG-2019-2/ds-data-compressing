#include<iostream>

#include"./include/hash.hpp"
#include "./include/index.hpp"

int main(){
    Hash<Index> indexes = Hash<Index>();
    indexes["abc"]->increment_ocurrency();
    indexes["abc"]->increment_ocurrency();
    indexes["abcd"]->increment_ocurrency();
    std::cout << indexes["abc"]->get_ocurrency() << std::endl;
    std::cout << indexes["abcd"]->get_ocurrency() << std::endl;
    std::cout << indexes["acb"]->get_ocurrency() << std::endl;
    indexes.clear();
}
