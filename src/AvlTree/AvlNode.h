#ifndef AVLNODE_H
#define AVLNODE_H
#include <concepts>

#pragma once
template <class T>
    requires std::totally_ordered<T>
class AvlNode {
public:
    AvlNode(T value);
    ~AvlNode();

    T           GetValue();
    AvlNode<T> *GetParent();

    void SetParent(AvlNode *node);

    AvlNode<T> *left  = nullptr;
    AvlNode<T> *right = nullptr;
    T           value;

private:
    AvlNode<T> *parent = nullptr;
};

#include "AvlNode.cpp"
#endif
