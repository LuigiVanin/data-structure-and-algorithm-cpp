#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#pragma once

#include <cstdlib>

template <class T>
class ArrayList
{
private:
    T *arr = nullptr;

    auto resize() -> void;
    int capacity = 8;

public:
    int length = 0;

    ArrayList(int initial_capacity = 8);
    ~ArrayList();

    auto GetArray() -> T *;
    auto Push(T value) -> void;
    auto Print(void) -> void;
    auto Pop(void) -> void;
    auto At(int index) -> T;
    auto Insert(T value, int pos) -> void;
    auto Remove(int pos) -> void;
    auto Length() -> int;
    auto GetCapacity() -> int;
};

#include "ArrayList.cpp"
#endif