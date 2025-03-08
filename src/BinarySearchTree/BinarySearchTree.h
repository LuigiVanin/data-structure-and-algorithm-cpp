#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#pragma once
#include <concepts>
#include "BstNode.h"

template <class T>
    requires std::totally_ordered<T>
class BinarySearchTree
{

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(T value);
    // void Remove(T value);
    BstNode<T> *Search(T value);
    BstNode<T> *GetRoot();
    bool HasValue(T value);
    void Clear();
    int Amount();
    int Depth();

private:
    int amount = 0;
    int depth = 0;
    BstNode<T> *root = nullptr;
};

#include "BinarySearchTree.cpp"
#endif