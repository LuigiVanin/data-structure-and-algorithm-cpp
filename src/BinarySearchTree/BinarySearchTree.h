#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#pragma once
#include <concepts>

template <class T>
    requires std::totally_ordered<T>
class BinarySearchTree
{
};

#include "BinarySearchTree.cpp"
#endif