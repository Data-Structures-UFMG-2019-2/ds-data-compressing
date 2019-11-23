#include<cstdlib>
#include<cstring>

#include"../../include/hash/hash_pair.hpp"
#include "../../include/index.hpp"

template<class T>
HashPair<T>::HashPair(const char* key){
    int key_size = strlen(key)+1;
    this->key = (char*) malloc(key_size*sizeof(char));
    memcpy((char*) this->key, key, key_size);
    this->value = nullptr;
}

template<class T>
HashPair<T>::HashPair(const char* key, T* value){
    int key_size = strlen(key)+1;
    this->key = (char*) malloc(key_size*sizeof(char));
    memcpy((char*) this->key, key, key_size);
    this->value = value;
}

template<class T>
HashPair<T>::~HashPair(){
    if(this->key != nullptr){
        free((char*)this->key);
    }
}

template<class T>
bool HashPair<T>::match(char const* key){
    for(int i = 0; this->key[i] != '\0' || key[i] != '\0'; i++){
        if(this->key[i] != key[i]){
            return false;
        }
    }
    return true;
}

template class HashPair<Index>;