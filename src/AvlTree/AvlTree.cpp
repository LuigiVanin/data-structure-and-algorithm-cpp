#include "AvlTree.h"
#include "AvlNode.h"
#include <algorithm>

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

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::Insert(T value) {
    auto node = new AvlNode<T>(value);

    if (this->root == nullptr) {
        this->root = node;
        this->amount++;
        this->depth++;
        return;
    }

    AvlNode<T> *curr  = this->root;
    int         depth = 1;

    while (curr != nullptr) {
        depth++;

        if (curr->value <= value) {
            if (curr->left == nullptr) {
                curr->left = node;
                break;
            }

            curr = curr->left;
        } else if (curr->value > value) {
            if (curr->right == nullptr) {
                curr->right = node;
                break;
            }

            curr = curr->right;
        }
    }

    node->SetParent(curr);
    this->depth = std::max(depth, this->depth);
    this->amount++;
    this->depth++;
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::Clear() {
    this->amount = 0;
    this->depth  = 0;

    if (this->root != nullptr) {
        delete this->root;
    }
    this->root = nullptr;
}