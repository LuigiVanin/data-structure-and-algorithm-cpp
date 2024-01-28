#ifndef DOUBLYLINKEDNODE_H
#define DOUBLYLINKEDNODE_H

#pragma once

template <class T>
class DoublyLinkedNode
{
public:
    T value;

    DoublyLinkedNode(T value);
    ~DoublyLinkedNode();

    auto Next() -> DoublyLinkedNode<T> *;
    auto Prev() -> DoublyLinkedNode<T> *;
    auto AttachNext(T value);
    auto AttachPrev(T value);
    auto AttachNext(DoublyLinkedNode<T> *node);
    auto AttachPrev(DoublyLinkedNode<T> *node);

private:
    DoublyLinkedNode<T> *prev;
    DoublyLinkedNode<T> *next;
};

#include "DoublyLinkedNode.cpp"
#endif