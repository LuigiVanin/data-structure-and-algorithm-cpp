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
    this->Detach();
    if (this->next != nullptr)
        delete this->next;
}

template <class T>
auto DoublyLinkedNode<T>::Next() -> DoublyLinkedNode<T> *
{
    return this->next;
}

template <class T>
auto DoublyLinkedNode<T>::Prev() -> DoublyLinkedNode<T> *
{
    return this->prev;
}

template <class T>
auto DoublyLinkedNode<T>::AttachNext(T value)
{
    auto node = new DoublyLinkedNode<T>(value);
    if (this->next != nullptr)
        this->next->Detach();

    this->next = node;
    node->prev = this;
}

template <class T>
auto DoublyLinkedNode<T>::AttachPrev(T value)
{
    auto node = new DoublyLinkedNode<T>(value);
    if (this->prev != nullptr)
        this->prev->Detach();

    this->prev = node;
    node->next = this;
}

template <class T>
auto DoublyLinkedNode<T>::AttachNext(DoublyLinkedNode<T> *node)
{
    if (this->next != nullptr)
        this->next->Detach();

    this->next = node;
    if (node != nullptr)
        node->prev = this;
}

template <class T>
auto DoublyLinkedNode<T>::AttachPrev(DoublyLinkedNode<T> *node)
{
    if (this->prev != nullptr)
        this->prev->Detach();

    this->prev = node;
    if (node != nullptr)
        node->next = this;
}

template <class T>
void DoublyLinkedNode<T>::Detach()
{
    if (this->prev != nullptr)
        this->prev->next = this->next;
    if (this->next != nullptr)
        this->next->prev = this->prev;
    this->prev = nullptr;
    this->next = nullptr;
}
