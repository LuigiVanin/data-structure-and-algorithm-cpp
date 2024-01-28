#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#pragma once
#include "DoublyLinkedNode.h"

template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    auto getHead() -> DoublyLinkedNode<T> *;
    auto getTail() -> DoublyLinkedNode<T> *;
    auto Length() -> int;

    auto Push(T value) -> DoublyLinkedNode<T> *;
    auto Shift(T value) -> DoublyLinkedNode<T> *;
    auto At(int index) -> T;
    auto Pop() -> void;
    auto Unshift() -> void;
    auto Print() -> void;
    auto Insert(int pos, T value) -> void;
    auto Remove(int pos) -> void;

private:
    int length;

    DoublyLinkedNode<T> *head;
    DoublyLinkedNode<T> *tail;
};

#include "DoublyLinkedList.cpp"
#endif