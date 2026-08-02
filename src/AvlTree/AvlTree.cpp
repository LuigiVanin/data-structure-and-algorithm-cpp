#include "AvlTree.h"
#include "AvlNode.h"
#include "../utils/errors.h"
#include <algorithm>

template <class T>
    requires std::totally_ordered<T>
AvlTree<T>::AvlTree() {
    this->amount = 0;
    this->root   = nullptr;
}

template <class T>
    requires std::totally_ordered<T>
AvlTree<T>::~AvlTree() {
    this->Clear();
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::GetRoot() {
    return this->root;
}

template <class T>
    requires std::totally_ordered<T>
int AvlTree<T>::Amount() {
    return this->amount;
}

template <class T>
    requires std::totally_ordered<T>
int AvlTree<T>::Depth() {
    return (int)this->height(this->root);
}

template <class T>
    requires std::totally_ordered<T>
uint AvlTree<T>::height(AvlNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::updateHeight(AvlNode<T> *node) {
    if (node == nullptr) {
        return;
    }

    node->height =
        1 + std::max(this->height(node->left), this->height(node->right));
}

template <class T>
    requires std::totally_ordered<T>
int AvlTree<T>::balanceFactor(AvlNode<T> *node) {
    if (node == nullptr) {
        return 0;
    }

    return (int)this->height(node->left) - (int)this->height(node->right);
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::replaceChild(AvlNode<T> *parent,
                              AvlNode<T> *oldChild,
                              AvlNode<T> *newChild) {
    if (parent == nullptr) {
        this->root = newChild;
        return;
    }

    if (parent->left == oldChild) {
        parent->left = newChild;
    } else if (parent->right == oldChild) {
        parent->right = newChild;
    }
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::rotateRight(AvlNode<T> *node) {
    AvlNode<T> *pivot = node->left;

    node->left = pivot->right;
    if (node->left != nullptr) {
        node->left->SetParent(node);
    }

    pivot->right = node;
    pivot->SetParent(node->GetParent());
    node->SetParent(pivot);

    this->replaceChild(pivot->GetParent(), node, pivot);

    this->updateHeight(node);
    this->updateHeight(pivot);

    return pivot;
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::rotateLeft(AvlNode<T> *node) {
    AvlNode<T> *pivot = node->right;

    node->right = pivot->left;
    if (node->right != nullptr) {
        node->right->SetParent(node);
    }

    pivot->left = node;
    pivot->SetParent(node->GetParent());
    node->SetParent(pivot);

    this->replaceChild(pivot->GetParent(), node, pivot);

    this->updateHeight(node);
    this->updateHeight(pivot);

    return pivot;
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::balance(AvlNode<T> *node) {
    int factor = this->balanceFactor(node);

    if (factor > 1) {
        if (this->balanceFactor(node->left) < 0) {
            this->rotateLeft(node->left);
        }

        return this->rotateRight(node);
    }

    if (factor < -1) {
        if (this->balanceFactor(node->right) > 0) {
            this->rotateRight(node->right);
        }

        return this->rotateLeft(node);
    }

    return node;
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::Insert(T value) {
    auto node = new AvlNode<T>(value);

    this->amount++;

    if (this->root == nullptr) {
        this->root = node;
        return;
    }

    AvlNode<T> *curr = this->root;

    while (curr != nullptr) {
        if (curr->value > value) {
            if (curr->left == nullptr) {
                curr->left = node;
                break;
            }

            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = node;
                break;
            }

            curr = curr->right;
        }
    }

    node->SetParent(curr);

    this->backtrack(node);
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::Remove(T value) {
    AvlNode<T> *node = this->Search(value);

    if (node == nullptr) {
        throw CouldNotFindItem();
    }

    if (node->left != nullptr && node->right != nullptr) {
        AvlNode<T> *successor = this->minimum(node->right);

        node->value = successor->value;
        node        = successor;
    }

    AvlNode<T> *child  = node->left != nullptr ? node->left : node->right;
    AvlNode<T> *parent = node->GetParent();

    if (child != nullptr) {
        child->SetParent(parent);
    }

    this->replaceChild(parent, node, child);

    node->left  = nullptr;
    node->right = nullptr;
    delete node;

    this->amount--;

    this->backtrack(parent);
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::minimum(AvlNode<T> *node) {
    AvlNode<T> *curr = node;

    while (curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }

    return curr;
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::backtrack(AvlNode<T> *current) {
    AvlNode<T> *temp = current;

    while (temp != nullptr) {
        this->updateHeight(temp);

        temp = this->balance(temp);
        temp = temp->GetParent();
    }
}

template <class T>
    requires std::totally_ordered<T>
AvlNode<T> *AvlTree<T>::Search(T value) {
    AvlNode<T> *curr = this->root;

    while (curr != nullptr) {
        if (curr->value == value) {
            return curr;
        }

        if (curr->value > value) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return nullptr;
}

template <class T>
    requires std::totally_ordered<T>
bool AvlTree<T>::HasValue(T value) {
    return this->Search(value) != nullptr;
}

template <class T>
    requires std::totally_ordered<T>
void AvlTree<T>::Clear() {
    this->amount = 0;

    if (this->root != nullptr) {
        delete this->root;
    }
    this->root = nullptr;
}
