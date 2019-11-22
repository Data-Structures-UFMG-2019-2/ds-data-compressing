#include<cstdlib>

#include"../include/index.hpp"

Index::Index(char* word){
    this->word = word;
    this->ocurrency = 0;
}

Index::Index(){
    this->ocurrency = 0;
}

Index::~Index(){
}

char* Index::get_word(){
    return this->word;
}

char* Index::get_code(){
    return this->code;
}

int Index::get_ocurrency(){
    return this->ocurrency;
}

void Index::set_code(char* code){
    this->code = code;
}

void Index::increment_ocurrency(){
    this->ocurrency++;
}

void Index::operator++(){
    this->ocurrency++;
}