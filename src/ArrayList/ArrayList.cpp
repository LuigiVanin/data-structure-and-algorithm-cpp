#include "ArrayList.h"
#include <iostream>
#include <stdlib.h>
#include <string>

// Public

template <class T>
ArrayList<T>::ArrayList(int initial_capacity)
{
    this->capacity = initial_capacity;
    this->arr = new T[this->capacity];
    this->length = 0;
}

template <class T>
ArrayList<T>::~ArrayList()
{
    delete[] this->arr;
}

template <class T>
auto ArrayList<T>::Push(T value) -> void
{
    if (this->length == this->capacity)
    {
        this->resize();
    }

    this->arr[this->length] = value;
    this->length++;
}

template <class T>
auto ArrayList<T>::Print(void) -> void
{
    std::cout << "[";
    for (int i = 0; i < this->length; i++)
    {
        std::cout << this->arr[i] << ", ";
    }
    std::cout << "]\n";
}

template <class T>
auto ArrayList<T>::Pop(void) -> void
{
    if (this->length == 0)
    {
        return;
    }

    this->length--;
}

template <class T>
auto ArrayList<T>::At(int index) -> T
{
    if (index > this->length - 1 || index < 0)
    {
        const char *error_message = "O index está fora dos limites";
        throw std::runtime_error(error_message);
    }
    return this->arr[index];
}

template <class T>
auto ArrayList<T>::Insert(T value, int pos) -> void
{
    if (this->length < pos || pos < 0)
        return;

    if (this->length == this->capacity)
        this->resize();

    if (this->length == pos)
        return this->Push(value);

    T prev_value = value;
    T temp = value;

    this->length++;
    for (int i = pos; i < this->length; i++)
    {
        temp = this->arr[i];
        this->arr[i] = prev_value;
        prev_value = temp;
    }
}

template <class T>
auto ArrayList<T>::Remove(int pos) -> void
{
    if (this->length <= pos)
        return;

    if (pos == this->length - 1)
    {
        this->Pop();
        return;
    }

    this->length--;
    for (int i = pos; i < this->length; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }
}

template <class T>
auto ArrayList<T>::GetCapacity() -> int
{
    return this->capacity;
}

// Private

template <class T>
auto ArrayList<T>::resize() -> void
{
    this->capacity *= 2;
    auto new_arr = new T[this->capacity];

    for (int i = 0; i < this->length; i++)
        new_arr[i] = this->arr[i];

    delete[] this->arr;
    this->arr = new_arr;
}

// auto list = new ArrayList<int>();

// list->Print();
// list->Push(1);
// list->Push(2);
// list->Push(3);
// list->Push(4);
// list->Push(5);
// list->Push(6);
// list->Push(7);

// list->Print();
// list->Push(8);
// list->Push(9);
// list->Push(10);
// list->Push(11);
// list->Push(12);
// list->Push(13);
// list->Push(14);
// list->Print();

// list->Push(15);
// list->Push(16);
// list->Push(17);
// list->Push(18);
// list->Push(19);
// list->Push(20);
// list->Push(21);

// list->Print();

// list->Insert(1000, 2);
// list->Print();
// list->Insert(1000, 0);
// list->Print();

// list->Insert(1000, list->length);

// list->Print();

// list->Remove(2);
// list->Remove(list->length - 1);
// list->Remove(0);

// list->Print();
