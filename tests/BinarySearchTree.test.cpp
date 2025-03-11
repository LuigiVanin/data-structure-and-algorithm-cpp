#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/BinarySearchTree/BinarySearchTree.h"
#include <vector>

TEST_CASE("Test BinarySearchTree Initialization", "[BinarySearchTree]")
{
    SECTION("Initialization with primitive types")
    {
        auto tree_int = new BinarySearchTree<int>();
        auto tree_char = new BinarySearchTree<char>();

        REQUIRE(tree_int->Amount() == 0);
        REQUIRE(tree_int->Depth() == 0);

        REQUIRE(tree_char->Amount() == 0);
        REQUIRE(tree_char->Depth() == 0);

        REQUIRE(tree_int->GetRoot() == nullptr);
        REQUIRE(tree_char->GetRoot() == nullptr);

        delete tree_int;
        delete tree_char;
    }
}

TEST_CASE("Testing BinarySearchTree Insert", "[BinarySearchTree]")
{
    SECTION("Simple Insert with integers")
    {
        auto bst = new BinarySearchTree<int>();
        int tempDepth = 0;

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(bst->Insert(random));
            REQUIRE(bst->Amount() == i + 1);
            REQUIRE(bst->Depth() >= tempDepth);
            tempDepth = bst->Depth();
        }
    }

    SECTION("Insert with characters")
    {
        auto bst = new BinarySearchTree<char>();

        REQUIRE_NOTHROW(bst->Insert('a'));
        REQUIRE_NOTHROW(bst->Insert('b'));
        REQUIRE_NOTHROW(bst->Insert('c'));
        REQUIRE_NOTHROW(bst->Insert('d'));

        REQUIRE_NOTHROW(bst->Insert('z'));
        REQUIRE_NOTHROW(bst->Insert('f'));
        REQUIRE_NOTHROW(bst->Insert('g'));
        REQUIRE_NOTHROW(bst->Insert('h'));

        REQUIRE(bst->Amount() == 8);
    }

    SECTION("Order of insertion")
    {
        auto bst = new BinarySearchTree<int>();

        REQUIRE_NOTHROW(bst->Insert(100));

        auto root = bst->GetRoot();

        REQUIRE(root->GetValue() == 100);

        bst->Insert(50);
        bst->Insert(120);

        REQUIRE(root->left != nullptr);
        REQUIRE(root->left->GetValue() == 50);

        REQUIRE(root->right != nullptr);
        REQUIRE(root->right->GetValue() == 120);

        bst->Insert(150);
        bst->Insert(110);

        REQUIRE(root->right->right != nullptr);
        REQUIRE(root->right->left != nullptr);
        REQUIRE(root->right->right->GetValue() == 150);
        REQUIRE(root->right->left->GetValue() == 110);

        bst->Insert(20);
        bst->Insert(80);

        REQUIRE(root->left->right != nullptr);
        REQUIRE(root->left->left != nullptr);
        REQUIRE(root->left->right->GetValue() == 80);
        REQUIRE(root->left->left->GetValue() == 20);
    }
}

TEST_CASE("Test BinarySearchTree Clear method")
{
    SECTION("Clear on an empty tree")
    {
        auto bst = new BinarySearchTree<int>();

        REQUIRE_NOTHROW(bst->Clear());

        REQUIRE(bst->Amount() == 0);
        REQUIRE(bst->Depth() == 0);
        REQUIRE(bst->GetRoot() == nullptr);

        REQUIRE_NOTHROW(bst->Clear());

        REQUIRE(bst->Amount() == 0);
        REQUIRE(bst->Depth() == 0);
        REQUIRE(bst->GetRoot() == nullptr);
    }

    SECTION("Clear on a filled tree")
    {
        auto bst = new BinarySearchTree<int>();
        int tempDepth = 0;

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            REQUIRE_NOTHROW(bst->Insert(random));
        }

        REQUIRE_NOTHROW(bst->Clear());
        REQUIRE_NOTHROW(bst->Clear());

        REQUIRE(bst->Amount() == 0);
        REQUIRE(bst->Depth() == 0);
        REQUIRE(bst->GetRoot() == nullptr);
    }
}

TEST_CASE("Test BinarySearchTree Search and HasValue Methods", "[BinarySearchTree]")
{
    SECTION("Search on an empty tree")
    {
        auto bst = new BinarySearchTree<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            REQUIRE(bst->Search(random) == nullptr);
            REQUIRE_FALSE(bst->HasValue(random));
        }
    }

    SECTION("Search for non-existent values")
    {
        auto bst = new BinarySearchTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            targetValues.push_back(random);
            bst->Insert(random);
        }

        for (int i = 0; i < 20; i++)
        {
            int random = (rand() % 100) + 100; // make random number out of bound of the target value
            REQUIRE(bst->Search(random) == nullptr);
            REQUIRE_FALSE(bst->HasValue(random));
        }
    }

    SECTION("Search for existing values")
    {
        auto bst = new BinarySearchTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            targetValues.push_back(random);
            bst->Insert(random);
        }

        for (const int &value : targetValues)
        {
            auto foundedValue = bst->Search(value);
            REQUIRE(foundedValue != nullptr);
            REQUIRE(foundedValue->GetValue() == value);
            REQUIRE(bst->HasValue(value));
        }

        for (int i = 0; i < 20; i++)
        {
            int random = (rand() % 100) + 100; // make random number out of bound of the target value
            REQUIRE(bst->Search(random) == nullptr);
            REQUIRE_FALSE(bst->HasValue(random));
        }
    }
}

TEST_CASE("Test Remove BinarySearchTree method", "[BinarySearchTree]")
{
    SECTION("Simple remove use case")
    {
        auto bst = new BinarySearchTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            targetValues.push_back(random);
            bst->Insert(random);
        }

        REQUIRE_NOTHROW(bst->Remove(targetValues.at(4)));
        REQUIRE(bst->Amount() == 19);
        REQUIRE(bst->Search(targetValues.at(4)) == nullptr);
        REQUIRE_FALSE(bst->HasValue(targetValues.at(4)));
    }

    SECTION("Remove all items from the tree")
    {
        auto bst = new BinarySearchTree<int>();
        std::vector<int> targetValues = {};

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            targetValues.push_back(random);
            bst->Insert(random);
        }

        for (int i = 19; i >= 0; i--)
        {
            bst->Remove(targetValues.at(i));
        }

        REQUIRE(bst->Amount() == 0);
        REQUIRE(bst->Depth() == 0);
        REQUIRE(bst->GetRoot() == nullptr);
    }

    SECTION("Remove non-existent value from filled tree")
    {
        auto bst = new BinarySearchTree<int>();

        for (int i = 0; i < 20; i++)
        {
            const int random = rand() % 100;
            bst->Insert(random);
        }

        int random = rand() % 100;

        REQUIRE_THROWS(bst->Remove(random + 100));
    }

    SECTION("Remove from an empty tree")
    {
        auto bst = new BinarySearchTree<int>();

        REQUIRE_THROWS(bst->Remove(19));
    }
}