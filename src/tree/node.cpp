#include "../../include/tree/node.hpp"

template<class T>
Tree::Node<T>::Node(T* object){
    this->object = object;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template<class T>
Tree::Node<T>::~Node(){
    this->object = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

template<class T>
T* Tree::Node<T>::get_object(){
    return this->object;
}

template<class T>
Tree::Node<T>* Tree::Node<T>::get_parent(){
    return this->parent;
}

template<class T>
Tree::Node<T>* Tree::Node<T>::get_left(){
    return this->left;
}

template<class T>
Tree::Node<T>* Tree::Node<T>::get_right(){
    return this->right;
}

template<class T>
int Tree::Node<T>::get_height(){
    int left = 0, right = 0;
    if(this->left != nullptr){
        left = this->left->get_height();
    }
    if(this->right != nullptr){
        right = this->right->get_height();
    }

    return left > right ? left + 1 : right + 1;
}

template<class T>
void Tree::Node<T>::cascade_clear(){
    if(this->left != nullptr){
        this->left->cascade_clear();
        delete this->left;
    }
    if(this->right != nullptr){
        this->right->cascade_clear();
        delete this->right;
    }
    if(this->object != nullptr){
        delete this->object;
    }
}