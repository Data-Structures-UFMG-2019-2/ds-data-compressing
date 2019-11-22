#ifndef HASH_H
#define HASH_H

#include"./linked_list.hpp"
#include"./hash_pair.hpp"

template<class T>
class Hash{
    private:
        int max_size = 255;
        int size = 0;
        LinkedList<HashPair<T>>** lists;

    public:
        Hash();
        Hash(int max_size);
        ~Hash();
        void add(const char* key, T* value);
        T* get(const char* key);
};

#endif