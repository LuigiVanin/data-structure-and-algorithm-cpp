#include "ArrayStack.h"

template <class T>
ArrayStack<T>::ArrayStack()
{
    this->stack = new ArrayList<T>();
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
    delete this->stack;
}

template <class T>
auto ArrayStack<T>::Length() -> int
{
    return this->stack->Length();
}

template <class T>
auto ArrayStack<T>::Push(T value) -> void
{
    return this->stack->Push(value);
}

template <class T>
auto ArrayStack<T>::Pop() -> T
{

    auto top = this->Top();
    this->stack->Pop();
    return top;
}

template <class T>
auto ArrayStack<T>::Top() -> T
{
    return this->stack->At(this->Length() - 1);
}

template <class T>
auto ArrayStack<T>::IsEmpty() -> bool
{

    return this->Length() <= 0;
}

template <class T>
auto ArrayStack<T>::toArray() -> T *
{
    auto arr = new T[this->Length()];
    for (int i = 0; i < this->Length(); i++)
    {
        arr[i] = this->stack->At(i);
    }

    return arr;
}