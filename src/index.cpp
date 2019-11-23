#include<cstdlib>
#include<iostream>

#include"../include/index.hpp"

Index::Index(char* word){
    this->word = word;
    this->occurrency = 0;
    this->leaves = 1;
}

Index::Index(){
    this->occurrency = 0;
    this->leaves = 1;
}

Index::~Index(){
    if(this->word != nullptr){
        free(this->word);
    }
    if(this->code != nullptr){
        free(this->code);
    }
}

char* Index::get_word(){
    return this->word;
}

char* Index::get_code(){
    return this->code;
}

int Index::get_occurrency(){
    return this->occurrency;
}

int Index::get_leaves(){
    return this->leaves;
}

void Index::set_code(char* code){
    this->code = code;
}

void Index::set_leaves(int leaves){
    this->leaves = leaves;
}

void Index::increment_occurrency(){
    this->occurrency++;
}

void Index::set_occurrency(int occurrency){
    this->occurrency = occurrency;
}

void Index::operator++(){
    this->occurrency++;
}