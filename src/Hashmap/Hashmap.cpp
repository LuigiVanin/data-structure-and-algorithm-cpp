#include "Hashmap.h"
#include "Tuple.h"

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
}

template <class Key, class Value>
void Hashmap<Key, Value>::Put(Key k, Value v)
{
    auto targetKeyHash = this->hashKey(k);
    LinkedList<Tuple<Key, Value>> targetList = this->table.GetArray()[targetKeyHash];

    std::cout << "Teste " << targetList.length << "\n";

    auto tuple = Tuple<Key, Value>(k, v);
    std::cout << tuple.GetKey() << " " << tuple.GetValue() << "\n";

    targetList.Push({k, v});
    // targetList.Shift(Tuple<Key, Value>(k, v));
}

template <class Key, class Value>
int Hashmap<Key, Value>::hashKey(Key key)
{
    auto hash_id = (int)std::hash<Key>{}(key);
    return abs(hash_id % this->buckets);
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
