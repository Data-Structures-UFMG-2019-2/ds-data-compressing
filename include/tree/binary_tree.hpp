#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include"./node.hpp"

namespace Tree{
    template <class T>
    class BinaryTree{
        private:
            int size = 0;
            int height = 0;
            int leaves = 0;
            Node<T>* root = nullptr;
        public:
            BinaryTree();
            ~BinaryTree();
            int get_size(); // O(1)
            int get_height(); // O(1)
            void add(T* object, bool (*compare)(T*, T*)); // O(logn) ~ O(n)
            void set_root(Node<T>* root); // O(1)
            Node<T>* get_root(); // O(1)
            Node<T>* get_smallest(); // O(n)
            Node<T>* get_largest(); // O(n)
            void each(void (*callback)(T*));
            void each(void (*callback)(T*, char*));
            void remove(Node<T>*); // O(1)
            void clear();
    };
}

#endif