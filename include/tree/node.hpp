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
            Node<T>* get_left();
            Node<T>* get_right();
            int get_height();
    };
}

#endif