#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/DoublyLinkedList/DoublyLinkedList.h"
#include <iostream>

TEST_CASE("Test DoublyLinkedList Initialization", "[DoublyLinkedList]")
{
    struct CustomStruct
    {
        int a;
        int b;
    };

    SECTION("Testing with other types")
    {
        auto list_int = new DoublyLinkedList<int>();
        auto list_string = new DoublyLinkedList<std::string>();
        auto list_custom_struct = new DoublyLinkedList<CustomStruct>();

        REQUIRE(list_int->Length() == 0);
        REQUIRE(list_string->Length() == 0);
        REQUIRE(list_custom_struct->Length() == 0);

        REQUIRE(list_int->getHead() == nullptr);
        REQUIRE(list_string->getHead() == nullptr);
        REQUIRE(list_custom_struct->getHead() == nullptr);

        REQUIRE(list_int->getTail() == nullptr);
        REQUIRE(list_string->getTail() == nullptr);
        REQUIRE(list_custom_struct->getTail() == nullptr);

        delete list_int;
        delete list_string;
        delete list_custom_struct;
    }
}

TEST_CASE("Testing DoublyLinkedList Push", "[DoublyLinkedList]")
{
    SECTION("Testing DoublyLinkedList Push")
    {
        auto list = new DoublyLinkedList<int>();
        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(i) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        delete list;
    }

    SECTION("Testing DoublyLinkedList Push with custom struct")
    {
        struct CustomStruct
        {
            int a;
            int b;
        };

        auto list = new DoublyLinkedList<CustomStruct>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push({.a = random, .b = random}));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(i).a == random);
            REQUIRE(list->At(i).b == random);
        }

        REQUIRE_FALSE(list->getHead()->value.a == list->getTail()->value.a);
        REQUIRE_FALSE(list->getHead()->value.b == list->getTail()->value.b);

        delete list;
    }

    SECTION("Testing Performing Push after Pop")
    {
        auto list = new DoublyLinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(i) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == 10 + i + 1);
            REQUIRE(list->At(10 + i) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        delete list;
    }
}

TEST_CASE("Testing LinkedList Pop")
{
    SECTION("Testing LinkedList Pop")
    {
        auto list = new DoublyLinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(i) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == 10 + i + 1);
            REQUIRE(list->At(10 + i) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        REQUIRE_NOTHROW(list->Pop());
        REQUIRE_NOTHROW(list->Pop());
        REQUIRE_NOTHROW(list->Pop());
        REQUIRE_NOTHROW(list->Pop());

        delete list;
    }

    SECTION("Testing DoublyLinkedList Pop out of bound")
    {
        auto list = new DoublyLinkedList<int>();
        REQUIRE_NOTHROW(list->Pop());

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(i) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        REQUIRE_NOTHROW(list->Pop());
    }
}

TEST_CASE("Testing LinkedList Shift")
{
    SECTION("Testing LinkedList Shift")
    {
        auto list = new DoublyLinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Shift(random));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(0) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Shift(random));
            REQUIRE(list->Length() == 10 + i + 1);
            REQUIRE(list->At(0) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        delete list;
    }

    SECTION("Testing LinkedList Shift with custom struct")
    {
        struct CustomStruct
        {
            int a;
            int b;
        };

        auto list = new DoublyLinkedList<CustomStruct>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Shift({.a = random, .b = random}));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(0).a == random);
            REQUIRE(list->At(0).b == random);
        }

        REQUIRE_FALSE(list->getHead()->value.a == list->getTail()->value.a);
        REQUIRE_FALSE(list->getHead()->value.b == list->getTail()->value.b);

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Shift({.a = random, .b = random}));
            REQUIRE(list->Length() == 10 + i + 1);
            REQUIRE(list->At(0).a == random);
            REQUIRE(list->At(0).b == random);
        }

        REQUIRE_FALSE(list->getHead()->value.a == list->getTail()->value.a);
        REQUIRE_FALSE(list->getHead()->value.b == list->getTail()->value.b);

        delete list;
    }

    SECTION("Testing Performing Shift after Pop")
    {
        auto list = new DoublyLinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Shift(random));
            REQUIRE(list->Length() == i + 1);
            REQUIRE(list->At(0) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Shift(random));
            REQUIRE(list->Length() == 10 + i + 1);
            REQUIRE(list->At(0) == random);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        delete list;
    }
}

TEST_CASE("Testing LinkedList Unshift")
{
    SECTION("Testing LinkedList Unshift")
    {
        auto list = new DoublyLinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;

            REQUIRE_NOTHROW(list->Push(random));
            REQUIRE(list->Length() == i + 1);
        }

        REQUIRE_FALSE(list->getHead()->value == list->getTail()->value);

        for (int i = 0; i < 10; i++)
        {
            REQUIRE_NOTHROW(list->Unshift());
            REQUIRE(list->Length() == 10 - i - 1);
        }
    }

    SECTION("Testing LinkedList Unshift with custom struct")
    {
        struct CustomStruct
        {
            int a;
            int b;
        };

        auto list = new DoublyLinkedList<CustomStruct>();
        for (int i = 0; i < 10; i++)
        {
            REQUIRE_NOTHROW(list->Push({.a = i, .b = i}));
            REQUIRE(list->Length() == i + 1);
        }

        REQUIRE_FALSE(list->getHead()->value.a == list->getTail()->value.a);
        REQUIRE_FALSE(list->getHead()->value.b == list->getTail()->value.b);

        for (int i = 0; i < 10; i++)
        {
            REQUIRE_NOTHROW(list->Unshift());
            REQUIRE(list->Length() == 10 - i - 1);
        }
    }
}
