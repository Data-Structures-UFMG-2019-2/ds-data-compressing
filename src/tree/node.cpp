#include<cstring>
#include<cstdlib>

#include "../../include/tree/node.hpp"
#include "../../include/index.hpp"

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
void Tree::Node<T>::set_parent(Node<T>* parent){
    this->parent = parent;
}

template<class T>
Tree::Node<T>* Tree::Node<T>::get_left(){
    return this->left;
}

template<class T>
void Tree::Node<T>::set_left(Node<T>* left){
    this->left = left;
}

template<class T>
Tree::Node<T>* Tree::Node<T>::get_right(){
    return this->right;
}

template<class T>
void Tree::Node<T>::set_right(Node<T>* right){
    this->right = right;
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
int Tree::Node<T>::get_size(){
    int left = 0, right = 0;
    if(this->left != nullptr){
        left = this->left->get_size();
    }
    if(this->right != nullptr){
        right = this->right->get_size();
    }
    return left + right + 1;
}

template<class T>
void Tree::Node<T>::propagate(char* path, void (*callback)(T*, char*)){
    int path_size = strlen(path);
    callback(this->object, path);
    if(this->left != nullptr){
        char *left_path = (char*) malloc((path_size+2)*sizeof(char));
        memcpy(left_path, path, path_size);
        left_path[path_size]='0';
        left_path[path_size+1]='\0';
        this->left->propagate(left_path, callback);
    }
    if(this->right != nullptr){
        char *right_path = (char*) malloc((path_size+2)*sizeof(char));
        memcpy(right_path, path, path_size);
        right_path[path_size]='1';
        right_path[path_size+1]='\0';
        this->right->propagate(right_path, callback);
    }
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
}

template class Tree::Node<Index>;