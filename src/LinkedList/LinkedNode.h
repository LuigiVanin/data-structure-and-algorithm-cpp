#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#pragma once

template <class T>
class Node
{
public:
    T value;

    Node(T value);
    ~Node();

    auto Next() -> Node<T> *;
    auto Append(T value) -> Node<T> *;

private:
    Node<T> *next;
};

#include "LinkedNode.cpp"
#endif