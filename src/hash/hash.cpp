#include<cstdlib>
#include<cstring>

#include"../../include/hash/hash.hpp"
#include"../../include/list/linked_list.hpp"
#include"../../include/list/cell.hpp"
#include "../../include/index.hpp"
#include"../../include/hash/hash_pair.hpp"

template<class T>
void free_pair(HashPair<T>* pair){
    delete pair;
}

template<class T>
Hash<T>::Hash(){
    this->lists = (List::LinkedList<HashPair<T>>**) malloc(this->max_size*sizeof(List::LinkedList<HashPair<T>>*));
    for(int i = 0; i < this->max_size; i++){
        this->lists[i] = new List::LinkedList<HashPair<T>>();
    }
    
}

template<class T>
Hash<T>::Hash(int max_size){
    this->max_size = max_size;
    this->lists = (List::LinkedList<HashPair<T>>**) malloc(this->max_size*sizeof(List::LinkedList<HashPair<T>>*));
    for(int i = 0; i < this->max_size; i++){
        this->lists[i] = new List::LinkedList<HashPair<T>>();
    }
}

template<class T>
Hash<T>::~Hash(){
    this->clear();
    free(this->lists);
}

template<class T>
int Hash<T>::get_max_size(){
    return this->max_size;
}

template<class T>
int Hash<T>::get_size(){
    return this->size;
}

template<class T>
List::LinkedList<HashPair<T>>** Hash<T>::get_lists(){
    return this->lists;
}

template<class T>
void Hash<T>::add(const char* key, T* value){
    int numeric_key = 0;
    HashPair<T>* pair = new HashPair<T>(key, value);
    List::LinkedList<HashPair<T>>* list;

    for(int i = 0; key[i] != '\0'; i++){
        numeric_key += (int)key[i];
    }
    list = this->lists[numeric_key % max_size];
    list->add(pair);
    this->size++;
}

template<class T>
T* Hash<T>::get(const char* key){
    int numeric_key = 0;
    HashPair<T>* pair;
    List::LinkedList<HashPair<T>>* list;
    
    for(int i = 0; key[i] != '\0'; i++){
        numeric_key += (int)key[i];
    }
    list = this->lists[numeric_key % max_size];
    for(List::Cell<HashPair<T>>* it = list->begin(); it != nullptr; it = it->get_next()){
        pair = it->get_object();
        if(pair->match(key)){
            return pair->value;
        }
    }
    return nullptr;
}

template<class T>
T* Hash<T>::operator[](const char* key){
    T* value = this->get(key);
    if(value == nullptr){
        value = new T((char*) key);
        this->add(key, value);
    }
    return value;
}

template<class T>
void Hash<T>::each(void (*callback)(T*)){
    HashPair<T>* pair;
    for (int i = 0; i < this->max_size; i++){
        for(List::Cell<HashPair<T>>* it = lists[i]->begin(); it != nullptr; it = it->get_next()){
            pair = it->get_object();
            callback(pair->value);
        }
    }
}

template<class T>
void Hash<T>::clear(){
    for (int i = 0; i < this->max_size; i++){
        this->lists[i]->each(free_pair);
        delete this->lists[i];
    }
    this->size = 0;
}

template class Hash<Index>;