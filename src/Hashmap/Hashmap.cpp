#include "Hashmap.h"
#include "Tuple.h"
#include "../LinkedList/LinkedNode.h"

template <class Key, class Value>
Hashmap<Key, Value>::Hashmap(int buckets)
{
    this->buckets = buckets;
    this->table = new ArrayList<LinkedList<Tuple<Key, Value>> *>(this->buckets);

    for (int i = 0; i < this->buckets; i++)
    {
        table->Push(new LinkedList<Tuple<Key, Value>>());
    }
}

template <class Key, class Value>
Hashmap<Key, Value>::~Hashmap()
{
    auto arr = this->table->GetArray();
    for (int i = 0; i < this->buckets; i++)
    {
        delete arr[i];
    }

    delete this->table;
}

template <class Key, class Value>
void Hashmap<Key, Value>::Put(Key k, Value v)
{
    if (this->getLoadFactor() > 0.7)
        this->resize();

    auto targetKeyHash = this->hashKey(k);
    auto targetList = this->getHashListItem(targetKeyHash);

    targetList->Shift({k, v});
    this->length++;
}

template <class Key, class Value>
LinkedList<Tuple<Key, Value>> *Hashmap<Key, Value>::getHashListItem(int hash)
{
    return this->table->GetArray()[hash];
}

template <class Key, class Value>
Option<Value> Hashmap<Key, Value>::Get(Key k)
{

    auto targetKeyHash = this->hashKey(k);

    auto targetList = this->getHashListItem(targetKeyHash);
    Node<Tuple<Key, Value>> *head = targetList->getHead();

    if (!head)
        return Option<Value>();

    auto temp = head;

    while (temp != nullptr)
    {
        if (temp->value.GetKey() == k)
            return Option<Value>(temp->value.GetValue());

        temp = temp->Next();
    }

    return Option<Value>();
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
    auto arr = table->GetArray();
    for (int i = 0; i < buckets; i++)
    {
        delete arr[i];
        arr[i] = new LinkedList<Tuple<Key, Value>>();
    }
}

template <class Key, class Value>
void Hashmap<Key, Value>::resize()
{
    auto oldTable = this->table;
    this->length = 0;
    this->buckets *= 2;
    this->table = new ArrayList<LinkedList<Tuple<Key, Value>> *>(this->buckets);

    for (int i = 0; i < this->buckets; i++)
    {
        table->Push(new LinkedList<Tuple<Key, Value>>());
    }

    for (int i = 0; i < oldTable->length; i++)
    {
        auto *list = oldTable->At(i);
        auto *head = list->getHead();

        while (head != nullptr)
        {
            auto key = head->value.GetKey();
            auto value = head->value.GetValue();
            if (this->Get(key).IsNone())
            {

                this->Put(key, value);
            }
            head = head->Next();
        }
    }

    delete oldTable;
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
