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

    auto getHead() -> Node<T> *;
    auto At(int index) -> T;
    auto Push(T value) -> Node<T> *;
    auto Shift(T value) -> Node<T> *;
    auto Insert(T value, int pos) -> Node<T> *;
    auto Pop() -> void;
    auto Remove(int pos) -> void;
    auto Print() -> void;

private:
    Node<T> *head = nullptr;
};

#include "LinkedList.cpp"
#endif