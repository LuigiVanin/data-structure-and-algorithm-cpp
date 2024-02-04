#include "LinkedQueue.h"
#include "../DoublyLinkedList/DoublyLinkedList.h"
#include <cstdlib>

template <class T>
LinkedQueue<T>::LinkedQueue()
{
    this->queue = new DoublyLinkedList<T>();
}

template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    delete this->queue;
}

template <class T>
auto LinkedQueue<T>::Length() -> int
{
    return this->queue->Length();
}

template <class T>
auto LinkedQueue<T>::Add(T value) -> void
{
    this->queue->Push(value);
}

template <class T>
auto LinkedQueue<T>::Remove() -> T
{
    auto item = this->queue->getHead();
    if (item == nullptr)
        throw new std::runtime_error("queue is empty");

    auto item_value = item->value;

    this->queue->Unshift();
    return item_value;
}

template <class T>
auto LinkedQueue<T>::Peek() -> T
{
    auto head = this->queue->getHead();
    if (head == nullptr)
        throw new std::runtime_error("queue is empty");

    return head->value;
}

template <class T>
auto LinkedQueue<T>::IsEmpty() -> bool
{
    return this->queue->Length() <= 0;
}