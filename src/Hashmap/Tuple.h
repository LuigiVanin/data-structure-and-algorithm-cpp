#ifndef TUPLE_H
#define TUPLE_H

#pragma once

template <class K, class V>
class Tuple
{
    K key;
    V value;

public:
    Tuple(K c, V v);
    Tuple() : key(K()), value(V()) {}
    // ~Tuple();

    K GetKey();
    V GetValue();
    void SetValue(V value);
    void SetKey(K key);
};

#include "Tuple.cpp"

#endif