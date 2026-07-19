#ifndef AVLTREE_H
#define AVLTREE_H
#include "AvlNode.h"
#include <concepts>

template <class T>
    requires std::totally_ordered<T>
class AvlTree {
public:
    AvlTree();
    ~AvlTree();

    void Insert(T value);

    void        Remove(T value);
    AvlNode<T> *Search(T value);
    AvlNode<T> *GetRoot();
    bool        HasValue(T value);
    void        Clear();
    int         Amount();
    int         Depth();

private:
    int         amount = 0;
    int         depth  = 0;
    AvlNode<T> *root   = nullptr;
};

#include "AvlTree.cpp"
#endif
