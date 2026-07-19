#include "AvlTree.h"

template <class T>
    requires std::totally_ordered<T>
AvlTree<T>::AvlTree() {
    this->amount = 0;
    this->depth  = 0;
    this->root   = nullptr;
}

template <class T>
    requires std::totally_ordered<T>
AvlTree<T>::~AvlTree() {
    this->amount = 0;
    this->depth  = 0;
    this->root   = nullptr;
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::GetRoot() {
    return this->root;
}

template <class T>
    requires std::totally_ordered<T>
int AvlTree<T>::Depth() {
    return this->depth;
}