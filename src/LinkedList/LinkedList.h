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
    Node<T> *head = nullptr;

    LinkedList();
    ~LinkedList();

    auto Push(T value) -> Node<T> *;
    auto Shift(T value) -> Node<T> *;
    auto Insert(T value, int pos) -> Node<T> *;
    auto Print() -> void;

private:
};

#include "LinkedList.cpp"
#endif