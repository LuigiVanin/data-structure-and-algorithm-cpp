#include "LinkedList.h"
#include "LinkedNode.h"
#include <iostream>
#include <cstdlib>

template <class T>
LinkedList<T>::LinkedList()
{
    std::cout << "TESTE" << std::endl;
    this->length = 0;
    this->head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    if (this->head != nullptr)
        delete this->head;
}

template <class T>
auto LinkedList<T>::Push(T value) -> Node<T> *
{

    if (this->head == nullptr)
    {
        Node<T> *new_node = new Node<T>(value);
        this->head = new_node;
        this->length++;
        return nullptr;
    }

    auto temp = this->head;

    while (temp->Next() != nullptr)
    {
        temp = temp->Next();
    }

    auto next_value = temp->Append(value);
    this->length++;
    return next_value;
}

template <class T>
auto LinkedList<T>::Shift(T value) -> Node<T> *
{
    Node<T> *new_node = new Node<T>(value);

    if (this->head == nullptr)
    {
        this->head = new_node;
        this->length++;
        return new_node;
    }

    auto temp = this->head;
    new_node->Append(temp);
    this->head = new_node;
    return new_node;
}

template <class T>
auto LinkedList<T>::Insert(T value, int pos) -> Node<T> *
{
    if (pos > this->length)
        return nullptr;

    this->length++;
    if (pos == 0)
        return this->Shift(value);
    if (pos == (this->length - 1))
        return this->Push(value);

    if (this->head == nullptr)
        return nullptr;

    auto temp = this->head;

    for (int i = 0; i < pos - 1; i++)
    {
        if (temp->Next() == nullptr)
            return nullptr;
        temp = temp->Next();
    }

    auto new_node = new Node(value);
    auto temp_next = temp->Next();
    new_node->Append(temp_next);
    temp->Append(new_node);

    return new_node;
}

template <class T>
auto LinkedList<T>::Print() -> void
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
