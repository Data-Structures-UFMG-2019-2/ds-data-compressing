#include<string>
#include<sstream>
#include<iostream>

#include"../../include/tree/binary_tree.hpp"

template<class T>
Tree::BinaryTree<T>::BinaryTree(){
}

template<class T>
Tree::BinaryTree<T>::~BinaryTree(){
}

template<class T>
int Tree::BinaryTree<T>::get_height(){
    return this->height;
}

template<class T>
int Tree::BinaryTree<T>::get_size(){
    return this->size;
}

template<class T>
void Tree::BinaryTree<T>::add(T* object, bool (*compare)(T*, T*)){
    Node<T>* node = this->root, new_node = new Node<T>(object);
    if(this->size == 0){
        this->root = new_node;
    }
    while(node != nullptr){
        T* node_object;
        if(compare(object, node_object)){
            if(node->right == nullptr){
                node->right = new_node;
                break;
            }
            else{
                node = node->get_right();
            }
        }
        else{
            if(node->left == nullptr){
                node->left = new_node;
                break;
            }
            else{
                node = node->get_left();
            }
        }
    }
    new_node->parent = node;
    this->size++;
    this->height = this->root->get_height();
}

template<class T>
Tree::Node<T>* Tree::BinaryTree<T>::get_root(){
    return this->root;
}

template<class T>
void Tree::BinaryTree<T>::clear(){
    if(this->size > 0){
        this->root->cascade_clear();
    }
}