#ifndef NODE_H
#define NODE_H

namespace Tree {

    template <class T> class BinaryTree;
    
    template <class T>
    class Node{
        private:
            T* object;
            Node<T>* parent;
            Node<T>* left;
            Node<T>* right;
            void cascade_clear();

            friend class BinaryTree<T>;
        public:
            Node(T* object);
            ~Node();
            T* get_object();
            Node<T>* get_parent();
            void set_parent(Node<T>* parent);
            Node<T>* get_left();
            void set_left(Node<T>* left);
            Node<T>* get_right();
            void set_right(Node<T>* right);
            int get_height();
            int get_size();
            void propagate(void (*callback)(T*));
            void propagate(char* path, void (*callback)(T*, char*));
    };
}

#endif