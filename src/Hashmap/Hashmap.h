#ifndef HASHMAP_H
#define HASHMAP_H

#pragma once

#include "../LinkedList/LinkedList.h"
#include "../ArrayList/ArrayList.h"
#include "Tuple.h"
#include "../utils/option.h"

template <class Key, class Value>
class Hashmap
{
public:
    Hashmap(int buckets = 8);
    ~Hashmap();

    int GetLength();
    int GetBuckets();

    Option<Value> Get(Key k);
    void Put(Key k, Value v);
    void Remove(Key k);
    void Clear();

private:
    int buckets = 8;
    int length = 0;
    ArrayList<LinkedList<Tuple<Key, Value>>> table;

    int hashKey(Key key);
    double getLoadFactor();
    LinkedList<Tuple<Key, Value>> *getHashList(int hash);
};

#include "Hashmap.cpp"
#endif