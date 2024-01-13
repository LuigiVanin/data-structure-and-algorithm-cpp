#include "ArrayList.h"
#include <iostream>
#include <stdlib.h>
#include <string>

// Public

template <class T>
ArrayList<T>::ArrayList()
{
    std::cout << "Criando uma Array List" << std::endl;
    this->arr = new T[this->capacity];
    this->length = 0;
}

template <class T>
ArrayList<T>::~ArrayList()
{
    std::cout << "Destruindo uma Array List" << std::endl;
    delete[] this->arr;
}

template <class T>
auto ArrayList<T>::Push(T value) -> void
{
    if (this->length == this->capacity)
        this->resize();

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
auto ArrayList<T>::Insert(T value, int pos) -> void
{
    if (this->length < pos)
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

// Private

template <class T>
auto ArrayList<T>::resize() -> void
{
    this->capacity *= 2;
    auto new_arr = static_cast<T *>(realloc(this->arr, this->capacity * sizeof(T)));

    if (new_arr == nullptr)
    {
        const char *error_message = "Falha na alocação de memória durante o redimensionamento.";
        std::cerr << error_message << std::endl;
        throw std::runtime_error(error_message);
    }
}
