#include "Hashmap.h"
#include "Tuple.h"
#include "../LinkedList/LinkedNode.h"

template <class Key, class Value>
Hashmap<Key, Value>::Hashmap(int buckets)
{
    this->buckets = buckets;
    this->table = ArrayList<LinkedList<Tuple<Key, Value>>>(this->buckets);

    for (int i = 0; i < this->buckets; i++)
    {
        table.Push(LinkedList<Tuple<Key, Value>>());
    }
}

template <class Key, class Value>
Hashmap<Key, Value>::~Hashmap()
{
    // delete this->table;
    // this->Clear();
}

template <class Key, class Value>
void Hashmap<Key, Value>::Put(Key k, Value v)
{

    auto targetKeyHash = this->hashKey(k);

    LinkedList<Tuple<Key, Value>> *targetList = this->getHashList(targetKeyHash);

    auto tuple = Tuple<Key, Value>(k, v);

    targetList->Shift({k, v});
}

template <class Key, class Value>
LinkedList<Tuple<Key, Value>> *Hashmap<Key, Value>::getHashList(int hash)
{
    return &this->table.GetArray()[hash];
}

template <class Key, class Value>
Option<Value> Hashmap<Key, Value>::Get(Key k)
{

    auto targetKeyHash = this->hashKey(k);

    LinkedList<Tuple<Key, Value>> *targetList = this->getHashList(targetKeyHash);
    Node<Tuple<Key, Value>> *head = targetList->getHead();

    if (!head)
    {
        return Option<Value>();
    }

    auto temp = head;

    while (temp != nullptr)
    {
        if (temp->value.GetKey() == k)
        {
            return Option<Value>(temp->value.GetValue());
        }

        temp = temp->Next();
    }

    return Option<Value>();
}

template <class Key, class Value>
int Hashmap<Key, Value>::hashKey(Key key)
{
    auto hashId = (int)std::hash<Key>{}(key);
    return abs(hashId % this->buckets);
}

template <class Key, class Value>
double Hashmap<Key, Value>::getLoadFactor()
{
    return (double)this->length / (double)this->buckets;
}

template <class Key, class Value>
int Hashmap<Key, Value>::GetLength()
{
    return this->length;
}

template <class Key, class Value>
int Hashmap<Key, Value>::GetBuckets()
{
    return this->buckets;
}

template <class Key, class Value>
void Hashmap<Key, Value>::Clear()
{
    for (int i = 0; i < buckets; i++)
    {
        table.GetArray()[i] = LinkedList<Tuple<Key, Value>>();
    }
}
