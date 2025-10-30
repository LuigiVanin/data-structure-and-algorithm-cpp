
#ifndef SORTING_H
#define SORTING_H

#include "../ArrayList/ArrayList.h"

namespace sorting {

template <class T>
int _defaultCompare(T a, T b) {
    return a - b;
}

template <typename T>
void _swapIndex(T *arr, int i, int j) {
    auto temp = arr[i];
    arr[i]    = arr[j];
    arr[j]    = temp;
}

// NOTE:
//      Compare type could also be declared as
//      template <class T, Compare = decltype(_defaultCompare<T>)
template <class T>
void BubbleSort(ArrayList<T>                *list,
                decltype(_defaultCompare<T>) compare = _defaultCompare<T>) {
    T *array = list->GetArray();

    for (int i = 0; i < list->Length(); i++) {
        for (int j = 0; j < list->Length() - i - 1; j++) {
            auto comparisonResult = compare(array[j], array[j + 1]);

            if (comparisonResult > 0) _swapIndex(array, j, j + 1);
        }
    }
}

template <class T>
void InsertionSort(ArrayList<T>                *list,
                   decltype(_defaultCompare<T>) compare = _defaultCompare<T>) {

    T *array = list->GetArray();

    for (int i = 0; i < list->Length(); i++) {
        for (int j = i; j > 0; j--) {
            auto comparisonResult = compare(array[j - 1], array[j]);

            if (comparisonResult > 0)
                _swapIndex(array, j - 1, j);
            else
                break;
        }
    }
}

template <class T>
void QuickSort(ArrayList<T>                *list,
               int                          start,
               int                          end,
               decltype(_defaultCompare<T>) compare = _defaultCompare<T>) {
    // Implementation here
    if (end > start) {
        // NOTE:
        //      There is many ways to choose the initial pivot, in this case
        //      the last item will always be the pivot of the pertition
        T  *array      = list->GetArray();
        T   pivot      = list->At(end);
        int pivotIndex = start;

        for (int i = start; i < end; i++) {
            auto comparisonResult = compare(pivot, array[i]);
            if (comparisonResult > 0) {
                _swapIndex(array, i, pivotIndex);
                pivotIndex++;
            }
        }

        _swapIndex(array, pivotIndex, end);

        QuickSort(list, start, pivotIndex - 1, compare);
        QuickSort(list, pivotIndex + 1, end, compare);
    }
}

template <class T>
void QuickSort(ArrayList<T>                *list,
               decltype(_defaultCompare<T>) compare = _defaultCompare<T>) {
    // Implementation here
    int start = 0, end = list->Length() - 1;
    QuickSort(list, start, end, compare);
}

} // namespace sorting

// template <class T>
// void QuickSortPartition()

#endif
