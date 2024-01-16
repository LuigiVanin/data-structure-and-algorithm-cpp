#include "LinkedList.h"
#include "LinkedNode.h"
#include <iostream>

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

    auto temp_next = this->head->Next();

    while (temp_next != nullptr)
    {
        temp_next = temp_next->Next();
    }

    temp_next->Append(value);
    this->length++;
    return temp_next->Next();
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
    new_node->next = temp;
    this->head = new_node;
}

// TODO: Test this function
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

    auto temp = this->head;

    for (int i = 0; i < pos; i++)
    {
        temp = temp->Next();
        if (temp == nullptr)
            return nullptr;
    }

    auto new_node = new Node(value);
    auto next = temp->next;
    new_node->next = next;
    temp->next = new_node;

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
