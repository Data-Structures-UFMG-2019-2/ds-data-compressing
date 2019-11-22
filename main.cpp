#include<iostream>
#include <cstdio>

#include"./include/hash.hpp"
#include "./include/index.hpp"

void print_index(Index* index){
    std::cout << index->get_word() << std::endl;
    std::cout << index->get_ocurrency() << std::endl;
}

int main(){
    int n;
    char op, word[64];
    Hash<Index> indexes = Hash<Index>();

    scanf("%d", &n);
    // indexes["TESTE"]->increment_ocurrency();
    // indexes["TESTE"]->increment_ocurrency();
    // indexes["ALO"]->increment_ocurrency();
    // indexes["ALOHA"]->increment_ocurrency();
    // indexes["TESTE"]->increment_ocurrency();
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        indexes[word]->increment_ocurrency();
    }
    indexes.each(print_index);
    while (scanf(" %c %s", &op, word) != EOF) {
        if (op == 'q'){
            
        }
    }
    indexes.clear();

    return 0;
}
