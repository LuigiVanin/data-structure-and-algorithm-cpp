#include "LinkedNode.h"
#include <cstdlib>
#include <iostream>

template <class T>
Node<T>::Node(T value)
{
    this->value = value;
    this->next = nullptr;
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
auto Node<T>::Next() -> Node<T> *
{
    return this->next;
}

template <class T>
auto Node<T>::Append(T value) -> Node<T> *
{
    auto new_node = new Node(value);
    this->next = new_node;

    return new_node;
}

template <class T>
auto Node<T>::Append(Node<T> *value) -> Node<T> *
{
    auto new_node = value;
    this->next = new_node;

    return new_node;
}
