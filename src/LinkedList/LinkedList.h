#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

#include <cstdlib>
#include "LinkedNode.h"

template <class T>
class LinkedList
{
public:
    int length = 0;

    LinkedList();
    ~LinkedList();

    auto Push(T value) -> Node<T> *;
    auto Print() -> void;

private:
    Node<T> *head = nullptr;
};

#include "LinkedList.cpp"
#endif