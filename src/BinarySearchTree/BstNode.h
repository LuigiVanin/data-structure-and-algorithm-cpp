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

    void SetParent(BstNode *node);

    BstNode *left = nullptr;
    BstNode *right = nullptr;
    T value;

private:
    BstNode *parent = nullptr;
};

#include "BstNode.cpp"
#endif