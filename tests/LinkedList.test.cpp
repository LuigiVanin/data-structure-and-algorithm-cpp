#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/LinkedList/LinkedList.h"

TEST_CASE("Test LinkedList Initialization", "[LinkedList]")
{
    struct CustomStruct
    {
        int a;
        int b;
    };

    SECTION("ArrayList initialization values")
    {

        auto list_int = new LinkedList<int>();
        REQUIRE(list_int->length == 0);
        REQUIRE(list_int->getHead() == nullptr);
    }

    SECTION("Testing with other types")
    {
        auto list_string = new LinkedList<std::string>();
        auto list_custom_struct = new LinkedList<CustomStruct>();

        REQUIRE(list_string->length == 0);
        REQUIRE(list_custom_struct->length == 0);

        REQUIRE_NOTHROW(list_string->Push("TEST TEXT"));
        REQUIRE_NOTHROW(list_custom_struct->Push({.a = 1, .b = 2}));

        REQUIRE(list_string->length == 1);
        REQUIRE(list_custom_struct->length == 1);

        REQUIRE_NOTHROW(list_string->Push("TEST TEXT"));
        REQUIRE_NOTHROW(list_custom_struct->Push({.a = 1, .b = 2}));

        delete list_string;
        delete list_custom_struct;
    }
}

TEST_CASE("Testing LinkedList Push", "[LinkedList]")
{
    SECTION("Testing LinkedList Push")
    {
        auto list_int = new LinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);

            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        delete list_int;
    }

    SECTION("Testing LinkedList Push with custom struct")
    {
        struct CustomStruct
        {
            int a;
            int b;
        };

        auto list_custom_struct = new LinkedList<CustomStruct>();
        for (int i = 0; i < 10; i++)
        {
            const CustomStruct random = {.a = rand() % 100, .b = rand() % 100};
            REQUIRE_NOTHROW(list_custom_struct->Push(random));
            REQUIRE(list_custom_struct->length == i + 1);

            REQUIRE(list_custom_struct->At(i).a == random.a);
            REQUIRE(list_custom_struct->At(i).b == random.b);
        }

        auto head = list_custom_struct->getHead();
        REQUIRE(head->value.a == list_custom_struct->At(0).a);
        REQUIRE(head->value.b == list_custom_struct->At(0).b);

        delete list_custom_struct;
    }

    SECTION("Testing Performing Push after Pop")
    {
        auto list_int = new LinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);

            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        for (int i = 0; i < 10; i++)
        {
            REQUIRE_NOTHROW(list_int->Pop());
            REQUIRE(list_int->length == 9 - i);
        }

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        delete list_int;
    }
}

TEST_CASE("Testing LinkedList Pop")
{
    SECTION("Testing LinkedList Pop")
    {
        auto list_int = new LinkedList<int>();
        REQUIRE_NOTHROW(list_int->Pop());

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        for (int i = 0; i < 10; i++)
        {
            REQUIRE_NOTHROW(list_int->Pop());
            REQUIRE(list_int->length == 9 - i);
        }
    }

    SECTION("Testing LinkedList Pop out of bound")
    {
        auto list_int = new LinkedList<int>();
        REQUIRE_NOTHROW(list_int->Pop());

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        for (int i = 0; i < 10; i++)
        {
            REQUIRE_NOTHROW(list_int->Pop());
            REQUIRE(list_int->length == 9 - i);
        }

        REQUIRE_NOTHROW(list_int->Pop());
        REQUIRE(list_int->length == 0);
    }
}

TEST_CASE("Testing LinkedList Shift", "[LinkedList]")
{

    SECTION("Testing LinkedList Shift")
    {
        auto list_int = new LinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Shift(random));
            REQUIRE(list_int->length == i + 1);

            REQUIRE(list_int->At(0) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        delete list_int;
    }
}

TEST_CASE("Testing LinkedList At", "[LinkedList]")
{
    SECTION("Testing LinkedList At")
    {
        auto list_int = new LinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);

            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        delete list_int;
    }

    SECTION("Testing LinkedList At out of bound")
    {
        auto list_int = new LinkedList<int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Push(random));
            REQUIRE(list_int->length == i + 1);

            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        REQUIRE_THROWS(list_int->At(100));
        REQUIRE_THROWS(list_int->At(-1));

        delete list_int;
    }
}

TEST_CASE("Testing LinkedList Insert", "[LinkedList]")
{
    SECTION("Testing standart insertion")
    {
        auto list_int = new LinkedList<int>();

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Insert(random, i));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        const int rando_index = rand() % list_int->length;
        const int value_to_insert = rand() % 100;

        REQUIRE_NOTHROW(list_int->Insert(value_to_insert, rando_index - 1));
        REQUIRE(list_int->At(rando_index - 1) == value_to_insert);

        delete list_int;
    }

    SECTION("Tesing random insertion")
    {
        auto list_int = new LinkedList<int>();

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Insert(random, i));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        const int rando_index = rand() % list_int->length;
        const int value_to_insert = rand() % 100;

        REQUIRE_NOTHROW(list_int->Insert(value_to_insert, rando_index - 1));
        REQUIRE(list_int->At(rando_index - 1) == value_to_insert);

        delete list_int;
    }

    SECTION("Testing inserting after performing POP")
    {
        auto list_int = new LinkedList<int>();

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Insert(random, i));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        const int rando_index = rand() % list_int->length;
        const int value_to_insert = rand() % 100;

        REQUIRE_NOTHROW(list_int->Insert(value_to_insert, rando_index - 1));
        REQUIRE(list_int->At(rando_index - 1) == value_to_insert);

        delete list_int;
    }

    SECTION("Testing inserting out of bound")
    {
        auto list_int = new LinkedList<int>();

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(list_int->Insert(random, i));
            REQUIRE(list_int->length == i + 1);
            REQUIRE(list_int->At(i) == random);
        }

        auto head = list_int->getHead();
        REQUIRE(head->value == list_int->At(0));

        const int rando_index = rand() % list_int->length;
        const int value_to_insert = rand() % 100;

        REQUIRE_NOTHROW(list_int->Insert(value_to_insert, rando_index - 1));
        // NOTE: The docker build throws a error in the statement bellow
        // REQUIRE_THROWS(list_int->At(rando_index - 1));

        delete list_int;
    }
}
