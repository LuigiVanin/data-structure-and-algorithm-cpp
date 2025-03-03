#include "DoublyLinkedList.h"
#include "DoublyLinkedNode.h"
#include "../utils/errors.h"
#include <cstdlib>
#include <iostream>

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
    auto new_node = new DoublyLinkedNode<T>(value);

    this->length++;
    if (this->head == nullptr && this->tail == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
        return new_node;
    }

    new_node->AttachPrev(this->tail);
    this->tail->AttachNext(new_node);
    this->tail = new_node;

    return new_node;
}

template <class T>
auto DoublyLinkedList<T>::Shift(T value) -> DoublyLinkedNode<T> *
{
    if (this->head == nullptr && this->tail == nullptr)
        return this->Push(value);

    auto new_node = new DoublyLinkedNode<T>(value);

    this->length++;
    auto temp = this->head;
    new_node->AttachNext(temp);
    temp->AttachPrev(new_node);
    this->head = new_node;

    return new_node;
}

template <class T>
auto DoublyLinkedList<T>::At(int index) -> T
{
    if (index > this->length - 1 || index < 0)
        throw std::invalid_argument("Index out of bounds");

    auto temp = this->head;

    for (int i = 0; i < index; i++)
        temp = temp->Next();

    return temp->value;
}

template <class T>
auto DoublyLinkedList<T>::Pop() -> void
{
    if (this->length == 0)
        return;

    if (this->length == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->length--;
        return;
    }

    this->length--;
    auto temp = this->tail->Prev();
    this->tail->Detach();
    delete this->tail;
    this->tail = temp;
}

template <class T>
auto DoublyLinkedList<T>::Unshift() -> void
{
    if (this->length == 0)
        return;

    if (this->head == nullptr || this->tail == nullptr)
        return;

    if (this->length == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->length--;
        return;
    }

    this->length--;
    auto temp = this->head->Next();
    this->head->Detach();
    delete this->head;
    this->head = temp;
}

template <class T>
auto DoublyLinkedList<T>::Print() -> void
{
    auto temp = this->head;

    std::cout << "[";
    while (temp != nullptr)
    {
        std::cout << temp->value << " -> ";
        temp = temp->Next();
    }
    std::cout << "]\n";
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
