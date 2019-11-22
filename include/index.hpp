#ifndef INDEX_H
#define INDEX_H

class Index{
    private:
        char* word;
        int ocurrency;
        char* code;

    public:
        Index(char* word, int ocurrency);
        ~Index();
        char* get_word();
        char* get_code();
        int get_ocurrency();
        void set_code(char* code);
        void increment_ocurrency();
};

#endif