#include"../include/index.hpp"

Index::Index(char* word, int ocurrency){
    this->word = word;
    this->ocurrency = ocurrency;
    this->code = code;
}

Index::~Index(){
}

char* Index::get_word(){ return this->word; }
char* Index::get_code(){ return this->code; }
int Index::get_ocurrency(){ return this->ocurrency; }
void Index::set_code(char* code){ this->code = code; }
void Index::increment_ocurrency(){ this->ocurrency++; }