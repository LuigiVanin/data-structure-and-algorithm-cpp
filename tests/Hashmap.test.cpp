#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/Hashmap/Hashmap.h"

TEST_CASE("Test Hashmap Initialization", "[Hashmap]")
{
    struct CustomStruct
    {
        int a;
        int b;
    };

    SECTION("Hashmap initialization values")
    {
        auto map = new Hashmap<std::string, int>();
        REQUIRE(map->GetLength() == 0);
        REQUIRE(map->GetBuckets() == 8);
    }

    SECTION("Testing with custom types")
    {
        auto map_string = new Hashmap<std::string, std::string>();
        auto map_custom_struct = new Hashmap<std::string, CustomStruct>();

        REQUIRE(map_string->GetLength() == 0);
        REQUIRE(map_custom_struct->GetLength() == 0);

        REQUIRE_NOTHROW(map_string->Put("key", "value"));
        REQUIRE_NOTHROW(map_custom_struct->Put("key", {.a = 1, .b = 2}));

        REQUIRE(map_string->GetLength() == 1);
        REQUIRE(map_custom_struct->GetLength() == 1);

        REQUIRE_NOTHROW(map_string->Put("another key", "another value"));
        REQUIRE_NOTHROW(map_custom_struct->Put("another key", {.a = 873, .b = 111}));

        // check length
        REQUIRE(map_string->GetLength() == 2);
        REQUIRE(map_custom_struct->GetLength() == 2);

        // Compare 'key' and 'another key' values
        REQUIRE_FALSE(map_string->Get("key").Unwrap() == map_string->Get("another key").Unwrap());
        REQUIRE_FALSE(map_custom_struct->Get("key").Unwrap().a == map_custom_struct->Get("another key").Unwrap().a);

        delete map_string;
        delete map_custom_struct;
    }
}

TEST_CASE("Testing Hashmap Put and Get", "[Hashmap]")
{
    SECTION("Testing Hashmap Put")
    {
        auto map = new Hashmap<int, int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(map->Put(i, random));
            REQUIRE(map->GetLength() == i + 1);

            REQUIRE(map->Get(i).Unwrap() == random);
        }

        delete map;
    }

    SECTION("Testing Hashmap Put with custom struct")
    {
        struct CustomStruct
        {
            int a;
            int b;
        };

        auto map = new Hashmap<int, CustomStruct>();
        for (int i = 0; i < 10; i++)
        {
            const CustomStruct random = {.a = rand() % 100, .b = rand() % 100};
            REQUIRE_NOTHROW(map->Put(i, random));
            REQUIRE(map->GetLength() == i + 1);

            REQUIRE(map->Get(i).Unwrap().a == random.a);
            REQUIRE(map->Get(i).Unwrap().b == random.b);
        }

        delete map;
    }

    SECTION("Tesing Put with resize of buckets, checking final bucket size")
    {

        auto map = new Hashmap<int, int>();
        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(map->Put(i, random));
        }

        REQUIRE(map->GetBuckets() == 16);

        for (int i = 0; i < 10; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(map->Put(i, random));
        }

        REQUIRE(map->GetBuckets() == 32);

        for (int i = 0; i < 100; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(map->Put(i, random));
        }

        REQUIRE(map->GetBuckets() == 256);

        delete map;
    }

    SECTION("Testing Put overwrite value")
    {
        auto map = new Hashmap<std::string, int>();

        REQUIRE_NOTHROW(map->Put("key", 1));

        auto value = map->Get("key").Unwrap();

        REQUIRE(value == 1);

        REQUIRE_NOTHROW(map->Put("key", 2));

        value = map->Get("key").Unwrap();

        REQUIRE(value == 2);

        map->Put("Outro teste", 12);
        map->Put("Outro teste", 31);
        map->Put("Outro teste", 31);
        map->Put("Outro teste", 31);
        map->Put("Outro teste", 31);
        map->Put("Outro teste", 31);
        map->Put("Outro teste", 31);
        map->Put("Outro teste", 31);

        REQUIRE(map->Get("Outro teste").Unwrap() == 31);

        map->Put("Outro teste", 55);

        REQUIRE(map->Get("Outro teste").Unwrap() == 55);

        delete map;
    }
}

TEST_CASE("Testing Clear method", "[Hashmap]")
{
    SECTION("Clear method should not throw error and have length 0")
    {
        auto map = new Hashmap<std::string, int>();
        map->Put("Teste", 2);
        map->Put("Mais um teste", 4);
        map->Put("Outro teste", 12);

        REQUIRE(map->GetLength() == 3);

        map->Clear();

        REQUIRE(map->GetLength() == 0);

        delete map;
    }

    SECTION("Clear method should not throw error and have all keys with None value")
    {
        auto map = new Hashmap<std::string, int>();
        map->Put("Teste", 2);
        map->Put("Mais um teste", 4);
        map->Put("Outro teste", 12);

        REQUIRE(map->GetLength() == 3);

        map->Clear();

        REQUIRE(map->GetLength() == 0);

        REQUIRE(map->Get("Teste").IsNone());
        REQUIRE(map->Get("Mais um teste").IsNone());
        REQUIRE(map->Get("Outro teste").IsNone());

        delete map;
    }

    SECTION("Clear method with multiple keys and values, should not throw error and have length 0")
    {
        auto map = new Hashmap<int, int>();

        for (int i = 0; i < 100; i++)
        {
            map->Put(i, i);
        }

        REQUIRE(map->GetLength() == 100);

        map->Clear();

        REQUIRE(map->GetLength() == 0);

        for (int i = 0; i < 100; i++)
        {
            REQUIRE(map->Get(i).IsNone());
        }
    }
}
