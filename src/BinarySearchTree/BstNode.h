#ifndef BSTNODE_H
#define BSTNODE_H

#pragma once
#include <concepts>

template <class T>
    requires std::totally_ordered<T>
class BstNode
{

public:
    BstNode(T value);
    ~BstNode();

    T GetValue();
    BstNode<T> *GetParent();

    void SetParent(BstNode *node);

    BstNode<T> *left = nullptr;
    BstNode<T> *right = nullptr;
    T value;

private:
    BstNode<T> *parent = nullptr;
};

#include "BstNode.cpp"
#endif