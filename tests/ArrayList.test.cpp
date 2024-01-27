#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/ArrayList/ArrayList.h"
#include <iostream>

TEST_CASE("Test ArrayList Initialization", "[ArrayList]")
{
    struct CustomStruct
    {
        int a;
        int b;
    };

    auto arr_int = new ArrayList<int>();
    auto arr_string = new ArrayList<std::string>();
    auto arr_custom = new ArrayList<int>(10);
    auto arr_custom_struct = new ArrayList<CustomStruct>();

    SECTION("Int initialization values")
    {

        REQUIRE(arr_int->length == 0);
        REQUIRE((arr_int->GetCapacity() == 8));
        REQUIRE_THROWS(arr_int->At(11));
    }

    SECTION("String initialization values")
    {

        REQUIRE(arr_string->length == 0);
        REQUIRE((arr_string->GetCapacity() == 8));
        REQUIRE_THROWS(arr_string->At(11));
    }

    SECTION("Custom initialization values")
    {

        REQUIRE(arr_custom->length == 0);
        REQUIRE((arr_custom->GetCapacity() == 10));
        REQUIRE_THROWS(arr_custom->At(11));
    }

    SECTION("Testing all methods that perform changes")
    {
        REQUIRE_NOTHROW(arr_int->Push(11));
        REQUIRE_NOTHROW(arr_int->Pop());
        REQUIRE_NOTHROW(arr_int->Insert(11, 0));
        REQUIRE_NOTHROW(arr_int->Remove(0));

        REQUIRE_NOTHROW(arr_string->Push("TEST TEXT"));
        REQUIRE_NOTHROW(arr_string->Pop());
        REQUIRE_NOTHROW(arr_string->Insert("TEST TEXT", 0));
        REQUIRE_NOTHROW(arr_string->Remove(0));

        REQUIRE_NOTHROW(arr_custom_struct->Push({.a = 1, .b = 2}));
        REQUIRE_NOTHROW(arr_custom_struct->Pop());
        REQUIRE_NOTHROW(arr_custom_struct->Insert({.a = 1, .b = 2}, 0));
        REQUIRE_NOTHROW(arr_custom_struct->Remove(0));
    }

    delete arr_int;
    delete arr_string;
    delete arr_custom;
    delete arr_custom_struct;
}

TEST_CASE("Test ArrayList Push", "[ArrayList]")
{

    SECTION("Int push values and length")
    {
        auto arr_int = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(arr_int->Push(random));
            REQUIRE(arr_int->At(i) == random);
            REQUIRE(arr_int->length == i + 1);
        }

        delete arr_int;
    }

    SECTION("Int push values testing capacity and resize function")
    {
        auto arr_int = new ArrayList<int>(4);

        REQUIRE(arr_int->GetCapacity() == 4);

        arr_int->Push(15);
        arr_int->Push(41);
        arr_int->Push(28);
        arr_int->Push(0);

        REQUIRE(arr_int->GetCapacity() == 4);

        arr_int->Push(1);

        REQUIRE(arr_int->GetCapacity() == 8);

        arr_int->Push(15);
        arr_int->Push(41);
        arr_int->Push(28);
        arr_int->Push(13);

        REQUIRE(arr_int->GetCapacity() == 16);
    }
}

TEST_CASE("Test ArrayList Pop", "[ArrayList]")
{
    SECTION("Int pop values and length")
    {
        auto arr_int = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            arr_int->Push(random);
        }

        for (int i = 19; i >= 0; i--)
        {
            auto prev_len = arr_int->length;
            REQUIRE_NOTHROW(arr_int->Pop());
            REQUIRE_FALSE(prev_len == arr_int->length);
            REQUIRE(arr_int->length == prev_len - 1);
        }

        delete arr_int;
    }

    SECTION("Int pop values testing capacity and resize function")
    {
        auto arr_int = new ArrayList<int>(4);

        REQUIRE(arr_int->GetCapacity() == 4);

        arr_int->Push(15);
        arr_int->Push(41);
        arr_int->Push(28);
        arr_int->Push(0);

        REQUIRE(arr_int->GetCapacity() == 4);

        arr_int->Pop();

        REQUIRE(arr_int->GetCapacity() == 4);
    }

    SECTION("Popping empty array")
    {
        auto list = new ArrayList<int>();
        REQUIRE_NOTHROW(list->Pop());
        list->Push(1);
        list->Push(45);

        REQUIRE(list->At(1) == 45);
        list->Pop();

        REQUIRE(list->At(0) == 1);

        list->Pop();

        REQUIRE_THROWS(list->At(0));

        delete list;
    }
}

TEST_CASE("Test ArrayList Insert", "[ArrayList]")
{
    SECTION("Int at values")
    {
        auto arr_int = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            arr_int->Push(random);
        }

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            arr_int->Insert(random, i);
            REQUIRE(arr_int->At(i) == random);
        }

        delete arr_int;
    }

    SECTION("Int insert values testing capacity and resize function")
    {
        auto arr_int = new ArrayList<int>(4);

        REQUIRE(arr_int->GetCapacity() == 4);

        arr_int->Push(15);
        arr_int->Push(41);
        arr_int->Push(28);
        arr_int->Push(0);

        REQUIRE(arr_int->GetCapacity() == 4);

        arr_int->Insert(1, 2);

        REQUIRE(arr_int->GetCapacity() == 8);

        arr_int->Insert(15, 2);
        arr_int->Insert(41, 2);
        arr_int->Insert(28, 2);
        arr_int->Insert(13, 2);

        REQUIRE(arr_int->GetCapacity() == 16);
    }

    SECTION("Testing inserting on the begining and end of arr")
    {
        auto list = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = i;
            list->Push(random);
        }

        list->Insert(2000, list->length);
        list->Insert(1000, 0);

        REQUIRE(list->At(list->length - 1) == 2000);

        list->Insert(3000, 0);
        REQUIRE(list->At(0) == 3000);

        delete list;
    }

    SECTION("Testing inserting out of bound")
    {
        auto list = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = i;
            list->Push(random);
        }

        REQUIRE_NOTHROW(list->Insert(2000, 100));
        REQUIRE_NOTHROW(list->Insert(2000, -1));

        delete list;
    }
}

TEST_CASE("Testing ArrayList Remove", "[ArrayList]")
{

    SECTION("Testing removing from the begining and end of arr")
    {
        auto list = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = i;
            list->Push(random);
        }

        list->Remove(list->length - 1);
        list->Remove(0);

        REQUIRE(list->At(list->length - 1) == 18);
        REQUIRE(list->At(0) == 1);

        delete list;
    }

    SECTION("Testing removing out of bound")
    {
        auto list = new ArrayList<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = i;
            list->Push(random);
        }

        REQUIRE_NOTHROW(list->Remove(100));
        REQUIRE_NOTHROW(list->Remove(-1));

        delete list;
    }

    SECTION("Testing removing from empty array")
    {
        auto list = new ArrayList<int>();

        REQUIRE_NOTHROW(list->Remove(0));

        delete list;
    }

    SECTION("Testing removing from array with one element")
    {
        auto list = new ArrayList<int>();

        list->Push(1);

        REQUIRE_NOTHROW(list->Remove(0));

        delete list;
    }
}