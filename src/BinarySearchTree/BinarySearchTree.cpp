#include "BinarySearchTree.h"
#include "../utils/errors.h"

#include <concepts>

template <class T>
    requires std::totally_ordered<T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = nullptr;
    this->amount = 0;
    this->depth = 0;
}

template <class T>
    requires std::totally_ordered<T>
BinarySearchTree<T>::~BinarySearchTree()
{
    if (this->root != nullptr)
        delete this->root;
}

template <class T>
    requires std::totally_ordered<T>
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
            if (current->right == nullptr)
            {
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
    requires std::totally_ordered<T>
void BinarySearchTree<T>::Remove(T value)
{
    BstNode<T> *nodeToRemove = this->Search(value);

    if (nodeToRemove == nullptr)
        throw new CouldNotFindItem();

    BstNode<T> *parent = nodeToRemove->GetParent();

    if (parent == nullptr) // Node to remove is the root
    {
        BstNode<T> *rightSubtree = nodeToRemove->right;
        BstNode<T> *leftSubtree = nodeToRemove->left;

        this->root = nullptr;
        this->amount = 0;
        this->depth = 0;

        this->recursiveInsertion(leftSubtree);
        this->recursiveInsertion(rightSubtree);

        delete nodeToRemove;
        return;
    }

    if (parent->right != nullptr && parent->right->GetValue() == value)
        parent->right = nullptr;
    else if (parent->left != nullptr && parent->left->GetValue() == value)
        parent->left = nullptr;

    int tmpAmount = this->Amount();
    this->recursiveInsertion(nodeToRemove->right);
    this->recursiveInsertion(nodeToRemove->left);
    this->amount = tmpAmount - 1;

    delete nodeToRemove;
}

template <class T>
    requires std::totally_ordered<T>
void BinarySearchTree<T>::recursiveInsertion(BstNode<T> *node)
{
    if (node == nullptr)
        return;

    this->Insert(node->GetValue());

    this->recursiveInsertion(node->left);
    this->recursiveInsertion(node->right);
}

template <class T>
    requires std::totally_ordered<T>
BstNode<T> *BinarySearchTree<T>::GetRoot()
{
    return this->root;
}

template <class T>
    requires std::totally_ordered<T>
int BinarySearchTree<T>::Amount()
{
    return this->amount;
}

template <class T>
    requires std::totally_ordered<T>
int BinarySearchTree<T>::Depth()
{
    return this->depth;
}

template <class T>
    requires std::totally_ordered<T>
BstNode<T> *BinarySearchTree<T>::Search(T value)
{
    if (this->root == nullptr)
    {
        return nullptr;
    }

    BstNode<T> *current = this->root;

    while (current != nullptr)
    {
        if (current->GetValue() == value)
        {
            return current;
        }

        if (current->GetValue() <= value)
        {
            current = current->right;
            continue;
        }
        else
        {
            current = current->left;
            continue;
        }
    }

    return nullptr;
}

template <class T>
    requires std::totally_ordered<T>
bool BinarySearchTree<T>::HasValue(T value)
{
    auto node = this->Search(value);
    return !(node == nullptr);
}

template <class T>
    requires std::totally_ordered<T>
void BinarySearchTree<T>::Clear()
{
    this->amount = 0;
    this->depth = 0;

    if (this->root != nullptr)
    {
        delete this->root;
    }
    this->root = nullptr;
}