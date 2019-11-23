#ifndef HASH_PAIR_H
#define HASH_PAIR_H

template<class T>
class HashPair{
    private:
        const char* key;

    public:
        T* value;
        HashPair(const char* key);
        HashPair(const char* key, T* value);
        ~HashPair();
        bool match(const char* key);
};

#endif