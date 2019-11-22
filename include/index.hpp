#ifndef INDEX_H
#define INDEX_H

class Index{
    private:
        char* word;
        int code;

    public:
        Index(char* word, int code);
        ~Index();
};

#endif