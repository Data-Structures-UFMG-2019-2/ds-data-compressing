#include<iostream>
#include <cstdio>

#include"./include/hash/hash.hpp"
#include "./include/index.hpp"
#include "./include/data_compressor.hpp"

int main(){
    int n;
    char op, word[64];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        DataCompressor::indexes[word]->increment_occurrency();
    }
    // DataCompressor::indexes.each(print_index);
    DataCompressor::build_tree();
    while (scanf(" %c %s", &op, word) != EOF) {
        if (op == 'q'){
            std::cout << DataCompressor::indexes[word]->get_occurrency() << std::endl;
        }
        else if (op == 'c'){
            std::cout << DataCompressor::indexes[word]->get_code() << std::endl;
        }
    }
    DataCompressor::index_tree->each(free_index);
    DataCompressor::index_tree->clear();
    delete DataCompressor::index_tree;

    return 0;
}
