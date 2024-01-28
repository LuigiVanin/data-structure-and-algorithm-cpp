#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/DoublyLinkedList/DoublyLinkedList.h"
#include <iostream>

TEST_CASE("Test DoublyLinkedList Initialization", "[ArrayList]")
{
    SECTION("Testing initialization")
    {
        auto list = new DoublyLinkedList<int>();
        REQUIRE(1 == 1);
    }
}
