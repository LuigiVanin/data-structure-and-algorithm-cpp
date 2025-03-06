#include "BstNode.h"

template <class T>
BstNode<T>::BstNode(T value)
{
    this->value = value;
    this->right = nullptr;
    this->left = nullptr;
    this->parent = nullptr;
}

template <class T>
BstNode<T>::~BstNode()
{
    delete this->left;
    delete this->right;
}

template <class T>
T BstNode<T>::GetValue()
{
    return this->value;
}

template <class T>
void BstNode<T>::SetParent(BstNode *node)
{
    this->parent = node;
}
