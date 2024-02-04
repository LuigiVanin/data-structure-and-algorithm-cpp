#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#pragma once
#include "../ArrayList/ArrayList.h"

template <class T>
class ArrayStack
{
public:
    ArrayStack();
    ~ArrayStack();

    auto Length() -> int;
    auto Push(T value) -> void;
    auto Top() -> T;
    auto Pop() -> T;
    auto IsEmpty() -> bool;
    auto toArray() -> T *;

private:
    ArrayList<T> *stack;
};

#include "ArrayStack.cpp"

#endif