#include "LinkedList.h"
#include "LinkedNode.h"
#include <iostream>
#include <cstdlib>

template <class T>
LinkedList<T>::LinkedList()
{
    this->length = 0;
    this->head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *current = this->head;
    while (current != nullptr)
    {
        Node<T> *next = current->Next();
        delete current;
        current = next;
    }
}

template <class T>
auto LinkedList<T>::getHead() -> Node<T> *
{
    return this->head;
}

template <class T>
auto LinkedList<T>::At(int index) -> T
{
    if (index > this->length - 1 || index < 0)
        throw std::invalid_argument("Index out of bounds");

    auto temp = this->head;

    for (int i = 0; i < index; i++)
        temp = temp->Next();

    return temp->value;
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

    this->length++;
    if (this->head == nullptr)
    {
        this->head = new_node;
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

    if (pos == 0)
        return this->Shift(value);
    if (pos == (this->length - 1))
        return this->Push(value);

    if (this->head == nullptr)
        return nullptr;

    this->length++;
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
auto LinkedList<T>::Pop() -> void
{
    if (this->head == nullptr)
        return;

    if (this->head->Next() == nullptr)
    {
        this->head = nullptr;
        this->length--;
        return;
    }

    auto temp = this->head;
    this->length--;
    for (int i = 0; i < this->length - 1; i++)
        temp = temp->Next();

    auto node_to_delete = temp->Next();
    temp->Append(nullptr);
    delete node_to_delete;
}

template <class T>
auto LinkedList<T>::Remove(int index) -> void
{   
    if (index > this->length - 1 || index < 0)
        throw std::invalid_argument("Index out of bounds");

    if (index == 0)
    {
        auto temp = this->head;
        this->head = temp->Next();
        delete temp;
        this->length--;
        return;
    }

    auto temp = this->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->Next();

    auto node_to_delete = temp->Next();
    temp->Append(node_to_delete->Next());
    delete node_to_delete;
    this->length--;
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

template <class T>
auto LinkedList<T>::Clear() -> void
{
    Node<T> *current = this->head;
    while (current != nullptr)
    {
        Node<T> *next = current->Next();
        delete current;
        current = next;
    }
    this->head = nullptr;
    this->length = 0;
}
