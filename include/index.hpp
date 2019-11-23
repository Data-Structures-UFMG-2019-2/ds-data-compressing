#ifndef INDEX_H
#define INDEX_H

class Index{
    private:
        char* word;
        int occurrency;
        int leaves;
        char* code = nullptr;

    public:
        Index(char* word);
        Index();
        ~Index();
        char* get_word();
        char* get_code();
        int get_occurrency();
        int get_leaves();
        void set_code(char* code);
        void set_leaves(int leaves);
        void increment_occurrency();
        void set_occurrency(int occurrency);
        void operator++();
};

#endif