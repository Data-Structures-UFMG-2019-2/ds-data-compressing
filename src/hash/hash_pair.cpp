#include<cstdlib>

#include"../../include/hash/hash_pair.hpp"
#include "../../include/index.hpp"

template<class T>
HashPair<T>::HashPair(const char* key){
    this->key = key;
    this->value = nullptr;
}

template<class T>
HashPair<T>::HashPair(const char* key, T* value){
    this->key = key;
    this->value = value;
}

template<class T>
HashPair<T>::~HashPair(){
    free((char*)this->key);
}

template<class T>
bool HashPair<T>::match(char const* key){
    for(int i = 0; this->key[i] != '\0' && key[i] != '\0'; i++){
        if(this->key[i] != key[i]){
            return false;
        }
    }
    return true;
}

template class HashPair<Index>;