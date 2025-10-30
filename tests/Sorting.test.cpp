#define CATCH_CONFIG_MAIN
#include "../src/Sorting/Sorting.h"
#include "../src/ArrayList/ArrayList.h"
#include <catch2/catch_test_macros.hpp>

// Custom comparison functions for testing
int compareAscending(int a, int b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int compareDescending(int a, int b) {
    if (a > b) return -1;
    if (a < b) return 1;
    return 0;
}

// Helper function to verify array is sorted
template <typename T> bool isSortedAscending(ArrayList<T> *list) {
    for (int i = 0; i < list->Length() - 1; i++) {
        if (list->At(i) > list->At(i + 1)) {
            return false;
        }
    }
    return true;
}

template <typename T> bool isSortedDescending(ArrayList<T> *list) {
    for (int i = 0; i < list->Length() - 1; i++) {
        if (list->At(i) < list->At(i + 1)) {
            return false;
        }
    }
    return true;
}

TEST_CASE("Test BubbleSort algorithm", "[BubbleSort]") {

    SECTION("Sort with default compare function (ascending)") {
        auto list = new ArrayList<int>();
        list->Push(64);
        list->Push(34);
        list->Push(25);
        list->Push(12);
        list->Push(22);
        list->Push(11);
        list->Push(90);

        sorting::BubbleSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 11);
        REQUIRE(list->At(6) == 90);

        delete list;
    }

    SECTION("Sort with custom function pointer (ascending)") {
        auto list = new ArrayList<int>();
        list->Push(5);
        list->Push(2);
        list->Push(8);
        list->Push(1);
        list->Push(9);

        sorting::BubbleSort(list, compareAscending);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 1);
        REQUIRE(list->At(4) == 9);

        delete list;
    }

    SECTION("Sort with custom function pointer (descending)") {
        auto list = new ArrayList<int>();
        list->Push(5);
        list->Push(2);
        list->Push(8);
        list->Push(1);
        list->Push(9);

        sorting::BubbleSort(list, compareDescending);

        REQUIRE(isSortedDescending(list));
        REQUIRE(list->At(0) == 9);
        REQUIRE(list->At(4) == 1);

        delete list;
    }

    SECTION("Sort with lambda function (ascending)") {
        auto list = new ArrayList<int>();
        list->Push(100);
        list->Push(50);
        list->Push(75);
        list->Push(25);

        sorting::BubbleSort(list, [](int a, int b) -> int {
            if (a < b) return -1;
            if (a > b) return 1;
            return 0;
        });

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 25);
        REQUIRE(list->At(3) == 100);

        delete list;
    }

    SECTION("Sort with lambda function (descending)") {
        auto list = new ArrayList<int>();
        list->Push(100);
        list->Push(50);
        list->Push(75);
        list->Push(25);

        sorting::BubbleSort(list, [](int a, int b) -> int {
            if (a > b) return -1;
            if (a < b) return 1;
            return 0;
        });

        REQUIRE(isSortedDescending(list));
        REQUIRE(list->At(0) == 100);
        REQUIRE(list->At(3) == 25);

        delete list;
    }

    SECTION("Sort empty list") {
        auto list = new ArrayList<int>();

        REQUIRE_NOTHROW(sorting::BubbleSort(list));
        REQUIRE(list->Length() == 0);

        delete list;
    }

    SECTION("Sort single element list") {
        auto list = new ArrayList<int>();
        list->Push(42);

        sorting::BubbleSort(list);

        REQUIRE(list->Length() == 1);
        REQUIRE(list->At(0) == 42);

        delete list;
    }

    SECTION("Sort already sorted list") {
        auto list = new ArrayList<int>();
        list->Push(1);
        list->Push(2);
        list->Push(3);
        list->Push(4);
        list->Push(5);

        sorting::BubbleSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 1);
        REQUIRE(list->At(4) == 5);

        delete list;
    }

    SECTION("Sort list with duplicates") {
        auto list = new ArrayList<int>();
        list->Push(5);
        list->Push(2);
        list->Push(5);
        list->Push(1);
        list->Push(2);

        sorting::BubbleSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 1);
        REQUIRE(list->At(1) == 2);
        REQUIRE(list->At(2) == 2);
        REQUIRE(list->At(3) == 5);
        REQUIRE(list->At(4) == 5);

        delete list;
    }
}

TEST_CASE("Test InsertionSort algorithm", "[InsertionSort]") {

    SECTION("Sort with default compare function (ascending)") {
        auto list = new ArrayList<int>();
        list->Push(64);
        list->Push(34);
        list->Push(25);
        list->Push(12);
        list->Push(22);
        list->Push(11);
        list->Push(90);

        sorting::InsertionSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 11);
        REQUIRE(list->At(6) == 90);

        delete list;
    }

    SECTION("Sort with custom function pointer (ascending)") {
        auto list = new ArrayList<int>();
        list->Push(5);
        list->Push(2);
        list->Push(8);
        list->Push(1);
        list->Push(9);

        sorting::InsertionSort(list, compareAscending);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 1);
        REQUIRE(list->At(4) == 9);

        delete list;
    }

    SECTION("Sort with custom function pointer (descending)") {
        auto list = new ArrayList<int>();
        list->Push(5);
        list->Push(2);
        list->Push(8);
        list->Push(1);
        list->Push(9);

        sorting::InsertionSort(list, compareDescending);

        REQUIRE(isSortedDescending(list));
        REQUIRE(list->At(0) == 9);
        REQUIRE(list->At(4) == 1);

        delete list;
    }

    SECTION("Sort with lambda function (ascending)") {
        auto list = new ArrayList<int>();
        list->Push(100);
        list->Push(50);
        list->Push(75);
        list->Push(25);

        sorting::InsertionSort(list, [](int a, int b) -> int {
            if (a < b) return -1;
            if (a > b) return 1;
            return 0;
        });

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 25);
        REQUIRE(list->At(3) == 100);

        delete list;
    }

    SECTION("Sort with lambda function (descending)") {
        auto list = new ArrayList<int>();
        list->Push(100);
        list->Push(50);
        list->Push(75);
        list->Push(25);

        sorting::InsertionSort(list, [](int a, int b) -> int {
            if (a > b) return -1;
            if (a < b) return 1;
            return 0;
        });

        REQUIRE(isSortedDescending(list));
        REQUIRE(list->At(0) == 100);
        REQUIRE(list->At(3) == 25);

        delete list;
    }

    SECTION("Sort empty list") {
        auto list = new ArrayList<int>();

        REQUIRE_NOTHROW(sorting::InsertionSort(list));
        REQUIRE(list->Length() == 0);

        delete list;
    }

    SECTION("Sort single element list") {
        auto list = new ArrayList<int>();
        list->Push(42);

        sorting::InsertionSort(list);

        REQUIRE(list->Length() == 1);
        REQUIRE(list->At(0) == 42);

        delete list;
    }

    SECTION("Sort already sorted list") {
        auto list = new ArrayList<int>();
        list->Push(1);
        list->Push(2);
        list->Push(3);
        list->Push(4);
        list->Push(5);

        sorting::InsertionSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 1);
        REQUIRE(list->At(4) == 5);

        delete list;
    }

    SECTION("Sort list with duplicates") {
        auto list = new ArrayList<int>();
        list->Push(5);
        list->Push(2);
        list->Push(5);
        list->Push(1);
        list->Push(2);

        sorting::InsertionSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 1);
        REQUIRE(list->At(1) == 2);
        REQUIRE(list->At(2) == 2);
        REQUIRE(list->At(3) == 5);
        REQUIRE(list->At(4) == 5);

        delete list;
    }

    SECTION("Sort reverse sorted list") {
        auto list = new ArrayList<int>();
        list->Push(10);
        list->Push(9);
        list->Push(8);
        list->Push(7);
        list->Push(6);

        sorting::InsertionSort(list);

        REQUIRE(isSortedAscending(list));
        REQUIRE(list->At(0) == 6);
        REQUIRE(list->At(4) == 10);

        delete list;
    }
}

TEST_CASE("Compare BubbleSort and InsertionSort results",
          "[BubbleSort][InsertionSort]") {

    SECTION("Both algorithms produce same sorted result") {
        auto list1 = new ArrayList<int>();
        auto list2 = new ArrayList<int>();

        // Add same elements to both lists
        int elements[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 42};
        for (int elem : elements) {
            list1->Push(elem);
            list2->Push(elem);
        }

        sorting::BubbleSort(list1);
        sorting::InsertionSort(list2);

        // Both should be sorted
        REQUIRE(isSortedAscending(list1));
        REQUIRE(isSortedAscending(list2));

        // Both should have same elements in same order
        REQUIRE(list1->Length() == list2->Length());
        for (int i = 0; i < list1->Length(); i++) {
            REQUIRE(list1->At(i) == list2->At(i));
        }

        delete list1;
        delete list2;
    }
}
