#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include"./node.hpp"

namespace Tree{
    template <class T>
    class BinaryTree{
        private:
            int size = 0;
            int height = 0;
            int leaves = 1;
            Node<T>* root = nullptr;
        public:
            BinaryTree();
            ~BinaryTree();
            int get_size();
            int get_height();
            void add(T* object, bool (*compare)(T*, T*));
            Node<T>* get_root();
            void clear();
    };
}

#endif