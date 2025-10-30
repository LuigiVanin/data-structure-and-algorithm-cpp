
#ifndef SORTING_H
#define SORTING_H

#include "../ArrayList/ArrayList.h"
#include <ostream>

namespace sorting {

template <class T> //
int DefaultCompareFunction(T a, T b) {
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    return 0;
}

template <typename T> void swapIndex(T *arr, int i, int j) {

    auto temp = arr[i];
    arr[i]    = arr[j];
    arr[j]    = temp;
}

template <class T, typename Compare = decltype(DefaultCompareFunction<T>)>
void BubbleSort(ArrayList<T> *list,
                Compare       compare = DefaultCompareFunction<T>) {
    T *array = list->GetArray();

    for (int i = 0; i < list->Length(); i++) {
        for (int j = 0; j < list->Length() - i - 1; j++) {
            auto comparisonResult = compare(array[j], array[j + 1]);

            if (comparisonResult > 0) swapIndex(array, j, j + 1);
        }
    }
}

template <class T, typename Compare = decltype(DefaultCompareFunction<T>)>
void InsertionSort(ArrayList<T> *list,
                   Compare       compare = DefaultCompareFunction<T>) {

    T *array = list->GetArray();

    for (int i = 0; i < list->Length(); i++) {
        for (int j = i - 1; j >= 0; j--) {
        }
    }
}

template <class T, typename Compare = decltype(DefaultCompareFunction<T>)>
void QuickSort(ArrayList<T> *array,
               Compare       compare = DefaultCompareFunction<T>) {
    // Implementation here
}

} // namespace sorting

#endif
