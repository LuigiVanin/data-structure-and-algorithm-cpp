#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/ArrayStack/ArrayStack.h"
#include <iostream>

TEST_CASE("Test ArrayStack Initialization", "[ArrayStack]")
{
    struct CustomStruct
    {
        int a;
        int b;
    };

    auto stack_int = new ArrayStack<int>();
    auto stack_string = new ArrayStack<std::string>();
    auto stack_custom = new ArrayStack<CustomStruct>();

    SECTION("Integer initialization values")
    {
        REQUIRE(stack_int->Length() == 0);
        REQUIRE(stack_int->IsEmpty());
    }

    SECTION("String initialization values")
    {
        REQUIRE(stack_string->Length() == 0);
        REQUIRE(stack_string->IsEmpty());
    }

    SECTION("Custom initialization values")
    {
        REQUIRE(stack_custom->Length() == 0);
        REQUIRE(stack_custom->IsEmpty());
    }

    delete stack_int;
    delete stack_string;
    delete stack_custom;
}

TEST_CASE("Test ArrayStack Push and Pop", "[ArrayStack]")
{
    auto stack = new ArrayStack<int>();
    auto stack_string = new ArrayStack<std::string>();

    SECTION("Pushing and Popping integers")
    {
        stack->Push(11);
        REQUIRE(stack->Top() == 11);
        stack->Push(12);
        REQUIRE(stack->Top() == 12);
        stack->Pop();
        REQUIRE(stack->Top() == 11);
        stack->Pop();
        REQUIRE(stack->IsEmpty());
    }

    SECTION("Pushing and Popping strings")
    {
        stack_string->Push("TEST TEXT");
        REQUIRE(stack_string->Top() == "TEST TEXT");
        stack_string->Pop();
        REQUIRE(stack_string->IsEmpty());
    }

    SECTION("Pushing multiple values(25)")
    {
        auto local_stack = new ArrayStack<int>();

        for (int i = 0; i < 25; i++)
        {
            local_stack->Push(i);
        }
        REQUIRE(local_stack->Top() == 24);
        for (int i = 24; i >= 0; i--)
        {
            REQUIRE(local_stack->Top() == i);
            local_stack->Pop();
        }
        REQUIRE(stack->IsEmpty());
    }

    SECTION("Popping out out of bounds")
    {
        auto local_stack = new ArrayStack<int>();

        REQUIRE_THROWS(local_stack->Pop());
        REQUIRE_THROWS(local_stack->Pop());
        REQUIRE_THROWS(local_stack->Pop());
    }

    delete stack;
    delete stack_string;
}

TEST_CASE("Test conversion to array", "[ArrayStack]")
{
    auto stack = new ArrayStack<int>();

    for (int i = 0; i < 25; i++)
    {
        stack->Push(i);
    }

    auto arr = stack->toArray();
    for (int i = 24; i >= 0; i--)
    {
        REQUIRE(arr[i] == i);
    }
    delete stack;
    delete[] arr;
}
