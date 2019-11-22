#ifndef HASH_H
#define HASH_H

#define MAX_STACK_SIZE 100000

#include"./linked_list.hpp"
#include"./hash_pair.hpp"

template<class T>
class Hash{
    private:
        int max_size = 255;
        int size = 0;
        List::LinkedList<HashPair<T>>** lists;
        char* copy_key(const char* key);

    public:
        Hash();
        Hash(int max_size);
        ~Hash();
        void add(const char* key, T* value);
        T* get(const char* key);
        T* operator[](const char* key);
        void each(void (*callback)(T*));
        void clear();
};

#endif