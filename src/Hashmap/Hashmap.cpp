#include "Hashmap.h"
#include "Tuple.h"

template <class Key, class Value>
Hashmap<Key, Value>::Hashmap(int buckets)
{
    this->buckets = buckets;
    this->tabela = ArrayList<LinkedList<Tuple<Key, Value>>>(this->buckets);
}

template <class Key, class Value>
Hashmap<Key, Value>::~Hashmap()
{
}

template <class Key, class Value>
int Hashmap<Key, Value>::hashKey(Key key)
{
    auto hash_id = (int)hash<Chave>{}(key);
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
