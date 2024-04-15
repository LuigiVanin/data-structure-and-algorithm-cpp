#include "Tuple.h"

template <class K, class V>
Tuple<K, V>::Tuple(K k, V v)
{
    this->key = k;
    this->value = v;
}

template <class K, class V>
K Tuple<K, V>::GetKey()
{
    return this->key;
}

template <class K, class V>
Tuple<K, V>::~Tuple() {}

template <class K, class V>
V Tuple<K, V>::GetValue()
{
    return this->value;
}

template <class K, class V>
void Tuple<K, V>::SetValue(V v)
{
    this->value = v;
}

template <class K, class V>
void Tuple<K, V>::SetKey(K k)
{
    this->key = k;
}
