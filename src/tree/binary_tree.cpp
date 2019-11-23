#include<string>
#include<sstream>
#include<iostream>

#include"../../include/tree/binary_tree.hpp"
#include "../../include/index.hpp"

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
    Tree::Node<T> *node = this->root, *new_node = new Tree::Node<T>(object);
    if(this->size == 0){
        this->root = new_node;
    }
    while(node != nullptr){
        T* node_object = node->get_object();
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
void Tree::BinaryTree<T>::set_root(Node<T>* root){
    this->root = root;
    this->height = root->get_height();
    this->size = root->get_size();
}

template<class T>
Tree::Node<T>* Tree::BinaryTree<T>::get_root(){
    return this->root;
}

template<class T>
Tree::Node<T>* Tree::BinaryTree<T>::get_smallest(){
    Tree::Node<T>* node = nullptr;
    for (node = this->root; node->left != nullptr; node = node->left){}
    return node;
}

template<class T>
Tree::Node<T>* Tree::BinaryTree<T>::get_largest(){
    Tree::Node<T>* node = nullptr;
    for (node = this->root; node->right != nullptr; node = node->right){}
    return node;
}

template<class T>
void Tree::BinaryTree<T>::each(void (*callback)(T*, char*)){
    this->root->propagate((char*) "", callback);
}

template<class T>
void Tree::BinaryTree<T>::remove(Tree::Node<T>* node){
    if(node == this->root){
        this->root = nullptr;
        this->size = 0;
    }
    else{
        Tree::Node<T>* parent = node->parent;
        if(parent->left == node){
            parent->left = nullptr;
        }
        else if(parent->right == node){
            parent->right = nullptr;
        }
        else{
            return;
        }
        node->parent = nullptr;
        this->size -= node->get_size();
        this->height = this->root->get_height();
    }
}

template<class T>
void Tree::BinaryTree<T>::clear(){
    if(this->size > 0){
        this->root->cascade_clear();
    }
}

template class Tree::BinaryTree<Index>;