#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/LinkedQueue/LinkedQueue.h"
#include <iostream>

TEST_CASE("Test LinkedQueue Initialization", "[LinkedQueue]")
{
    SECTION("Integer initialization values")
    {
        auto queue = new LinkedQueue<int>();
        REQUIRE(queue->Length() == 0);
        REQUIRE(queue->IsEmpty());
        delete queue;
    }

    SECTION("String initialization values")
    {
        auto queue = new LinkedQueue<std::string>();
        REQUIRE(queue->Length() == 0);
        REQUIRE(queue->IsEmpty());
        delete queue;
    }

    SECTION("Custom initialization values")
    {
        struct CustomStruct
        {
            int a;
            int b;
        };

        auto queue = new LinkedQueue<CustomStruct>();
        REQUIRE(queue->Length() == 0);
        REQUIRE(queue->IsEmpty());
        delete queue;
    }
}

TEST_CASE("Test LinkedQueue Add and Remove", "[LinkedQueue]")
{
    SECTION("Add multiple itens(25) and checking if the length is correct")
    {
        auto queue = new LinkedQueue<int>();
        for (int i = 0; i < 25; i++)
        {
            queue->Add(i);
        }
        REQUIRE(queue->Length() == 25);
        delete queue;
    }

    SECTION("Add multiple itens(25) and remove them all")
    {
        auto queue = new LinkedQueue<int>();
        for (int i = 0; i < 25; i++)
        {
            queue->Add(i);
        }
        for (int i = 0; i < 25; i++)
        {
            queue->Remove();
        }
        REQUIRE(queue->IsEmpty());
        delete queue;
    }

    SECTION("Add multiple itens(25) and remove them all, checking if the length is correct")
    {
        auto queue = new LinkedQueue<int>();
        for (int i = 0; i < 25; i++)
        {
            queue->Add(i);
        }
        for (int i = 0; i < 25; i++)
        {
            queue->Remove();
        }
        REQUIRE(queue->Length() == 0);
        delete queue;
    }

    SECTION("Add one and removing to see head value(Peek)")
    {
        auto queue = new LinkedQueue<int>();
        queue->Add(12);
        REQUIRE(queue->Peek() == 12);
        queue->Remove();
        REQUIRE(queue->IsEmpty());
        delete queue;
    }

    SECTION("Testing Peek with Add and Remove")
    {
        auto queue = new LinkedQueue<int>();
        queue->Add(12);
        queue->Add(1345);
        queue->Add(111);
        queue->Add(49);
        REQUIRE(queue->Peek() == 12);
        queue->Remove();
        REQUIRE(queue->Peek() == 1345);
        queue->Remove();
        REQUIRE(queue->Peek() == 111);
        queue->Remove();
        REQUIRE(queue->Peek() == 49);
        queue->Remove();
        REQUIRE(queue->IsEmpty());
        delete queue;
    }
}