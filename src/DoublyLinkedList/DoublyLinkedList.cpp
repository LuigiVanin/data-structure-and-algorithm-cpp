#include "DoublyLinkedList.h"
#include "DoublyLinkedNode.h"
#include "../utils/errors.h"
#include <cstdlib>

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    if (this->head != nullptr)
        delete this->head;

    if (this->tail != nullptr)
        delete this->tail;
}

template <class T>
auto DoublyLinkedList<T>::Length() -> int
{
    return this->length;
}

template <class T>
auto DoublyLinkedList<T>::getHead() -> DoublyLinkedNode<T> *
{
    return this->head;
}

template <class T>
auto DoublyLinkedList<T>::getTail() -> DoublyLinkedNode<T> *
{
    return this->tail;
}

template <class T>
auto DoublyLinkedList<T>::Push(T value) -> DoublyLinkedNode<T> *
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::Shift(T value) -> DoublyLinkedNode<T> *
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::At(int index) -> T
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::Pop() -> void
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::Unshift() -> void
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::Print() -> void
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::Insert(int pos, T value) -> void
{
    throw new NotImplementedException();
}

template <class T>
auto DoublyLinkedList<T>::Remove(int pos) -> void
{
    throw new NotImplementedException();
}
