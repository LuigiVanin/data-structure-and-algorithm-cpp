#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#pragma once

#include "../DoublyLinkedList/DoublyLinkedList.h"

template <class T>
class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue();

    auto Add(T value) -> void;
    auto Remove() -> T;
    auto IsEmpty() -> bool;
    auto Peek() -> T;
    auto Length() -> int;

private:
    DoublyLinkedList<T> *queue;
};

#include "LinkedQueue.cpp"

#endif