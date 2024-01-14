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