#include "AvlNode.h"

template <class T>
    requires std::totally_ordered<T>
AvlNode<T>::AvlNode(T value) {
    this->value  = value;
    this->left   = nullptr;
    this->right  = nullptr;
    this->parent = nullptr;
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T>::~AvlNode() {
    delete this->left;
    delete this->right;
}

template <class T>
    requires std::totally_ordered<T>
T AvlNode<T>::GetValue() {

    return this->value;
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlNode<T>::GetParent() {
    return this->parent;
}

template <class T>
    requires std::totally_ordered<T>
void AvlNode<T>::SetParent(AvlNode *node) {
    this->parent = node;
}
