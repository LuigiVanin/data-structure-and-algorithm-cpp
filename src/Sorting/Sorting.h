
#ifndef SORTING_H
#define SORTING_H

#include "../ArrayList/ArrayList.h"
#include <functional>

namespace sorting {

template <class T> //
int DefaultCompareFunction(T a, T b) {
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    return 0;
}

template <class T> //
void BubbleSort(ArrayList<T>            *array,
                std::function<int(T, T)> compare = DefaultCompareFunction<T>);

template <class T> //
void InsertionSort(
    ArrayList<T>            *array,
    std::function<int(T, T)> compare = DefaultCompareFunction<T>);

template <class T> //
void QuickSort(ArrayList<T>            *array,
               std::function<int(T, T)> compare = DefaultCompareFunction<T>);

template <class T> //
void BogoSort(ArrayList<T>            *array,
              std::function<int(T, T)> compare = DefaultCompareFunction<T>);

} // namespace sorting

#endif
