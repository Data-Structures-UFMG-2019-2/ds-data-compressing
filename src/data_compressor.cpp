#include<iostream>

#include"../include/data_compressor.hpp"

Hash<Index> DataCompressor::indexes = Hash<Index>();
Tree::BinaryTree<Index>* DataCompressor::index_tree = nullptr;

bool compare_indexes(Index* a, Index* b){
    // Is a greater than b?
    if(a->get_occurrency() > b->get_occurrency()){
        return true;
    }
    else if(a->get_occurrency() < b->get_occurrency()){
        return false;
    }
    else{
        if(a->get_leaves() > b->get_leaves()){
            return true;
        }
        else if(a->get_leaves() < b->get_leaves()){
            return false;
        }
        else{
            for (int i = 0; a->get_word()[i] != '\0' || b->get_word()[i] != '\0' ; i++){
                if(a->get_word()[i] > b->get_word()[i]){
                    return true;
                }
                else if(a->get_word()[i] < b->get_word()[i]){
                    return false;
                }
            }
            return false;
            
        }
    }
}

void delegate_code(Index* index, char* code){
    index->set_code(code);
}

void free_index(Index* index){
    if(index != nullptr){
        delete index;
    }
}

List::LinkedList<Tree::BinaryTree<Index>>* DataCompressor::get_forest(){
    List::LinkedList<Tree::BinaryTree<Index>>* forest = new List::LinkedList<Tree::BinaryTree<Index>>();
    int j = 0;
    for (int i = 0; i < DataCompressor::indexes.get_max_size(); i++){
        for(List::Cell<HashPair<Index>>* it = DataCompressor::indexes.get_lists()[i]->begin(); it != nullptr; it = it->get_next()){
            HashPair<Index> *pair = it->get_object();
            Tree::BinaryTree<Index>* tree = new Tree::BinaryTree<Index>();
            tree->add(pair->value, compare_indexes);
            forest->add(tree);
            j++;
        }
    }
    return forest;
}

Tree::BinaryTree<Index>* DataCompressor::join_trees(List::Cell<Tree::BinaryTree<Index>> *a, List::Cell<Tree::BinaryTree<Index>> *b){
    Index *index_a, *index_b;
    index_a = a->get_object()->get_root()->get_object();
    index_b = b->get_object()->get_root()->get_object();

    Index *new_index = new Index(index_a->get_word());
    new_index->set_leaves(index_a->get_leaves()+index_b->get_leaves());
    new_index->set_occurrency(index_a->get_occurrency()+index_b->get_occurrency());

    Tree::Node<Index>* new_root = new Tree::Node<Index>(new_index);
    new_root->set_left(a->get_object()->get_root());
    a->get_object()->get_root()->set_parent(new_root);
    new_root->set_right(b->get_object()->get_root());
    b->get_object()->get_root()->set_parent(new_root);
    
    Tree::BinaryTree<Index>* new_tree = new Tree::BinaryTree<Index>();
    new_tree->set_root(new_root);
    return new_tree;
}

void DataCompressor::build_tree(){
    List::LinkedList<Tree::BinaryTree<Index>>* forest = DataCompressor::get_forest();

    while(forest->length() > 1){
        List::Cell<Tree::BinaryTree<Index>> *a = forest->begin(), *b = nullptr;
        for (List::Cell<Tree::BinaryTree<Index>>* it = a->get_next(); it != nullptr; it = it->get_next()){
            Tree::BinaryTree<Index>* tree = it->get_object();
            if(compare_indexes(a->get_object()->get_root()->get_object(), tree->get_root()->get_object())){
                b = a;
                a = it;
            }
            else if(b == nullptr || compare_indexes(b->get_object()->get_root()->get_object(), tree->get_root()->get_object())){
                b = it;
            }
        }

        forest->remove(a);
        forest->remove(b);
        Tree::BinaryTree<Index>* new_tree = DataCompressor::join_trees(a, b);
        forest->add(new_tree);
        delete a->get_object();
        delete b->get_object();
        delete a;
        delete b;
    }
    DataCompressor::index_tree = forest->remove(0);
    DataCompressor::index_tree->each(delegate_code);
    delete forest;
}