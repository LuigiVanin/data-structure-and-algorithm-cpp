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
    AvlNode<T> *root   = nullptr;

    uint        height(AvlNode<T> *node);
    int         balanceFactor(AvlNode<T> *node);
    void        updateHeight(AvlNode<T> *node);

    AvlNode<T> *rotateRight(AvlNode<T> *node);
    AvlNode<T> *rotateLeft(AvlNode<T> *node);
    AvlNode<T> *balance(AvlNode<T> *node);

    AvlNode<T> *minimum(AvlNode<T> *node);
    void        replaceChild(AvlNode<T> *parent,
                             AvlNode<T> *oldChild,
                             AvlNode<T> *newChild);

    void backtrack(AvlNode<T> *current);
};

#include "AvlTree.cpp"
#endif
