#include "BinarySearchTree.h"

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = nullptr;
    this->amount = 0;
    this->depth = 0;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete this->root;
}

template <class T>
void BinarySearchTree<T>::Insert(T value)
{
    BstNode<T> *newNode = new BstNode<T>(value);

    if (this->root == nullptr)
    {
        this->root = newNode;
        this->depth = 1;
        this->amount++;
        return;
    }

    BstNode<T> *current = this->root;
    int depth = 1; // Start depth at 1 since root is level 1

    while (current != nullptr)
    {
        depth++;
        if (value < current->value)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                this->depth = std::max(depth, this->depth);
                this->amount++;
                newNode->SetParent(current);
                return;
            }
            current = current->left;
        }
        else
        {
            std::cout << "Right" << std::endl;
            std::cout << "current right: " << current->left << std::endl;

            if (current->right == nullptr)
            {
                std::cout << "NULL Right" << std::endl;
                current->right = newNode;
                this->depth = std::max(depth, this->depth);
                this->amount++;
                newNode->SetParent(current);
                return;
            }
            current = current->right;
        }
    }
}

template <class T>
BstNode<T> *BinarySearchTree<T>::GetRoot()
{
    return this->root;
}
