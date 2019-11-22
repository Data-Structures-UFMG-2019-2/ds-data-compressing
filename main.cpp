#include<iostream>

#include"./include/hash.hpp"
#include "./include/index.hpp"

int main(){
    Index* index_a = new Index((char*) "a", 12);
    Index* index_b = new Index((char*) "b", 13);
    Index* index_c = new Index((char*) "c", 14);
    Hash<Index> hash = Hash<Index>();
    hash.add("abc", index_a);
    hash.add("abcd", index_b);
    hash.add("acb", index_c);
    std::cout << hash["abc"]->get_word() << std::endl;
    std::cout << hash["abcd"]->get_word() << std::endl;
    std::cout << hash["acb"]->get_word() << std::endl;
    hash.clear();
}
