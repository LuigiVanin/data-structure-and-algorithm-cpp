#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cstdlib>

template <class T>
class ArrayList
{
private:
    T *arr = nullptr;
    int capacity = 4;

    auto resize() -> void;

public:
    int length = 0;

    ArrayList();
    ~ArrayList();

    auto GetArray() -> T *;
    auto Push(T value) -> void;
    auto Print(void) -> void;
    auto Pop(void) -> void;
    auto Insert(T value, int pos) -> void;
    auto Remove(int pos) -> void;
};

#include "ArrayList.cpp"
#endif