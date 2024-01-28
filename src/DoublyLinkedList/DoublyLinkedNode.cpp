#include "DoublyLinkedNode.h"
#include <cstdlib>

template <class T>
DoublyLinkedNode<T>::DoublyLinkedNode(T value)
{
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
DoublyLinkedNode<T>::~DoublyLinkedNode()
{
    if (this->prev != nullptr)
        delete this->prev;
    if (this->next != nullptr)
        delete this->next;
}

template <class T>
auto DoublyLinkedNode<T>::Next() -> DoublyLinkedNode<T> *
{
    return this->next();
}

template <class T>
auto DoublyLinkedNode<T>::Prev() -> DoublyLinkedNode<T> *
{
    return this->prev();
}

template <class T>
auto DoublyLinkedNode<T>::AttachNext(T value)
{
    auto node = new DoublyLinkedNode<T>(value);
    if (this->next != nullptr)
        delete this->next;

    this->next = node;
}

template <class T>
auto DoublyLinkedNode<T>::AttachPrev(T value)
{
    auto node = new DoublyLinkedNode<T>(value);
    if (this->prev != nullptr)
        delete this->prev;

    this->prev = node;
}

template <class T>
auto DoublyLinkedNode<T>::AttachNext(DoublyLinkedNode<T> *node)
{
    if (this->next != nullptr)
        delete this->next;

    this->next = node;
}

template <class T>
auto DoublyLinkedNode<T>::AttachPrev(DoublyLinkedNode<T> *node)
{

    if (this->prev != nullptr)
        delete this->prev;

    this->prev = node;
}
