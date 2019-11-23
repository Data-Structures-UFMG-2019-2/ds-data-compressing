#include "../../include/list/cell.hpp"
#include "../../include/index.hpp"
#include "../../include/hash/hash_pair.hpp"
#include "../../include/tree/binary_tree.hpp"

template<class T>
List::Cell<T>::Cell(T* object){
    this->object = object;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
List::Cell<T>::~Cell(){
}

template<class T>
List::Cell<T>* List::Cell<T>::operator++(){
    return this->next;
}

template<class T>
List::Cell<T>* List::Cell<T>::operator--(){
    return this->prev;
}

template<class T>
T* List::Cell<T>::get_object(){
    return this->object;
}

template<class T>
List::Cell<T>* List::Cell<T>::get_next(){
    return this->next;
}

template<class T>
List::Cell<T>* List::Cell<T>::get_prev(){
    return this->prev;
}

template<class T>
void List::Cell<T>::cascade_clear(int direction){
    if(direction == FORWARD){
        if(this->next != nullptr){
            this->next->cascade_clear(FORWARD);
            delete this->next;
        }
    }
    else if(direction == BACKWARD){
        if(this->prev != nullptr){
            this->prev->cascade_clear(BACKWARD);
            delete this->prev;
        }
    }
}

template class List::Cell<HashPair<Index>>;
template class List::Cell<Tree::BinaryTree<Index>>;